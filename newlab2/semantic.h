#ifndef C__COMPLIER_SEMANTIC_H
#define C__COMPLIER_SEMANTIC_H
#include "symtab.h"
#include "tree.h"

struct Symbol_table_item * Dec_in_structure(Node node, Type type);
FieldList Def_in_structure(Node node);/*, FieldList temp_field, FieldList head_field*/

Type Specifier(Node node);
struct Symbol_table_item *VarDec(Node node, Type type);
Type Exp(Node node);
struct Symbol_table_item *Dec(Node node, Type type);
void Def(Node node);
void CompSt(Node node, Type function_type);
void ExtDef(Node node);

void traverse(Node this_node,int depth);


#endif //C__COMPLIER_SEMANTIC_H
