%{
//-- don't change *any* of these: if you do, you'll break the compiler.
#include <algorithm>
#include <memory>
#include <cstring>
#include <cdk/compiler.h>
#include <cdk/types/types.h>
#include ".auto/all_nodes.h"
#define LINE                         compiler->scanner()->lineno()
#define yylex()                      compiler->scanner()->scan()
#define yyerror(compiler, s)         compiler->scanner()->error(s)
//-- don't change *any* of these --- END!
%}

%parse-param {std::shared_ptr<cdk::compiler> compiler}

%union {
  //--- don't change *any* of these: if you do, you'll break the compiler.
  YYSTYPE() : type(cdk::primitive_type::create(0, cdk::TYPE_VOID)) {}
  ~YYSTYPE() {}
  YYSTYPE(const YYSTYPE &other) { *this = other; }
  YYSTYPE& operator=(const YYSTYPE &other) { type = other.type; return *this; }

  std::shared_ptr<cdk::basic_type> type;        /* expression type */
  //-- don't change *any* of these --- END!

  int                   i;	/* integer value */
  double                d;    /* Real Value*/
  std::string          *s;	/* symbol name or string literal */
  cdk::basic_node      *node;	/* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  cdk::lvalue_node     *lvalue;
  l22::block_node      *block;
  std::vector<std::shared_ptr<cdk::basic_type>> *type_vector;
  
};

%token <i> tINTEGER 
%token <d> tREAL
%token <s> tID tSTRING
%token tPUBLIC tUSE tFOREIGN  tWRITE tWRITELN tPRIVATE tWITH tUPDATE tTO tITERATE tCOUNT
%token tWHILE  tPRINT tREAD tBEGIN tEND tNOT
%token  tDO  tAGAIN tSTOP tRETURN tNULLPTR tINPUT tSIZEOF
%token tSTRING_TYPE tINT_TYPE tREAL_TYPE tVOID tVAR


%nonassoc tUNARY
%nonassoc tIF
%nonassoc tTHEN
%nonassoc tELIF tELSE
%nonassoc tNOT
%nonassoc  '(' 

%right '='
%left '&' '|' 
%left tGE tLE tEQ tNE '>' '<'
%left '+' '-'
%left '*' '/' '%'


%type <node>  program vardecl variable   instruction elif
%type <sequence> file declarations  exprs opt_exprs   instructions variables
%type <expression> expr integer real opt_initializer
%type <lvalue> lval
%type<block> block
%type<type> data_type 
%type<type_vector> function_type
%type<s> string

%{
//-- The rules below will be included in yyparse, the main parsing function.
%}
%%

file         : /* empty */          { compiler->ast($$ = new cdk::sequence_node(LINE)); }
             | declarations         { compiler->ast($1); }
             | program              { compiler->ast($1); }
             | declarations program { compiler->ast(new cdk::sequence_node(LINE,$2,$1));} 
             ;

program	: tBEGIN block tEND { $$ = new l22::program_node(LINE, $2); }
	      ;

declarations : vardecl ';'                 { $$ = new cdk::sequence_node(LINE, $1);     }
             | vardecl                     { $$ = new cdk::sequence_node(LINE, $1);     }
             | declarations vardecl        { $$ = new cdk::sequence_node(LINE, $2, $1); }
             | declarations vardecl ';'    { $$ = new cdk::sequence_node(LINE, $2, $1); }
             ;







opt_initializer  : /* empty */         { $$ = nullptr; /* must be nullptr, not NIL */ }
                 | '=' expr            { $$ = $2; }
                 ;

vardecl  : tPUBLIC tID '=' expr                             { $$ = new l22::variable_declaration_node(LINE, tPUBLIC,  cdk::primitive_type::create(4, cdk::TYPE_UNSPEC), *$2, $4); delete $2; }
          |tPUBLIC  data_type  tID         opt_initializer  { $$ = new l22::variable_declaration_node(LINE, tPUBLIC,  $2, *$3, $4); delete $3;}
          | tPUBLIC  tVAR  tID             '=' expr         { $$ = new l22::variable_declaration_node(LINE, tPUBLIC,  cdk::primitive_type::create(4, cdk::TYPE_UNSPEC), *$3, $5); delete $3; }
          |tUSE  data_type  tID                             { $$ = new l22::variable_declaration_node(LINE, tUSE,  $2, *$3,nullptr); delete $3;} 
          |tFOREIGN  data_type  tID                         { $$ = new l22::variable_declaration_node(LINE, tFOREIGN,  $2, *$3,nullptr);delete $3; }
          |          tVAR       tID        '=' expr         { $$ =  new l22::variable_declaration_node(LINE, tPRIVATE, cdk::primitive_type::create(4, cdk::TYPE_UNSPEC), *$2, $4); delete $2;} 
          |          data_type  tID        opt_initializer  { $$ = new l22::variable_declaration_node(LINE, tPRIVATE, $1, *$2, $3);delete $2; }
          ;




variable : tVAR  tID          { $$ =  new l22::variable_declaration_node(LINE, tPRIVATE, cdk::primitive_type::create(4, cdk::TYPE_UNSPEC), *$2, nullptr);delete $2;}
         | data_type  tID     { $$ = new l22::variable_declaration_node(LINE, tPRIVATE, $1, *$2, nullptr); delete $2; }
         ;

variables : variable               { $$ = new cdk::sequence_node(LINE, $1);}
         | variables ',' variable  { $$ = new cdk::sequence_node(LINE, $3, $1); }
         ;
    




block    : '{' declarations instructions '}'   { $$ = new l22::block_node(LINE, $2, $3); }
         | '{' instructions '}'               { $$ = new l22::block_node(LINE, nullptr, $2); } 
         | '{' declarations '}'               { $$ = new l22::block_node(LINE, $2, nullptr); }
         ;
         

elif : tELSE block                               { $$ = $2; }
     | tELIF '(' expr ')' tTHEN block            { $$ = new l22::if_node(LINE, $3, $6); }
     | tELIF '(' expr ')' tTHEN block elif       { $$ = new l22::if_else_node(LINE, $3, $6,$7); }
     ;

instructions : instruction               { $$ = new cdk::sequence_node(LINE, $1);     }
             | instruction     ';'          { $$ = new cdk::sequence_node(LINE, $1);     }
             | instructions instruction     { $$ = new cdk::sequence_node(LINE, $2, $1);}
             | instructions instruction  ';'   { $$ = new cdk::sequence_node(LINE, $2, $1);}
             ;
             


instruction     : expr                                 { $$ = new l22::evaluation_node(LINE, $1); } 
                | tWRITE exprs                         { $$ = new l22::print_node(LINE, $2, false); }
                | tWRITELN  exprs                      { $$ = new l22::print_node(LINE, $2, true); }
                | tAGAIN                               { $$ = new l22::again_node(LINE); }
                | tSTOP                                { $$ = new l22::stop_node(LINE);  }
                | tRETURN                              { $$ = new l22::return_node(LINE, nullptr); }
                | tRETURN expr                         { $$ = new l22::return_node(LINE, $2);}
                | tIF '(' expr ')' tTHEN block         { $$ = new l22::if_node(LINE, $3, $6); } 
                | tIF '(' expr ')' tTHEN block elif     { $$ = new l22::if_else_node(LINE, $3, $6,$7); }
                | tWHILE '(' expr ')' tDO block         { $$ = new l22::while_node(LINE, $3, $6); }
                | block                                 { $$ = $1;}
                |tWITH expr tUPDATE expr ":" expr tTO expr { $$ = new l22::with_vector_update_node(LINE, $2, $4, $6, $8); }
                |tITERATE expr tCOUNT expr tWITH expr tIF expr {$$ = new l22::iterate_node(LINE, $2, $4, $6, $8);}
                ;


lval : tID                { $$ = new cdk::variable_node(LINE, $1); }
     | lval '[' expr ']'  { $$ = new l22::index_node(LINE, new cdk::rvalue_node(LINE, $1), $3); }
     ;

expr : integer                       { $$ = $1; }
     | real                          { $$ = $1; }
     | string                        { $$ = new cdk::string_node(LINE, $1); }
     | tNULLPTR                      { $$ = new l22::nullptr_node(LINE); }

     /* ARITHMETIC,Logical EXPRESSIONS */
     | '-' expr %prec tUNARY      { $$ = new cdk::neg_node(LINE, $2); }
     | '+' expr %prec tUNARY      { $$ = new l22::identity_node(LINE,$2); }
     | expr '+' expr	         { $$ = new cdk::add_node(LINE, $1, $3); }
     | expr '-' expr	         { $$ = new cdk::sub_node(LINE, $1, $3); }
     | expr '*' expr	         { $$ = new cdk::mul_node(LINE, $1, $3); }
     | expr '/' expr	         { $$ = new cdk::div_node(LINE, $1, $3); }
     | expr '%' expr	         { $$ = new cdk::mod_node(LINE, $1, $3); }
     | expr '<' expr	         { $$ = new cdk::lt_node(LINE, $1, $3); }
     | expr '>' expr	         { $$ = new cdk::gt_node(LINE, $1, $3); }
     | tNOT  expr                 { $$ = new cdk::not_node(LINE, $2);     }
     | expr tGE expr	         { $$ = new cdk::ge_node(LINE, $1, $3); }
     | expr tLE expr              { $$ = new cdk::le_node(LINE, $1, $3); }
     | expr tNE expr	         { $$ = new cdk::ne_node(LINE, $1, $3); }
     | expr tEQ expr	         { $$ = new cdk::eq_node(LINE, $1, $3); }
     | expr '&' expr              { $$ = new cdk::and_node(LINE, $1, $3); }
     | expr '|' expr              { $$ = new cdk::or_node (LINE, $1, $3); }
     | '(' expr ')'               { $$ = $2; }
     
     /* OTHER EXPRESSION */
     | tINPUT                        { $$ = new l22::read_node(LINE); }
     | expr '(' opt_exprs ')'         { $$ = new l22::function_call_node(LINE, $1, $3);}
     |'@' '(' opt_exprs ')'           { $$ = new l22::function_call_node(LINE, nullptr, $3);}
     |'[' expr ']'             { $$ = new l22::stack_alloc_node(LINE, $2); }
     | tSIZEOF '(' expr ')'   { $$ = new l22::sizeof_node(LINE,$3); }
     /*Lvalues*/
     | lval                    { $$ = new cdk::rvalue_node(LINE, $1); }  
     | lval '=' expr           { $$ = new cdk::assignment_node(LINE, $1, $3); }
     | lval '?'                { $$ = new l22::address_of_node(LINE, $1); }

     /*FUNCTION*/
     |'(' variables ')' '-' '>' data_type ':' block    { $$ = new l22::function_definition_node(LINE,$6,$2,$8); }
     |'('               ')' '-' '>' data_type ':' block    { $$ = new l22::function_definition_node(LINE,$5,nullptr,$7); }

     ;


exprs     : expr                   { $$ = new cdk::sequence_node(LINE, $1);}
          | exprs ',' expr         { $$ = new cdk::sequence_node(LINE, $3, $1); }
          ;

opt_exprs : /* empty */         { $$ = new cdk::sequence_node(LINE); }
          | exprs               { $$ = $1; }
          ;



function_type: data_type                                 { $$ = new std::vector<std::shared_ptr<cdk::basic_type>>(); $$->push_back($1);}
	        | function_type ',' data_type               { $$ = $1; $$->push_back($3); }
             ;

data_type    : tSTRING_TYPE                     { $$ = cdk::primitive_type::create(4, cdk::TYPE_STRING);  }
             | tINT_TYPE                        { $$ = cdk::primitive_type::create(4, cdk::TYPE_INT );     }
             | tREAL_TYPE                       { $$ = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE);  }
             | tVOID                            { $$ = cdk::primitive_type::create(4, cdk::TYPE_VOID);  }
             | '[' data_type ']'                { $$ = cdk::reference_type::create(4, $2); }
             | data_type '<' '>'                { std::vector<std::shared_ptr<cdk::basic_type>> ola; ola.push_back($1); $$ =  cdk::functional_type::create(ola); }
             | data_type '<'function_type'>'    { std::vector<std::shared_ptr<cdk::basic_type>> ola; ola.push_back($1); $$ =  cdk::functional_type::create(ola,*$3); delete $3; }
             ;


integer         : tINTEGER                      { $$ = new cdk::integer_node(LINE, $1); };
real            : tREAL                         { $$ = new cdk::double_node(LINE, $1); };
string          : tSTRING                       { $$ = $1; }
                | string tSTRING                { $$ = $1; $$->append(*$2); delete $2; }
                ;

%%
