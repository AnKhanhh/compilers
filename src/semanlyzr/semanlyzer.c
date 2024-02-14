//  nested code block is only allowed inside function definition, which simplifies scoping
//	since functions don't have return statement, closure or inline function call is not supported
//	all array is 2d

//	all variable, constant, function and array share the same namespace
//	PL/0 is declarative, meaning it has a separate declaration section, simplifying declaration check

#include <stdio.h>
#include "list_semantic_check.h"
#include "list_symbol_table.h"
#include "../parser/syntax_tree.h"

void SemanticAnalysis(NodeAST* root, FILE* out) {

}