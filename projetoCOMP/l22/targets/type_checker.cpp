#include <string>
#include "targets/type_checker.h"
#include ".auto/all_nodes.h"  // automatically generated
#include <cdk/types/primitive_type.h>

#define ASSERT_UNSPEC { if (node->type() != nullptr && !node->is_typed(cdk::TYPE_UNSPEC)) return; }

//---------------------------------------------------------------------------

void l22::type_checker::do_sequence_node(cdk::sequence_node *const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++)
    node->node(i)->accept(this, lvl);
}

//---------------------------------------------------------------------------

void l22::type_checker::do_nil_node(cdk::nil_node *const node, int lvl) {
  // EMPTY
}
void l22::type_checker::do_data_node(cdk::data_node *const node, int lvl) {
  // EMPTY
}
void l22::type_checker::do_double_node(cdk::double_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
}


//---------------------------------------------------------------------------

void l22::type_checker::do_integer_node(cdk::integer_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void l22::type_checker::do_string_node(cdk::string_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
}

//---------------------------------------------------------------------------



void l22::type_checker::do_neg_node(cdk::neg_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl);
  if (node->argument()->is_typed(cdk::TYPE_INT)) {
    node->type(node->argument()->type());
  } else {
    throw std::string("integer or vector expressions expected");
  }
}

//---------------------------------------------------------------------------
//protected:
void l22::type_checker::do_IntOnlyExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (!node->left()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary operator (left)");
  }

  node->right()->accept(this, lvl + 2);
  if (!node->right()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary operator (right)");
  }

  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

//---------------------------------------------------------------------------
//protected:
void l22::type_checker::do_IDExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);

  if (node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_DOUBLE)) {
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  } else if (node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_INT)) {
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  } else if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_DOUBLE)) {
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  } else if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_INT)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else if (node->left()->is_typed(cdk::TYPE_UNSPEC) && node->right()->is_typed(cdk::TYPE_UNSPEC)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->left()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->right()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else {
    throw std::string("wrong types in binary expression");
  }
}

