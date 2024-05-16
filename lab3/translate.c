#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "translate.h"
struct InterCodes* cur_inter_code = NULL;
struct InterCodes* code_head=NULL;

extern struct Symbol_table_item *s_table[HASH_TABLE_SIZE];
extern struct Symbol_table_item *struct_table[HASH_TABLE_SIZE];

int label_num=1;
int temp_var_num=1;
int translate_correct=1;
char *array_name = NULL;

void print_op(Operand op)
{
    switch(op->kind)
    {
        case OP_VARIABLE:
            printf("%s",op->u.name);break;
        case OP_CONSTANT:
            printf("#%d",op->u.value);break;
        case OP_ADDRESS:
            printf("%s",op->u.name);break;
        case OP_LABEL:
            printf("%s",op->u.name);break;
        case OP_FUNCTION:
        case OP_RELOP:
            printf("%s",op->u.name);break;
    }
}
void print_intercode()
{
    struct InterCodes* x = code_head;
    //int num=1;
    while(x != NULL)
    {
        //printf("%d  ",num);
        //num++;
        switch(x->code.kind)
        {
            case IR_LABEL:
                printf("LABEL ");
                print_op(x->code.u.one.op);
                printf(" :");
                break;
            case IR_FUNCTION:
                printf("FUNCTION ");
                print_op(x->code.u.one.op);
                printf(" :");
                break;
            case IR_ASSIGN:
                print_op(x->code.u.two.left);
                printf(" := ");
                print_op(x->code.u.two.right);
                break;
            case IR_ADD:
                print_op(x->code.u.three.result);
                printf(" := ");
                print_op(x->code.u.three.op1);
                printf(" + ");
                print_op(x->code.u.three.op2);
                break;
            case IR_SUB:
                print_op(x->code.u.three.result);
                printf(" := ");
                print_op(x->code.u.three.op1);
                printf(" - ");
                print_op(x->code.u.three.op2);
                break;
            case IR_MUL:
                print_op(x->code.u.three.result);
                printf(" := ");
                print_op(x->code.u.three.op1);
                printf(" * ");
                print_op(x->code.u.three.op2);
                break;
            case IR_DIV:
                print_op(x->code.u.three.result);
                printf(" := ");
                print_op(x->code.u.three.op1);
                printf(" / ");
                print_op(x->code.u.three.op2);
                break;
            case IR_GET_ADDR:
                print_op(x->code.u.two.left);
                printf(" := &");
                print_op(x->code.u.two.right);
                break;
            case IR_INTO_ADDR_RIGHT:
                print_op(x->code.u.two.left);
                printf(" := *");
                print_op(x->code.u.two.right);
                break;
            case IR_INTO_ADDR_LEFT:
                printf("*");
                print_op(x->code.u.two.left);
                printf(" := ");
                print_op(x->code.u.two.right);
                break;
            case IR_GOTO:
                printf("GOTO ");
                print_op(x->code.u.one.op);
                break;
            case IR_IF_GOTO:
                printf("IF ");
                print_op(x->code.u.if_goto.x);
                printf(" ");
                print_op(x->code.u.if_goto.relop);
                printf(" ");
                print_op(x->code.u.if_goto.y);
                printf(" GOTO ");
                print_op(x->code.u.if_goto.z);
                break;
            case IR_RETURN:
                printf("RETURN ");
                print_op(x->code.u.one.op);
                break;
            case IR_DEC:
                printf("DEC ");
                print_op(x->code.u.dec.op);
                printf(" ");
                printf("%d",x->code.u.dec.size);
                break;
            case IR_ARG:
                printf("ARG ");
                print_op(x->code.u.one.op);
                break;
            case IR_CALL:
                print_op(x->code.u.two.left);
                printf(" := CALL ");
                print_op(x->code.u.two.right);
                break;
            case IR_PARAM:
                printf("PARAM ");
                print_op(x->code.u.one.op);
                break;
            case IR_READ:
                printf("READ ");
                print_op(x->code.u.one.op);
                break;
            case IR_WRITE:
                printf("WRITE ");
                print_op(x->code.u.one.op);
                break;

        }
        printf("\n");
        x = x->next;
    }
    //printf("\n");
}

void print_op_to_file(FILE* fp, Operand op)
{
    switch(op->kind)
    {
        case OP_VARIABLE:
            fprintf(fp, "%s",op->u.name);break;
        case OP_CONSTANT:
            fprintf(fp, "#%d",op->u.value);break;
        case OP_ADDRESS:
            fprintf(fp, "%s",op->u.name);break;
        case OP_LABEL:
            fprintf(fp, "%s",op->u.name);break;
        case OP_FUNCTION:
        case OP_RELOP:
            fprintf(fp, "%s",op->u.name);break;
    }
}

