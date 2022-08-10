%option c++ prefix="l22_scanner_" outfile="l22_scanner.cpp"
%option stack noyywrap yylineno 8bit debug
%{ 
// make relevant includes before including the parser's tab file
#include <string>
#include <vector>
#include <sstream>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include <cdk/ast/lvalue_node.h>
#include "l22_parser.tab.h"


static bool restart_functions = false;

static int lLevelsToPop = 0, lIndex = 0;
static std::vector<int> indents;   // known indentation levels
static std::vector<int> deferred;  // deferred tokens

// output stream for building string literals
static std::ostringstream strlit;


inline bool valid(int indent) {
    lLevelsToPop = lIndex = -1;
    bool indentOk = false;
    for (size_t ix = 0; ix < indents.size(); ix++) {
        if (indent == indents[ix]) {
            lLevelsToPop = indents.size() - ix - 1;
            lIndex = ix;
            indentOk = true;
        }
    }
    return indentOk;
}

// don't change this
#define yyerror LexerError
%}





%x  X_STRING X_COMMENT X_BAR X_NEWLINE


%%
  {
        //std::cerr << "################" << std::endl;
        set_debug(true);
        if (restart_functions) {
          std::cerr << "POPPING FUNCTIONS (" << indents.size() << ")" << std::endl;
          indents.pop_back();
          if (indents.size() == 0) restart_functions = false;
          return '}';
        }
        else {
          if (lLevelsToPop > 0) {
            std::cerr << "POPPING LEVELS (" << lLevelsToPop << ")" << std::endl;
            lLevelsToPop--;
            indents.pop_back();
            return '}';
          }
        }  
  }
  yydebug=1; set_debug(1);



  /* ====================================================================== */
  /* ====[                  1.1   - Tipos de dados                    ]==== */
  /* ====================================================================== */

"int"                  return tINT_TYPE;
"double"               return tREAL_TYPE;
"text"                 return tSTRING_TYPE;
"var"                  return tVAR;
"void"                 return tVOID;




 /* ====================================================================== */
  /* ====[                  3.1   - Linhas Logicas                   ]==== */
  /* ====================================================================== */

[ ]*"..."\n        ; /* ignore continuation marks */                 




  /* ====================================================================== */
  /* ====[                      3.3 - COMMENTS                        ]==== */
  /* ====================================================================== */

";".*$                ;
"(*"                   yy_push_state(X_COMMENT);
<X_COMMENT>"(*"        yy_push_state(X_COMMENT);
<X_COMMENT>"*)"        yy_pop_state();
<X_COMMENT>.|\n        ; /* ignore content */

  /* ====================================================================== */
  /* ====[                      Declarações                           ]==== */
  /* ====================================================================== */
  
"foreign"            return tFOREIGN;
"use"                return tUSE;
"public"             return tPUBLIC;


  /* ====================================================================== */
  /* ====[                      3.6- Operadores                       ]==== */
  /* ====================================================================== */
  
"and"                return '&';
"or"                 return '|';
"not"                return tNOT;
">="                 return tGE; 
"<="                 return tLE; 
"=="                 return tEQ; 
"!="                 return tNE;
[-()<>=+*/%;{}.?,@:] return *yytext;
"["                  return '[';
"]"                  return ']';
  

  /* ====================================================================== */
  /* ====[                     Intruções                              ]==== */
  /* ====================================================================== */
"if"                 return tIF; 
"else:"              return tELSE; 
"elif"               return tELIF; 
"do:"                return tDO;
"then:"              return tTHEN;
"while"              return tWHILE; 
"again"              return tAGAIN;
"stop"               return tSTOP;
"write"              return tWRITE;
"writeln"            return tWRITELN;          
"return"             return tRETURN;
"sizeof"             return tSIZEOF;
"with"               return tWITH;
"update"             return tUPDATE;
".."                 return tTO;
"iterate"            return tITERATE;
"count"               return tCOUNT;
  

  /* ====================================================================== */
  /* ====[                     Expressões                             ]==== */
  /* ====================================================================== */
"input"              return tINPUT;
"null"               return tNULLPTR;

  /* ====================================================================== */
  /* ====[                      Main                                  ]==== */
  /* ====================================================================== */
"begin"              return tBEGIN; 
"end"                return tEND; 


  /* ====================================================================== */
  /* ====[                2.6 - Identificadores                       ]==== */
  /* ====================================================================== */