//---------------------------------------------------------------------------
//protected:
void l22::type_checker::do_PIDExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);

  if (node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_DOUBLE)) {
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  } else if (node->left()->is_typed(cdk::TYPE_DOUBLE) && node->right()->is_typed(cdk::TYPE_INT)) {
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  } else if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_DOUBLE)) {
    node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  } else if (node->left()->is_typed(cdk::TYPE_POINTER) && node->right()->is_typed(cdk::TYPE_INT)) {
    node->type(node->left()->type());
  } else if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_POINTER)) {
    node->type(node->right()->type());
  } else if (node->left()->is_typed(cdk::TYPE_INT) && node->right()->is_typed(cdk::TYPE_INT)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else if (node->left()->is_typed(cdk::TYPE_UNSPEC) && node->right()->is_typed(cdk::TYPE_UNSPEC)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->left()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->right()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else {
    throw std::string("wrong types in binary expression");
  }
}

//---------------------------------------------------------------------------
//protected:
void l22::type_checker::do_ScalarLogicalExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (!node->left()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary logical expression (left)");
  }

  node->right()->accept(this, lvl + 2);
  if (!node->right()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary logical expression (right)");
  }

  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

//protected:
void l22::type_checker::do_BooleanLogicalExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (!node->left()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary expression");
  }

  node->right()->accept(this, lvl + 2);
  if (!node->right()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in binary expression");
  }

  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

//protected:
void l22::type_checker::do_GeneralLogicalExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  if (node->left()->type() != node->right()->type()) {
    throw std::string("same type expected on both sides of equality operator");
  }
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

//---------------------------------------------------------------------------


void l22::type_checker::do_add_node(cdk::add_node *const node, int lvl) {
  do_PIDExpression(node, lvl);
}
void l22::type_checker::do_sub_node(cdk::sub_node *const node, int lvl) {
  do_PIDExpression(node, lvl);
}
void l22::type_checker::do_mul_node(cdk::mul_node *const node, int lvl) {
  do_IDExpression(node, lvl);
}
void l22::type_checker::do_div_node(cdk::div_node *const node, int lvl) {
  do_IDExpression(node, lvl);
}
void l22::type_checker::do_mod_node(cdk::mod_node *const node, int lvl) {
  do_IntOnlyExpression(node, lvl);
}
void l22::type_checker::do_lt_node(cdk::lt_node *const node, int lvl) {
   do_ScalarLogicalExpression(node, lvl);
}
void l22::type_checker::do_le_node(cdk::le_node *const node, int lvl) {
   do_ScalarLogicalExpression(node, lvl);
}
void l22::type_checker::do_ge_node(cdk::ge_node *const node, int lvl) {
   do_ScalarLogicalExpression(node, lvl);
}
void l22::type_checker::do_gt_node(cdk::gt_node *const node, int lvl) {
   do_ScalarLogicalExpression(node, lvl);
}
void l22::type_checker::do_ne_node(cdk::ne_node *const node, int lvl) {
   do_GeneralLogicalExpression(node, lvl);
}
void l22::type_checker::do_eq_node(cdk::eq_node *const node, int lvl) {
   do_GeneralLogicalExpression(node, lvl);
}

void l22::type_checker::do_and_node(cdk::and_node *const node, int lvl) {
  do_BooleanLogicalExpression(node, lvl);
}
void l22::type_checker::do_or_node(cdk::or_node *const node, int lvl) {
  do_BooleanLogicalExpression(node, lvl);
}


void l22::type_checker::do_not_node(cdk::not_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  if (node->argument()->is_typed(cdk::TYPE_INT))
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  else if (node->argument()->is_typed(cdk::TYPE_UNSPEC)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->argument()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else
    throw std::string("wrong type in unary logical expression");
}
//---------------------------------------------------------------------------

void l22::type_checker::do_variable_node(cdk::variable_node *const node, int lvl) {
  ASSERT_UNSPEC;
  const std::string &id = node->name();
  std::shared_ptr<l22::symbol> symbol = _symtab.find(id);

  if (symbol != nullptr) {
    node->type(symbol->type());
  } else {
    throw id;
  }
}

void l22::type_checker::do_rvalue_node(cdk::rvalue_node *const node, int lvl) {
  ASSERT_UNSPEC;
  try {
    node->lvalue()->accept(this, lvl);
    node->type(node->lvalue()->type());
  } catch (const std::string &id) {
    throw "undeclared variable '" + id + "'";
  }
}

void l22::type_checker::do_assignment_node(cdk::assignment_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->lvalue()->accept(this, lvl + 4);
  node->rvalue()->accept(this, lvl + 4);

  if (node->lvalue()->is_typed(cdk::TYPE_INT)) {
    if (node->rvalue()->is_typed(cdk::TYPE_INT)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
      node->rvalue()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    } else {
      throw std::string("wrong assignment to integer");
    }
  } else if (node->lvalue()->is_typed(cdk::TYPE_POINTER)) {

    //TODO: check pointer level

    if (node->rvalue()->is_typed(cdk::TYPE_POINTER)) {
      node->type(node->rvalue()->type());
    } else if (node->rvalue()->is_typed(cdk::TYPE_INT)) {
      //TODO: check that the integer is a literal and that it is zero
      node->type(cdk::primitive_type::create(4, cdk::TYPE_POINTER));
    } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_ERROR));
      node->rvalue()->type(cdk::primitive_type::create(4, cdk::TYPE_ERROR));
    } else {
      throw std::string("wrong assignment to pointer");
    }

  } else if (node->lvalue()->is_typed(cdk::TYPE_DOUBLE)) {

    if (node->rvalue()->is_typed(cdk::TYPE_DOUBLE) || node->rvalue()->is_typed(cdk::TYPE_INT)) {
      node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
    } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
      node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
      node->rvalue()->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
    } else {
      throw std::string("wrong assignment to real");
    }

  } else if (node->lvalue()->is_typed(cdk::TYPE_STRING)) {

    if (node->rvalue()->is_typed(cdk::TYPE_STRING)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
    } else if (node->rvalue()->is_typed(cdk::TYPE_UNSPEC)) {
      node->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
      node->rvalue()->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
    } else {
      throw std::string("wrong assignment to string");
    }

  } else {
    throw std::string("wrong types in assignment");
  }
}

//---------------------------------------------------------------------------

void l22::type_checker::do_program_node(l22::program_node *const node, int lvl) {
  // EMPTY
}

void l22::type_checker::do_evaluation_node(l22::evaluation_node *const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
}

void l22::type_checker::do_print_node(l22::print_node *const node, int lvl) {
  node->arguments()->accept(this, lvl + 2);
}