void print_intercode_to_file(FILE* fp)
{
    struct InterCodes* x = code_head;
    while(x != NULL)
    {
        switch(x->code.kind)
        {
            case IR_LABEL:
                fprintf(fp, "LABEL ");
                print_op_to_file(fp, x->code.u.one.op);
                fprintf(fp, " :");
                break;
            case IR_FUNCTION:
                fprintf(fp, "FUNCTION ");
                print_op_to_file(fp, x->code.u.one.op);
                fprintf(fp, " :");
                break;
            case IR_ASSIGN:
                print_op_to_file(fp, x->code.u.two.left);
                fprintf(fp, " := ");
                print_op_to_file(fp, x->code.u.two.right);
                break;
            case IR_ADD:
                print_op_to_file(fp, x->code.u.three.result);
                fprintf(fp, " := ");
                print_op_to_file(fp, x->code.u.three.op1);
                fprintf(fp, " + ");
                print_op_to_file(fp, x->code.u.three.op2);
                break;
            case IR_SUB:
                print_op_to_file(fp, x->code.u.three.result);
                fprintf(fp, " := ");
                print_op_to_file(fp, x->code.u.three.op1);
                fprintf(fp, " - ");
                print_op_to_file(fp, x->code.u.three.op2);
                break;
            case IR_MUL:
                print_op_to_file(fp, x->code.u.three.result);
                fprintf(fp, " := ");
                print_op_to_file(fp, x->code.u.three.op1);
                fprintf(fp, " * ");
                print_op_to_file(fp, x->code.u.three.op2);
                break;
            case IR_DIV:
                print_op_to_file(fp, x->code.u.three.result);
                fprintf(fp, " := ");
                print_op_to_file(fp, x->code.u.three.op1);
                fprintf(fp, " / ");
                print_op_to_file(fp, x->code.u.three.op2);
                break;
            case IR_GET_ADDR:
                print_op_to_file(fp, x->code.u.two.left);
                fprintf(fp, " := &");
                print_op_to_file(fp, x->code.u.two.right);
                break;
            case IR_INTO_ADDR_RIGHT:
                print_op_to_file(fp, x->code.u.two.left);
                fprintf(fp, " := *");
                print_op_to_file(fp, x->code.u.two.right);
                break;
            case IR_INTO_ADDR_LEFT:
                fprintf(fp, "*");
                print_op_to_file(fp, x->code.u.two.left);
                fprintf(fp, " := ");
                print_op_to_file(fp, x->code.u.two.right);
                break;
            case IR_GOTO:
                fprintf(fp, "GOTO ");
                print_op_to_file(fp, x->code.u.one.op);
                break;
            case IR_IF_GOTO:
                fprintf(fp, "IF ");
                print_op_to_file(fp, x->code.u.if_goto.x);
                fprintf(fp, " ");
                print_op_to_file(fp, x->code.u.if_goto.relop);
                fprintf(fp, " ");
                print_op_to_file(fp, x->code.u.if_goto.y);
                fprintf(fp, " GOTO ");
                print_op_to_file(fp, x->code.u.if_goto.z);
                break;
            case IR_RETURN:
                fprintf(fp, "RETURN ");
                print_op_to_file(fp, x->code.u.one.op);
                break;
            case IR_DEC:
                fprintf(fp, "DEC ");
                print_op_to_file(fp, x->code.u.dec.op);
                fprintf(fp, " ");
                fprintf(fp, "%d",x->code.u.dec.size);
                break;
            case IR_ARG:
                fprintf(fp, "ARG ");
                print_op_to_file(fp, x->code.u.one.op);
                break;
            case IR_CALL:
                print_op_to_file(fp, x->code.u.two.left);
                fprintf(fp, " := CALL ");
                print_op_to_file(fp, x->code.u.two.right);
                break;
            case IR_PARAM:
                fprintf(fp, "PARAM ");
                print_op_to_file(fp, x->code.u.one.op);
                break;
            case IR_READ:
                fprintf(fp, "READ ");
                print_op_to_file(fp, x->code.u.one.op);
                break;
            case IR_WRITE:
                fprintf(fp, "WRITE ");
                print_op_to_file(fp, x->code.u.one.op);
                break;

        }
        fprintf(fp, "\n");
        x = x->next;
    }
}

void add_intercode(struct InterCodes * new_code)
{
    //printf("cur_inter_code\n");
    if(cur_inter_code == NULL)
    {
        //printf("cur_inter_code == NULL");
        code_head = new_code;
        cur_inter_code = new_code;
    }
    else
    {
        //printf("cur_inter_code != NULL\n");
        cur_inter_code->next = new_code;
        new_code->prev=cur_inter_code;
        cur_inter_code=new_code;
    }
    //printf("exitadd\n");
}

Operand new_temp()
{
    Operand op = (Operand)malloc(sizeof(struct Operand_));
    op->kind = OP_VARIABLE;
    char *str = (char*)malloc(100);
    sprintf(str, "t%d", temp_var_num);
    op->u.name = str;
    op->u.is_addr=0;
    temp_var_num++;
    return op;
}

Operand new_label()
{
    Operand op = (Operand)malloc(sizeof(struct Operand_));
    op->kind = OP_LABEL;
    char *str = (char*)malloc(100);
    sprintf(str, "label%d", label_num);
    op->u.name = str;
    label_num++;
    return op;
}

//IR_LABEL, IR_FUNCTION, IR_GOTO, IR_RETURN, IR_ARG, IR_PARAM, IR_READ, IR_WRITE
void create_one_intercode(Operand op, int kind)
{
    //printf("create one intercode\n");
    if(op->kind == OP_ADDRESS && op->u.is_addr==0)
    {
        Operand t1 = new_temp();
        create_two_intercode(t1, op, IR_INTO_ADDR_RIGHT);
        op = t1;
    }
    //printf("Intercodes\n");
    struct InterCodes * new_code = (struct InterCodes*)malloc(sizeof(struct InterCodes));
    new_code->next=NULL;
    new_code->prev=NULL;
    new_code->code.kind=kind;
    new_code->code.u.one.op = op;
    //print_op(op);
    //printf("\n%d\n",kind);
    //printf("addintercode\n");
    add_intercode(new_code);
}