[A-Za-z][A-Za-z0-9_]*  yylval.s = new std::string(yytext); return tID;



  /* ====================================================================== */
  /* ====[                           inteiros                         ]==== */
  /* ====================================================================== */

0[0-6]+              yylval.i = strtoul(yytext, NULL, 7); return tINTEGER;

[0-9]+               yylval.i = strtoul(yytext, nullptr, 10); return tINTEGER;


  /* ====================================================================== */
  /* ====[                           reais                            ]==== */
  /* ====================================================================== */

([0-9]*\.[0-9]+|[0-9]+\.[0-9])([Ee]([-+])?[0-9]+)? {yylval.d = strtod(yytext, NULL); return tREAL;}

  /* ====================================================================== */
  /* ====[               Cadeias de caracteres                        ]==== */
  /* ====================================================================== */

"\""                    yy_push_state(X_STRING);
<X_STRING>"\\"          yy_push_state(X_BAR);
<X_STRING>"\""         {
                         yylval.s = new std::string(strlit.str());
                         strlit.str("");
                         yy_pop_state();
                         return tSTRING;
                       }
<X_STRING>.            strlit << *yytext;

<X_BAR>n         strlit << '\n'; yy_pop_state();
<X_BAR>r         strlit << '\r'; yy_pop_state();
<X_BAR>t         strlit << '\t'; yy_pop_state();
<X_BAR>"\""      strlit << '"'; yy_pop_state();
<X_BAR>"\\"       strlit << '\\'; yy_pop_state();

<X_BAR>[0-6]{1,3} {
                                 strlit << (char)(unsigned char)strtoul(yytext, NULL, 7);
                                 yy_pop_state();
                               }
<X_BAR>.                 strlit << *yytext; yy_pop_state();



 /* ====================================================================== */
 /* ====[                      3.2 - INDENTATION                     ]==== */
 /* ====================================================================== */

\n                   yy_push_state(X_NEWLINE); /* delay decision */

<X_NEWLINE>^[ ]+  {
    yy_pop_state();

    if (valid(yyleng)) {
          std::cerr << "CASE 1" << std::endl;
          if (lLevelsToPop == 0) {
            // at the same level: ignore index
            // do not return tINDENT;
            std::cerr << "CASE 1a (levels to pop = 0)" << std::endl;
            return ';';
          }
          else {
            // nothing is done here: the scanner will ignore the input while levels > 0
            // and send block-end tokens to the parser
            std::cerr << "CASE 1b (levels to pop = " << lLevelsToPop << ")" << std::endl;
            // at least one has to be returned here...
            if (lLevelsToPop > 0) {
              std::cerr << "POPPING LEVELS (" << lLevelsToPop << ")" << std::endl;
              lLevelsToPop--;
              indents.pop_back();
              return '}';
            }
          }
    }
    else if (indents.size() == 0) {
          // first block to open
          std::cerr << "CASE 2" << std::endl;
          indents.push_back(yyleng);
          return '{';
    }
    else if (yyleng > indents.back()) {
          // this is like the one before, but not the first
          std::cerr << "CASE 3" << std::endl;
          indents.push_back(yyleng);
          return '{';
    }
    else {
          // something wrong: bad indent: communicate to user
          std::cerr << "CASE 4" << std::endl;
          std::cerr << "bad indent at line " << yylineno;
    }
}
<X_NEWLINE>\n      ; // ignore successive newline chars
<X_NEWLINE>.       {
  // in this case, we have a new function starting
  // first, return whatever we are seeing to the input
  yyless(0);
  yy_pop_state();
  if (indents.size() > 0) {
    std::cerr << "should restart " << indents.size() << " functions at " << yylineno << std::endl;
    indents.pop_back();
    if (indents.size() > 0) { restart_functions = true; }
    return '}';
  }
  else return ';'; // top-level declarations
}

  /* ====================================================================== */
  /* ====[                    (other characters)                      ]==== */
  /* ====================================================================== */

<<EOF>>                {
  std::cout << "AT <<EOF>> OPEN INDENTS ARE " << indents.size() << std::endl;
  if (indents.size() > 0) {
    indents.pop_back();
    return '}';
  }
  return 0;  // nothing left to do: tell parser to proceed
} 

[ ]+               ; /* ignore whitespace */

.                      yyerror("unknow Charectar");    /* all other chars: error! */


%%
