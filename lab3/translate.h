#ifndef _INTERMEDIATE_H_
#define _INTERMEDIATE_H_
#include<stdio.h>
#include "tree.h"
#include "semantic.h"
#include "symtab.h"
#define MAX_LINE 100000
typedef struct Operand_ *Operand;

struct Operand_
{
    enum
    {
        OP_VARIABLE,
        OP_CONSTANT,
        OP_ADDRESS,
        OP_LABEL,
        OP_FUNCTION,
        OP_RELOP
    } kind;
    struct {
        int var_no;
        int value;
        char *name;
        int is_addr;
    } u;
};
struct InterCode
{
    enum
    {
        IR_LABEL,
        IR_FUNCTION,
        IR_ASSIGN,
        IR_ADD,IR_SUB,IR_MUL,IR_DIV,
        IR_GET_ADDR,IR_INTO_ADDR_RIGHT,IR_INTO_ADDR_LEFT,
        IR_GOTO,
        IR_IF_GOTO,
        IR_RETURN,
        IR_DEC,
        IR_ARG,
        IR_CALL,
        IR_PARAM,
        IR_READ,
        IR_WRITE

    } kind;
    union {
        struct
        {
            Operand op;
        } one;
        struct
        {
            Operand right, left;
        } two;
        struct
        {
            Operand result, op1, op2;
        } three;
        struct
        {
            Operand x, relop, y, z;
        } if_goto;
        struct
        {
            Operand op;
            int size;
        }dec;
    } u;
};

struct InterCodes
{
    struct InterCode code;
    struct InterCodes *prev, *next;
};

struct Arg_list
{
    Operand op;
    struct Arg_list *next;
};
void traverse_gen_intercode(Node this_node);
void create_one_intercode(Operand op, int kind);
void create_two_intercode(Operand op1,Operand op2, int kind);
void create_three_intercode(Operand result, Operand op1,Operand op2, int kind);

int get_size(Type type);
void translate_Exp(Node exp, Operand place);
void translate_Args(Node node, struct Arg_list ** arg_list_p);
void translate_Cond(Node node, Operand label_true, Operand label_false);
void translate_VarDec(Node node, Operand place);
void translate_Dec(Node node);
void translate_DecList(Node node);
void translate_Def(Node node);
void translate_DefList(Node node);
void translate_CompSt(Node node);
void translate_Stmt(Node node);
void translate_StmtList(Node node);
void translate_FunDec(Node node);
void translate_ExtDef(Node node);
void translate_ExtDefList(Node node);

void print_intercode_to_file(FILE* fp);
void print_intercode();

#endif