/*
IR_ASSIGN,
IR_GET_ADDR,IR_INTO_ADDR_RIGHT,IR_INTO_ADDR_LEFT,
IR_CALL
*/
void create_two_intercode(Operand op1,Operand op2, int kind)
{
    if(kind == IR_ASSIGN && (op1->kind == OP_ADDRESS || op2->kind == OP_ADDRESS))
    {
        if(op1->kind == OP_ADDRESS && op2->kind != OP_ADDRESS)
            create_two_intercode(op1, op2, IR_INTO_ADDR_LEFT);
        else if(op2->kind == OP_ADDRESS && op1->kind != OP_ADDRESS)
            create_two_intercode(op1, op2, IR_INTO_ADDR_RIGHT);
        else
        {
            Operand t1 = new_temp();
            create_two_intercode(t1, op2, IR_INTO_ADDR_RIGHT);
            create_two_intercode(op1, t1, IR_INTO_ADDR_LEFT);
        }
    }
    else if(kind == IR_GET_ADDR && op2->kind == OP_ADDRESS)
    {
        struct InterCodes * new_code = (struct InterCodes*)malloc(sizeof(struct InterCodes));
        new_code->next=NULL;
        new_code->prev=NULL;
        new_code->code.kind=IR_ASSIGN;
        new_code->code.u.two.left = op1;
        new_code->code.u.two.right = op2;
        add_intercode(new_code);
    }
    else
    {
        struct InterCodes * new_code = (struct InterCodes*)malloc(sizeof(struct InterCodes));
        new_code->next=NULL;
        new_code->prev=NULL;
        new_code->code.kind=kind;
        new_code->code.u.two.left = op1;
        new_code->code.u.two.right = op2;
        add_intercode(new_code);
    }

}

//IR_ADD,IR_SUB,IR_MUL,IR_DIV,
void create_three_intercode(Operand result, Operand op1,Operand op2, int kind)
{
    if(op1->kind == OP_ADDRESS && op1->u.is_addr==0)
    {
        Operand t1 = new_temp();
        create_two_intercode(t1, op1, IR_INTO_ADDR_RIGHT);
        op1 = t1;
    }
    if(op2->kind == OP_ADDRESS && op1->u.is_addr==0)
    {
        Operand t1 = new_temp();
        create_two_intercode(t1, op2, IR_INTO_ADDR_RIGHT);
        op2 = t1;
    }

    struct InterCodes * new_code = (struct InterCodes*)malloc(sizeof(struct InterCodes));
    new_code->next=NULL;
    new_code->prev=NULL;
    new_code->code.kind=kind;
    new_code->code.u.three.result = result;
    new_code->code.u.three.op1 = op1;
    new_code->code.u.three.op2 = op2;
    add_intercode(new_code);
}