//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void l22::type_checker::do_while_node(l22::while_node *const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
  node->block()->accept(this, lvl + 4);
}

//---------------------------------------------------------------------------

void l22::type_checker::do_if_node(l22::if_node *const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
  if (!node->condition()->is_typed(cdk::TYPE_INT)) throw std::string("expected integer condition");
}

void l22::type_checker::do_if_else_node(l22::if_else_node *const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
  if (!node->condition()->is_typed(cdk::TYPE_INT)) throw std::string("expected integer condition");
}

void l22::type_checker::do_nullptr_node(l22::nullptr_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::reference_type::create(4, nullptr));
}

void l22::type_checker::do_address_of_node(l22::address_of_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  node->type(cdk::reference_type::create(4, node->argument()->type()));
}

void l22::type_checker::do_again_node(l22::again_node *const node, int lvl) {
  //EMPTY
}

void l22::type_checker::do_block_node(l22::block_node *const node, int lvl) {
  //EMPTY
}

void l22::type_checker::do_function_call_node(l22::function_call_node *const node, int lvl) {
  /*ASSERT_UNSPEC;

  const std::string &id = node->identifier();
  auto symbol = _symtab.find(id);
  if (symbol == nullptr) throw std::string("symbol '" + id + "' is undeclared.");
  if (!symbol->isFunction()) throw std::string("symbol '" + id + "' is not a function.");

  if (symbol->is_typed(cdk::TYPE_STRUCT)) {
    // declare return variable for passing to function call
    const std::string return_var_name = "$return_" + id;
    auto return_symbol = l22::make_symbol(false, symbol->qualifier(), symbol->type(), return_var_name, false, false);
    if (_symtab.insert(return_var_name, return_symbol)) {
    } else {
      // if already declared, ignore new insertion
    }
  }

  node->type(symbol->type());

  if (node->arguments()->size() == symbol->number_of_arguments()) {
    node->arguments()->accept(this, lvl + 4);
    for (size_t ax = 0; ax < node->arguments()->size(); ax++) {
      if (node->argument(ax)->type() == symbol->argument_type(ax)) continue;
      if (symbol->argument_is_typed(ax, cdk::TYPE_DOUBLE) && node->argument(ax)->is_typed(cdk::TYPE_INT)) continue;
      throw std::string("type mismatch for argument " + std::to_string(ax + 1) + " of '" + id + "'.");
    }
  } else {
    throw std::string(
        "number of arguments in call (" + std::to_string(node->arguments()->size()) + ") must match declaration ("
            + std::to_string(symbol->number_of_arguments()) + ").");
  }*/
}



void l22::type_checker::do_function_definition_node(l22::function_definition_node *const node, int lvl) {
  //EMPTY
}


void l22::type_checker::do_index_node(l22::index_node *const node, int lvl) {
  ASSERT_UNSPEC;
  std::shared_ptr < cdk::reference_type > btype;

  if (node->base()) {
    node->base()->accept(this, lvl + 2);
    btype = cdk::reference_type::cast(node->base()->type());
    if (!node->base()->is_typed(cdk::TYPE_POINTER)) throw std::string("pointer expression expected in index left-value");
  } else {
    btype = cdk::reference_type::cast(_function->type());
    if (!_function->is_typed(cdk::TYPE_POINTER)) throw std::string("return pointer expression expected in index left-value");
  }

  node->index()->accept(this, lvl + 2);
  if (!node->index()->is_typed(cdk::TYPE_INT)) throw std::string("integer expression expected in left-value index");

  node->type(btype->referenced());
}

void l22::type_checker::do_read_node(l22::read_node *const node, int lvl) {
  //EMPTY
}

