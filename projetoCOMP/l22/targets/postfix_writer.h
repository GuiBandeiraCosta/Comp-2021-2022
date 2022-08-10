#ifndef __L22_TARGETS_POSTFIX_WRITER_H__
#define __L22_TARGETS_POSTFIX_WRITER_H__

#include "targets/basic_ast_visitor.h"
#include <stack>
#include <sstream>
#include <set>
#include <cdk/emitters/basic_postfix_emitter.h>

namespace l22 {

  //!
  //! Traverse syntax tree and generate the corresponding assembly code.
  //!
  class postfix_writer: public basic_ast_visitor {
    cdk::symbol_table<l22::symbol> &_symtab;
    bool _errors, _inFunction, _inFunctionName, _inFunctionArgs, _inFunctionBody;
    std::set<std::string> _functions_to_declare;
    bool _returnSeen; // when building a function
    std::stack<int> _whileIni,_whileEnd; // for break/repeat
    std::shared_ptr<l22::symbol> _function; // for keeping track of the current function and its arguments
    int _offset; // current framepointer offset (0 means no vars defined)
    cdk::basic_postfix_emitter &_pf;
    cdk::typename_type _lvalueType;
    int _lbl;

    std::string _currentBodyRetLabel; // where to jump when a return occurs of an exclusive section ends


  public:
    postfix_writer(std::shared_ptr<cdk::compiler> compiler, cdk::symbol_table<l22::symbol> &symtab, cdk::basic_postfix_emitter &pf) :
        basic_ast_visitor(compiler), _symtab(symtab), _errors(false), _inFunction(false), _inFunctionName(false), _inFunctionArgs(
            false), _inFunctionBody(false),_returnSeen(false), _offset(0), _pf(pf), _lbl(0) {
    }
  public:
    ~postfix_writer() {
      os().flush();
    }

  private:
    /** Method used to generate sequential labels. */
    inline std::string mklbl(int lbl) {
      std::ostringstream oss;
      if (lbl < 0)
        oss << ".L" << -lbl;
      else
        oss << "_L" << lbl;
      return oss.str();
    }


  public:
  // do not edit these lines
#define __IN_VISITOR_HEADER__
#include ".auto/visitor_decls.h"       // automatically generated
#undef __IN_VISITOR_HEADER__
  // do not edit these lines: end

  };

} // l22

#endif