void translate_Exp(Node exp, Operand place)
{
    /*	Exp ->
        //基本表达式
          Exp ASSIGNOP Exp			1
        | ID						1
        | INT						1
        | Exp PLUS Exp				1
        | Exp MINUS Exp				1
        | Exp STAR Exp				1
        | Exp DIV Exp				1
        | MINUS Exp					1

        //条件表达式
        | Exp AND Exp				1
        | Exp OR Exp				1
        | Exp RELOP Exp				1
        | NOT Exp					1

        //函数调用
        | ID LP Args RP				1
        | ID LP RP					1

        | Exp LB Exp RB	//数组		1
        | Exp DOT ID	//结构体		1

        | LP Exp RP					1
*/
    //printf("eeeeeexp\n");
    //Exp -> INT
    if(translate_correct==0)
        return;
    if(strcmp(exp->child->name,"LP")==0)
        translate_Exp(exp->child->bro, place);
    else if(strcmp(exp->child->name,"INT")==0)
    {
        /*Operand op = (Operand)malloc(sizeof(struct Operand_));
        op->kind = OP_CONSTANT;
        op->u.value = atoi(exp->child->text);

		create_two_intercode(place, op, IR_ASSIGN);*/
        temp_var_num--;
        place->kind = OP_CONSTANT;
        place->u.value = exp->child->data.val_int;
    }
        //Exp -> ID
    else if(strcmp(exp->child->name,"ID")==0 && exp->child->bro == NULL)
    {
        /*Operand op = (Operand)malloc(sizeof(struct Operand_));
        op->kind = OP_VARIABLE;
        op->u.name = exp->child->text;
        create_two_intercode(place, op, IR_ASSIGN);*/
       //printf("%s,%s\n",exp->child->name,exp->child->data.var_ID);
        struct Symbol_table_item* item = find_items_s_table(exp->child->data.var_ID);
        if(item->f->is_param==1&&item->f->type->kind==STRUCTURE)
            place->kind = OP_ADDRESS;
        else
            place->kind = OP_VARIABLE;
        temp_var_num--;
        place->u.name = exp->child->data.var_ID;
        //printf("return form exp id\n");
    }
        //Exp -> Exp ASSIGNOP Exp
    else if(strcmp(exp->child->name, "Exp")==0 && strcmp(exp->child->bro->name, "ASSIGNOP")==0)
    {   //todo? bug
        //不考虑结构体和数组
        /*Operand exp1 = (Operand)malloc(sizeof(struct Operand_));
        exp1->kind = OP_VARIABLE;
        exp1->u.name = exp->child->child->text;*/
        Operand t2 = new_temp();
        if(strcmp(exp->child->child->name,"ID")==0)
        {
            find_items_s_table(exp->child->data.var_ID);
            temp_var_num--;
            t2->kind = OP_VARIABLE;
            t2->u.name = exp->child->child->data.var_ID;
        }


        translate_Exp(exp->child, t2);

        Operand t1 = new_temp();
        translate_Exp(exp->child->bro->bro,t1);

        create_two_intercode(t2, t1, IR_ASSIGN);
    }
        //Exp -> Exp PLUS Exp
    else if(strcmp(exp->child->name, "Exp")==0 && strcmp(exp->child->bro->name, "PLUS")==0)
    {
        Operand t1 = new_temp();
        Operand t2 = new_temp();

        translate_Exp(exp->child,t1);
        translate_Exp(exp->child->bro->bro,t2);

        create_three_intercode(place, t1, t2, IR_ADD);
    }
        //Exp -> Exp MINUS Exp
    else if(strcmp(exp->child->name, "Exp")==0 && strcmp(exp->child->bro->name, "MINUS")==0)
    {
        Operand t1 = new_temp();
        Operand t2 = new_temp();

        translate_Exp(exp->child,t1);
        translate_Exp(exp->child->bro->bro,t2);

        create_three_intercode(place, t1, t2, IR_SUB);
    }
        //Exp -> Exp STAR Exp
    else if(strcmp(exp->child->name, "Exp")==0 && strcmp(exp->child->bro->name, "STAR")==0)
    {
        Operand t1 = new_temp();
        Operand t2 = new_temp();

        translate_Exp(exp->child,t1);
        translate_Exp(exp->child->bro->bro,t2);

        create_three_intercode(place, t1, t2, IR_MUL);
    }
        //Exp -> Exp DIV Exp
    else if(strcmp(exp->child->name, "Exp")==0 && strcmp(exp->child->bro->name, "DIV")==0)
    {
        Operand t1 = new_temp();
        Operand t2 = new_temp();

        translate_Exp(exp->child,t1);
        translate_Exp(exp->child->bro->bro,t2);

        create_three_intercode(place, t1, t2, IR_DIV);
    }
        //Exp -> MINUS Exp
    else if(strcmp(exp->child->name, "MINUS")==0)
    {
        Operand t1 = new_temp();
        translate_Exp(exp->child->bro,t1);

        Operand t2 = (Operand)malloc(sizeof(struct Operand_));
        t2->kind = OP_CONSTANT;
        t2->u.value = 0;

        create_three_intercode(place, t2, t1, IR_SUB);
    }
    else if(strcmp(exp->child->name, "NOT")==0 || (strcmp(exp->child->name, "Exp")==0 && strcmp(exp->child->bro->name, "RELOP")==0)||(strcmp(exp->child->name, "Exp")==0 && strcmp(exp->child->bro->name, "AND")==0)||(strcmp(exp->child->name, "Exp")==0 && strcmp(exp->child->bro->name, "OR")==0))
    {//todo? bug
        Operand label1 = new_label();
        Operand label2 = new_label();
        //printf("1%s\n",exp->child->name);
        Operand t1 = (Operand)malloc(sizeof(struct Operand_));
        t1->kind = OP_CONSTANT;
        t1->u.value = 0;

        Operand t2 = (Operand)malloc(sizeof(struct Operand_));
        t2->kind = OP_CONSTANT;
        t2->u.value = 1;

        create_two_intercode(place, t1, IR_ASSIGN);
        translate_Cond(exp, label1, label2);
        create_one_intercode(label1, IR_LABEL);
        create_two_intercode(place, t2, IR_ASSIGN);
        create_one_intercode(label2, IR_LABEL);
    }
        //Exp -> ID LB (Args) RB
    else if(strcmp(exp->child->name, "ID")==0 && exp->child->bro != NULL)
    {
        //printf("%s\n",exp->child->text);
        Operand t = (Operand)malloc(sizeof(struct Operand_));
        t->kind = OP_FUNCTION;
        t->u.name = exp->child->data.var_ID;
        if(strcmp(exp->child->bro->bro->name,"RP")==0)
        {
            if(strcmp(exp->child->data.var_ID, "read")==0)
            {
                create_one_intercode(place, IR_READ);
            }
            else
            {
                if(place != NULL)
                    create_two_intercode(place, t, IR_CALL);
                else
                {
                    Operand t1 = new_temp();
                    create_two_intercode(t1, t, IR_CALL);
                }
            }
        }
        else
        {
            //这里由于要在函数中实现改变arg_list的值，因此创建了指针的指针作为参数传入
            //用单向连表存储参数列表，每新增一个参数，将其插入链表头部，以实现实参倒序传入
            struct Arg_list *arg_list = NULL;
            struct Arg_list **arg_list_p = &arg_list;
            translate_Args(exp->child->bro->bro, arg_list_p);
            if(strcmp(exp->child->data.var_ID, "write")==0)//todo?
            {
                create_one_intercode(arg_list->op, IR_WRITE);
            }
            else
            {
                struct Arg_list *temp = arg_list;
                while(temp != NULL)
                {
                    struct Symbol_table_item *item = find_items_s_table(temp->op->u.name);
                    //结构体作为参数，传引用
                    if(item!= NULL && item->f->type->kind==STRUCTURE){
                        Operand t1 = new_temp();
                        create_two_intercode(t1, temp->op, IR_GET_ADDR);
                        t1->kind = OP_ADDRESS;
                        t1->u.is_addr=1;
                        create_one_intercode(t1, IR_ARG);
                    }
                    else
                        create_one_intercode(temp->op, IR_ARG);
                    temp=temp->next;
                }
                if(place != NULL)
                    create_two_intercode(place, t, IR_CALL);
                else
                {
                    Operand t1 = new_temp();
                    create_two_intercode(t1, t, IR_CALL);
                }
            }
        }
    }
        //Exp -> Exp1 LB Exp2 RB
    else if(strcmp(exp->child->name, "Exp")==0 && strcmp(exp->child->bro->name, "LB")==0)
    {
        /*	translate_Exp(Exp2, t1);
            t2 = t1*4;
            translate_Exp(Exp1, ID);//这里默认左侧Exp为ID
            t3 = &ID;
            place = t3+t2;
            不为id的情况：结构体变量，此时应返回地址类型变量
        */
        Operand t1 = new_temp();
        Operand t2 = new_temp();
        Operand t3 = new_temp();
        Operand id = new_temp();
        translate_Exp(exp->child->bro->bro,t1);
        translate_Exp(exp->child, id);
        //printf("%s\n",id->u.name);
        struct Symbol_table_item *item = find_items_s_table(id->u.name);
        if(item == NULL)
        {
            item = find_items_struct_table(id->u.name);
            if(item == NULL)
                printf("数组调用处发生段错误\n");
            return;
        }
        //print_hash_table();
        Operand t = (Operand)malloc(sizeof(struct Operand_));
        t->kind = OP_CONSTANT;
        t->u.value = get_size(item->f->type->u.array.elem);

        create_three_intercode(t2,t1,t,IR_MUL);
        create_two_intercode(t3,id, IR_GET_ADDR);
        create_three_intercode(place,t3,t2,IR_ADD);
        place->kind = OP_ADDRESS;
        //place->u.name = id->u.name;
        array_name = id->u.name;
        //printf("%s\n",id->u.name);
    }
        //Exp -> Exp1 DOT ID2
    else if(strcmp(exp->child->name, "Exp")==0 && strcmp(exp->child->bro->name, "DOT")==0)
    {
        /*	translate_Exp(Exp1, ID);
            t1 = &ID;
            t2 = offset;
            place = t1+t2;
        */

        Operand id = new_temp();
        translate_Exp(exp->child, id);
        Operand t1;
        if(id->kind != OP_ADDRESS)
        {
            t1 = new_temp();
            create_two_intercode(t1,id, IR_GET_ADDR);
        }
        else
        {
            t1 = id;
            t1->u.is_addr=1;
        }

        Operand id2 = (Operand)malloc(sizeof(struct Operand_));
        id2->kind = OP_VARIABLE;
        id2->u.name = exp->child->bro->bro->data.var_ID;

        int offset=0;
        struct Symbol_table_item *item = find_items_s_table(id->u.name);
        if(item == NULL)
        {
            //说明此变量为结构体成员变量
            item = find_items_struct_table(id->u.name);
            if(item == NULL)
            {
                //结构体数组
                item = find_items_s_table(array_name);
                if(item == NULL)
                {
                    item = find_items_struct_table(array_name);
                    if(item == NULL)
                        printf("结构体调用处发生段错误\n");
                }
            }
        }

        FieldList tmp;
        if(item->f->type->kind == ARRAY)//结构体数组
            tmp = item->f->type->u.array.elem->u.structure_.structure;
        else
            tmp = item->f->type->u.structure_.structure;

        while(tmp != NULL)
        {
            if(strcmp(tmp->name,id2->u.name)==0)
                break;
            else
                offset=offset+get_size(tmp->type);
            tmp=tmp->tail;
        }
        Operand t2 = (Operand)malloc(sizeof(struct Operand_));
        t2->kind = OP_CONSTANT;
        t2->u.value = offset;

        create_three_intercode(place,t1,t2,IR_ADD);
        place->kind = OP_ADDRESS;
        place->u.name = id2->u.name;
        //printf("%s %s\n",place->u.name,id2->u.name);

    }
}