void l22::type_checker::do_stack_alloc_node(l22::stack_alloc_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  if (!node->argument()->is_typed(cdk::TYPE_INT)) {
    throw std::string("integer expression expected in allocation expression");
  }
  //DAVID TODO FIXME
  auto mytype = cdk::reference_type::create(4, cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
  node->type(mytype);
}

void l22::type_checker::do_return_node(l22::return_node *const node, int lvl) {
  //EMPTY
}

void l22::type_checker::do_sizeof_node(l22::sizeof_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void l22::type_checker::do_stop_node(l22::stop_node *const node, int lvl) {
  //EMPTY
}

void l22::type_checker::do_variable_declaration_node(l22::variable_declaration_node *const node, int lvl) {
  if (node->initializer() != nullptr) {
    node->initializer()->accept(this, lvl + 2);

    if (node->is_typed(cdk::TYPE_INT)) {
      if (!node->initializer()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type for initializer (integer expected).");
    } else if (node->is_typed(cdk::TYPE_DOUBLE)) {
      if (!node->initializer()->is_typed(cdk::TYPE_INT) && !node->initializer()->is_typed(cdk::TYPE_DOUBLE)) {
        throw std::string("wrong type for initializer (integer or double expected).");
      }
    } else if (node->is_typed(cdk::TYPE_STRING)) {
      if (!node->initializer()->is_typed(cdk::TYPE_STRING)) {
        throw std::string("wrong type for initializer (string expected).");
      }
    } else if (node->is_typed(cdk::TYPE_POINTER)) {
      if (!node->initializer()->is_typed(cdk::TYPE_POINTER)) {
        auto in = (cdk::literal_node<int>*)node->initializer();
        if (in == nullptr || in->value() != 0) throw std::string("wrong type for initializer (pointer expected).");
      }
    }
     else if (node->is_typed(cdk::TYPE_UNSPEC)) {
        if (node->initializer()->is_typed(cdk::TYPE_INT)){
          node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
        }
        else if (node->initializer()->is_typed(cdk::TYPE_DOUBLE)){
          node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
        }
        else if (node->initializer()->is_typed(cdk::TYPE_STRING)){
          node->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
        }
        else if (node->initializer()->is_typed(cdk::TYPE_POINTER)){
          node->type(cdk::primitive_type::create(4, cdk::TYPE_POINTER));
        }
    }  
    else {
      throw std::string("unknown type for initializer.");
    }
  }
  const std::string &id = node->identifier();
  auto symbol = l22::make_symbol(false, node->qualifier(), node->type(), id, (bool)node->initializer(), false);
  if (_symtab.insert(id, symbol)) {
    _parent->set_new_symbol(symbol);  // advise parent that a symbol has been inserted
  } else {
    throw std::string("variable '" + id + "' redeclared");
  }
}

void l22::type_checker::processUnaryExpression(cdk::unary_operation_node *const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
  if (!node->argument()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type in argument of unary expression");  
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void l22::type_checker::do_identity_node(l22::identity_node *const node, int lvl) {
  processUnaryExpression(node, lvl);
}

void l22::type_checker::do_with_vector_update_node(l22::with_vector_update_node *const node, int lvl) {
  node->function()->accept(this, lvl + 4);
  node->vector()->accept(this, lvl + 4 );
  node->low()->accept(this, lvl + 4);
  node->high()->accept(this, lvl + 4);

  if(node->function()->type()->name() != cdk::TYPE_FUNCTIONAL){
    throw std::string("wrong type for function");
  }

  //std::shared_ptr<cdk::functional_type> function_type = cdk::functional_type::cast(node->function()->type);

  if(node->vector()->type()->name() != cdk::TYPE_POINTER){
    throw std::string("wrong type for vector");
  }

  if (!node->low()->is_typed(cdk::TYPE_INT)) throw std::string(
      "expected integer expression as lower bound of for cycle");
  if (!node->high()->is_typed(cdk::TYPE_INT)) throw std::string(
      "expected integer expression as upper bound of for cycle");
}

void l22::type_checker::do_iterate_node(l22::iterate_node *const node, int lvl){
  node->vector()->accept(this,lvl);
  node->count()->accept(this,lvl);
  node->function()->accept(this,lvl);
  node->condition()->accept(this,lvl);

  if(node->function()->type()->name() != cdk::TYPE_FUNCTIONAL){
    throw std::string("wrong type for function");
  }

  std::shared_ptr<cdk::functional_type> function_type = cdk::functional_type::cast(node->function()->type());

  if(node->vector()->type()->name() != cdk::TYPE_POINTER){
    throw std::string("wrong type for vector");
  }else{
    std::shared_ptr<cdk::reference_type> vector_type = cdk::reference_type::cast(node->vector()->type());
    if(function_type ->input_length()!=1 || vector_type->referenced()->name()!=function_type->input(0)->name()){
      throw std::string("incompatible types for vector and function");
    }
  }

  if (!node->count()->is_typed(cdk::TYPE_INT)) throw std::string(
      "expected integer expression as count");
  if (!node->condition()->is_typed(cdk::TYPE_INT)) throw std::string(
      "expected integer expression as condition");
}
  