void translate_Args(Node node, struct Arg_list ** arg_list_p)
{
    if(translate_correct==0)
        return;
    //Exp
    if(node->child->bro == NULL)
    {
        struct Arg_list *temp = (struct Arg_list *)malloc(sizeof(struct Arg_list));
        temp->op = new_temp();
        translate_Exp(node->child, temp->op);

        if(temp->op->kind == OP_VARIABLE)
        {
            struct Symbol_table_item *temp_item = find_items_s_table(temp->op->u.name);
            if(temp_item != NULL && temp_item->f->type->kind == ARRAY)
            {
                translate_correct = 0;
                printf("Cannot translate: Code contains parameters of array type.\n");
                return;
            }
        }


        if(*arg_list_p == NULL)
            *arg_list_p = temp;
        else
        {
            temp->next = *arg_list_p;
            *arg_list_p = temp;
        }
    }
        //Exp COMMA Args
    else
    {
        struct Arg_list *temp = (struct Arg_list *)malloc(sizeof(struct Arg_list));
        temp->op = new_temp();
        translate_Exp(node->child, temp->op);

        if(temp->op->kind == OP_VARIABLE)
        {
            struct Symbol_table_item *temp_item = find_items_s_table(temp->op->u.name);
            if(temp_item != NULL && temp_item->f->type->kind == ARRAY)
            {
                translate_correct = 0;
                printf("Cannot translate: Code contains parameters of array type.\n");
                return;
            }
        }

        if(*arg_list_p == NULL)
            *arg_list_p = temp;
        else
        {
            temp->next = *arg_list_p;
            *arg_list_p = temp;
        }
        translate_Args(node->child->bro->bro, arg_list_p);
    }
}


void translate_Cond(Node node, Operand label_true, Operand label_false)
{
    //printf("cond:%s\n",node->child->name);
    if(translate_correct==0)
        return;
    if(strcmp(node->child->name,"NOT")==0)
    {
        //printf("NOT\n");
        translate_Cond(node->child, label_false, label_true);
    }
    else if(strcmp(node->child->name,"ID")==0)
    {
        //printf("\nELSE\n");
        Operand t1 = new_temp();
        //printf("RIGHT OR:%s\n",node->child->name);
        translate_Exp(node, t1);

        Operand t2 = (Operand)malloc(sizeof(struct Operand_));
        t2->kind = OP_CONSTANT;
        t2->u.value = 0;

        Operand relop1 = (Operand)malloc(sizeof(struct Operand_));
        relop1->kind = OP_RELOP;
        relop1->u.name = "!=";

        if(t1->kind == OP_ADDRESS)
        {
            Operand t100 = new_temp();
            create_two_intercode(t100, t1, IR_INTO_ADDR_RIGHT);
            t1 = t100;
        }

        if(t2->kind == OP_ADDRESS)
        {
            Operand t100 = new_temp();
            create_two_intercode(t100, t2, IR_INTO_ADDR_RIGHT);
            t2 = t100;
        }
        //print_hash_table();
        struct InterCodes * new_code = (struct InterCodes*)malloc(sizeof(struct InterCodes));
        new_code->next=NULL;
        new_code->prev=NULL;
        new_code->code.kind=IR_IF_GOTO;
        new_code->code.u.if_goto.x = t1;
        new_code->code.u.if_goto.relop = relop1;
        new_code->code.u.if_goto.y = t2;
        new_code->code.u.if_goto.z = label_true;
        add_intercode(new_code);
        create_one_intercode(label_false, IR_GOTO);
    }
    else if(strcmp(node->child->bro->name,"RELOP")==0)
    {
        Operand t1 = new_temp();
        Operand t2 = new_temp();
        translate_Exp(node->child, t1);
        translate_Exp(node->child->bro->bro, t2);
        //printf("exit exp");
        Operand relop1 = (Operand)malloc(sizeof(struct Operand_));
        relop1->kind = OP_RELOP;
        relop1->u.name = node->child->bro->data.var_ID;
        //if_goto语句，对地址类型变量取值
        if(t1->kind == OP_ADDRESS)
        {
            Operand t100 = new_temp();
            create_two_intercode(t100, t1, IR_INTO_ADDR_RIGHT);
            t1 = t100;
        }

        if(t2->kind == OP_ADDRESS)
        {
            Operand t100 = new_temp();
            create_two_intercode(t100, t2, IR_INTO_ADDR_RIGHT);
            t2 = t100;
        }

        struct InterCodes * new_code = (struct InterCodes*)malloc(sizeof(struct InterCodes));
        new_code->next=NULL;
        new_code->prev=NULL;
        new_code->code.kind=IR_IF_GOTO;
        new_code->code.u.if_goto.x = t1;
        new_code->code.u.if_goto.relop = relop1;
        new_code->code.u.if_goto.y = t2;
        new_code->code.u.if_goto.z = label_true;
        add_intercode(new_code);
        create_one_intercode(label_false, IR_GOTO);
    }
    else if(strcmp(node->child->bro->name,"AND")==0)
    {
        Operand label1 = new_label();
        translate_Cond(node->child, label1, label_false);
        create_one_intercode(label1, IR_LABEL);
        translate_Cond(node->child->bro->bro, label_true, label_false);
    }
    else if(strcmp(node->child->bro->name,"OR")==0)
    {
        Operand label1 = new_label();
        translate_Cond(node->child, label_true, label1);
        create_one_intercode(label1, IR_LABEL);
        //printf("OR:%s\n",node->child->bro->bro->child->data.var_ID);
        translate_Cond(node->child->bro->bro, label_true, label_false);
        //printf("OR:return\n");
    }
    else
    {
        Operand t1 = new_temp();
        //printf("RIGHT OR:%s\n",node->child->name);
        translate_Exp(node, t1);

        Operand t2 = (Operand)malloc(sizeof(struct Operand_));
        t2->kind = OP_CONSTANT;
        t2->u.value = 0;

        Operand relop1 = (Operand)malloc(sizeof(struct Operand_));
        relop1->kind = OP_RELOP;
        relop1->u.name = "!=";

        if(t1->kind == OP_ADDRESS)
        {
            Operand t100 = new_temp();
            create_two_intercode(t100, t1, IR_INTO_ADDR_RIGHT);
            t1 = t100;
        }

        if(t2->kind == OP_ADDRESS)
        {
            Operand t100 = new_temp();
            create_two_intercode(t100, t2, IR_INTO_ADDR_RIGHT);
            t2 = t100;
        }
        //print_hash_table();
        struct InterCodes * new_code = (struct InterCodes*)malloc(sizeof(struct InterCodes));
        new_code->next=NULL;
        new_code->prev=NULL;
        new_code->code.kind=IR_IF_GOTO;
        new_code->code.u.if_goto.x = t1;
        new_code->code.u.if_goto.relop = relop1;
        new_code->code.u.if_goto.y = t2;
        new_code->code.u.if_goto.z = label_true;
        add_intercode(new_code);
        create_one_intercode(label_false, IR_GOTO);
    }
}

int get_size(Type type)
{
    if(type == NULL)
        return 0;
    else if(type->kind == BASIC)
    {
        return 4;
    }
    else if(type->kind == ARRAY)
    {
        return type->u.array.size*get_size(type->u.array.elem);
    }
    else if(type->kind == STRUCTURE)
    {
        int size=0;
        FieldList temp = type->u.structure_.structure;
        while(temp != NULL)
        {
            if(temp->type->kind == BASIC)
            {
                size=size+4;
            }
            else if(temp->type->kind == ARRAY)
            {
                size = size+temp->type->u.array.size*get_size(temp->type->u.array.elem);
            }
            else if(temp->type->kind == STRUCTURE)
            {
                size = size+get_size(temp->type);
            }
            temp = temp->tail;
        }
        return size;
    }
    return 0;
}

void translate_VarDec(Node node, Operand place)
{
    if(translate_correct==0)
        return;
    //printf("translateVarDec:%s\n",node->child->name);
    if(strcmp(node->child->name,"ID")==0)
    {
        //printf("%s\n",node->child->data.var_ID);
        //print_hash_table();
        struct Symbol_table_item *temp = find_items_s_table(node->child->data.var_ID);
        if(temp->f->type->kind == BASIC)
        {
            if(place != NULL)
            {
                //定义变量时进行初始化
                temp_var_num--;
                place->kind = OP_VARIABLE;
                place->u.name = temp->f->name;
            }
        }
        else if(temp->f->type->kind == ARRAY)
        {
            //这里不考虑数组用另一个数组进行初始化
            if(temp->f->type->u.array.elem->kind == ARRAY)
            {
                translate_correct = 0;
                printf("Cannot translate: Code contains variables of multi-dimensional array type.\n");
                return;
            }
            else
            {
                Operand op = (Operand)malloc(sizeof(struct Operand_));
                op->kind = OP_VARIABLE;
                op->u.name = temp->f->name;

                struct InterCodes * new_code = (struct InterCodes*)malloc(sizeof(struct InterCodes));
                new_code->next=NULL;
                new_code->prev=NULL;
                new_code->code.kind=IR_DEC;
                new_code->code.u.dec.op = op;
                new_code->code.u.dec.size = get_size(temp->f->type);
                add_intercode(new_code);
            }
        }
        else if(temp->f->type->kind == STRUCTURE)
        {
            //TODO:选做1部分
            Operand op = (Operand)malloc(sizeof(struct Operand_));
            op->kind = OP_VARIABLE;
            op->u.name = temp->f->name;
            //printf("%d\n",temp->f->type->u.structure_.structure->type->u.array.elem->kind);
            struct InterCodes * new_code = (struct InterCodes*)malloc(sizeof(struct InterCodes));
            new_code->next=NULL;
            new_code->prev=NULL;
            new_code->code.kind=IR_DEC;
            new_code->code.u.dec.op = op;
            new_code->code.u.dec.size = get_size(temp->f->type);
            add_intercode(new_code);
        }
    }
    else
        translate_VarDec(node->child, place);
}

void translate_Dec(Node node)
{
    if(translate_correct==0)
        return;
    //printf("1\n");
    if(node->child->bro != NULL)
    {
        //printf("%s,%s\n",node->child->name,node->child->bro->name);
        Operand t1 = new_temp();
        Operand t2 = new_temp();
        translate_VarDec(node->child, t1);
        translate_Exp(node->child->bro->bro, t2);
        create_two_intercode(t1,t2,IR_ASSIGN);
    }
    else {
        //printf("%s\n",node->child->name);;
        translate_VarDec(node->child, NULL);
    }
}

void translate_DecList(Node node)
{
    if(translate_correct==0)
        return;
    //printf("translate_DecList\n");
    translate_Dec(node->child);
    if(node->child->bro != NULL)
    {
        //printf("%s",node->child->bro->name);
        translate_DecList(node->child->bro->bro);
    }
}

void translate_Def(Node node)
{
    if(translate_correct==0)
        return;
    //printf("translate_Def\n");
    translate_DecList(node->child->bro);
}

void translate_DefList(Node node)
{
    if(translate_correct==0)
        return;
    if(node == NULL)
        return;
    if(strcmp(node->child->name,"Def")==0)
    {
        translate_Def(node->child);
        translate_DefList(node->child->bro);
    }
}

void translate_CompSt(Node node)
{
    if(translate_correct==0)
        return;
    Node CompSt = node;
    Node StmtList;

    //printf("%s\n",CompSt->child->bro->name);
    if(strcmp(CompSt->child->bro->name,"StmtList") == 0)
        StmtList = CompSt->child->bro;
    else
    {
        //print_hash_table();
        StmtList = CompSt->child->bro->bro;
        translate_DefList(CompSt->child->bro);
    }
    translate_StmtList(StmtList);
}
void translate_Stmt(Node node)
{
    if(translate_correct==0)
        return;
    //printf("Stmt\n");
    //Exp SEMI
    if(strcmp(node->child->name,"Exp")==0)
    {
        //printf("xwj\n");
        translate_Exp(node->child, NULL);
    }
        //CompSt
    else if(strcmp(node->child->name,"CompSt")==0)
    {
        translate_CompSt(node->child);
    }
        //RETURN Exp SEMI
    else if(strcmp(node->child->name,"RETURN")==0)
    {
        Operand t1 = new_temp();
        translate_Exp(node->child->bro, t1);

        create_one_intercode(t1, IR_RETURN);
    }
        //IF LP Exp RP Stmt (ELSE Stmt)
    else if(strcmp(node->child->name,"IF")==0)
    {
        //printf("IF\n");
        //printf("%s\n",node->name);
        Operand label1 = new_label();
        Operand label2 = new_label();
        Node Exp = node->child->bro->bro;
        Node Stmt1 = Exp->bro->bro;
        //printf("exp\n");
        translate_Cond(Exp, label1, label2);
        //printf("stmt\n");
        create_one_intercode(label1, IR_LABEL);
        //printf("stmt\n");
        if (Stmt1!=NULL)
            translate_Stmt(Stmt1);
        if(Stmt1->bro == NULL)
        {

            create_one_intercode(label2, IR_LABEL);
            //printf("if\n");
        }
        else
        {
            //printf("if else:\n");
            Operand label3 = new_label();
            Node Stmt2 = Stmt1->bro->bro;
            create_one_intercode(label3, IR_GOTO);
            create_one_intercode(label2, IR_LABEL);
            translate_Stmt(Stmt2);
            create_one_intercode(label3, IR_LABEL);
            //printf("if else\n");
        }
    }
        //WHILE LP Exp RP Stmt
    else if(strcmp(node->child->name,"WHILE")==0)
    {
        //printf("------------------\n");
        //print_intercode();
        Operand label1 = new_label();
        Operand label2 = new_label();
        Operand label3 = new_label();
        //printf("------------------------------------------------------\n");
        //printf("------------------------------------------------------\n");
        create_one_intercode(label1, IR_LABEL);
        //printf("***************************************\n");
        translate_Cond(node->child->bro->bro, label2, label3);
        //printf("***************************************\n");
        create_one_intercode(label2, IR_LABEL);
        translate_Stmt(node->child->bro->bro->bro->bro);
        //printf("***************************************\n");
        create_one_intercode(label1, IR_GOTO);
        create_one_intercode(label3, IR_LABEL);
    }
}

void translate_StmtList(Node node)
{
    if(translate_correct==0)
        return;
    if(node == NULL)
        return;
    if(strcmp(node->child->name,"Stmt")==0)
    {
        //printf("StmtList\n");
        translate_Stmt(node->child);
        translate_StmtList(node->child->bro);
    }
}

void translate_FunDec(Node node)
{
    if(translate_correct==0)
        return;
    //printf("%s\n",node->child->data.var_ID);
    Operand t = (Operand)malloc(sizeof(struct Operand_));
    //printf("FunDec5\n");
    t->kind = OP_FUNCTION;
    t->u.name = node->child->data.var_ID;
    create_one_intercode(t, IR_FUNCTION);
    //printf("finish create an intercode\n");
    struct Symbol_table_item *fun = find_items_s_table(t->u.name);
    if(fun->f->type->u.function.paramNum != 0)
    {
        FieldList temp = fun->f->type->u.function.params;
        while(temp != NULL)
        {
            Operand tt = (Operand)malloc(sizeof(struct Operand_));
            tt->kind = OP_VARIABLE;
            tt->u.name = temp->name;
            //printf("var:[%s]\n",temp->name);
            temp->is_param=1;
            create_one_intercode(tt, IR_PARAM);
            temp = temp->tail;
        }
    }
}
void translate_ExtDef(Node node)
{
    if(translate_correct==0)
        return;
    if(strcmp(node->child->bro->name,"FunDec")==0)
    {
        //printf("FunDec\n");
        Node FunDec = node->child->bro;
        translate_FunDec(FunDec);
        Node CompSt = FunDec->bro;
        translate_CompSt(CompSt);
    }
}

void translate_ExtDefList(Node node)
{
    if(translate_correct==0)
        return;
    if(node == NULL)
        return;
    if(strcmp(node->child->name,"ExtDef")==0)
    {
        //printf("[ExtDef]\n");
        translate_ExtDef(node->child);
        translate_ExtDefList(node->child->bro);
    }
}
void traverse_gen_intercode(Node this_node)
{
    if(translate_correct==0)
        return;
    if(this_node == NULL)
        return;
    if(strcmp(this_node->name,"ExtDefList")==0)
    {
        //printf("[ExtDefList]\n");
        translate_ExtDefList(this_node);
    }
    else
    {
        traverse_gen_intercode(this_node->child);
        traverse_gen_intercode(this_node->bro);
    }

}
