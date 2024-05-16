#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "semantic.h"
extern int semantic_line;
extern int cur_stack_deep;
char anonymous_struct_name[100] = "Ikun";
extern struct Symbol_table_item *s_table[HASH_TABLE_SIZE] ;
extern struct Symbol_table_item *struct_table[HASH_TABLE_SIZE] ;
extern struct Symbol_table_item *stack[STACK_DEEP] ;
extern struct Symbol_table_item *cur_depth_symbol[STACK_DEEP] ;

//初始化符号表：添加read、write函数
//其中read函数没有任何参数,返回值为int型(即读入的整数值),write
//函数包含一个int类型的参数(即要输出的整数值),返回值也为int型(固定返回0)。
void init_table()
{
    Type spe_type = (Type)malloc(sizeof(struct Type_));
    spe_type->kind=BASIC;
    spe_type->u.basic=VAR_INT;
    //添加read函数
    struct Symbol_table_item *p = (struct Symbol_table_item *)malloc(sizeof(struct Symbol_table_item));
    p->next_hash_item = NULL;
    p->next_symbol = NULL;
    p->symbol_depth = cur_stack_deep;
    p->f = (FieldList)malloc(sizeof(struct FieldList_));
    p->f->name="read";

    Type t = (Type)malloc(sizeof(struct Type_));
    t->kind = FUNCTION;
    t->u.function.funcType = spe_type;
    t->u.function.paramNum=0;
    t->u.function.params=NULL;
    p->f->type=t;
    add_s_table(p);
    //添加write函数
    struct Symbol_table_item *p2 = (struct Symbol_table_item *)malloc(sizeof(struct Symbol_table_item));
    p2->next_hash_item = NULL;
    p2->next_symbol = NULL;
    p2->symbol_depth = cur_stack_deep;
    p2->f = (FieldList)malloc(sizeof(struct FieldList_));
    p2->f->name="write";

    Type t2 = (Type)malloc(sizeof(struct Type_));
    t2->kind = FUNCTION;
    t2->u.function.funcType = spe_type;
    t2->u.function.paramNum=1;
    t2->u.function.params=(FieldList)malloc(sizeof(struct FieldList_));

    t2->u.function.params->name="params1";
    t2->u.function.params->type=(Type)malloc(sizeof(struct Type_));
    t2->u.function.params->type->kind=BASIC;
    t2->u.function.params->type->u.basic=VAR_INT;
    p2->f->type=t2;
    add_s_table(p2);
}

struct Symbol_table_item * Dec_in_structure(Node node, Type type)
{
    Node child_1 = node->child;//VarDec
    struct Symbol_table_item *p = VarDec(child_1, type);
    p->symbol_depth=STACK_DEEP;//结构体成员变量单独一张表
    if(child_1->bro!= NULL)
    {
        printf("Error type 15 at Line %d: illegal initialization.\n",node->line);
        //结构体变量不允许初始化
    }
    return p;
}


FieldList Def_in_structure(Node node)/*, FieldList temp_field, FieldList head_field*/
{
    /*
        Def -> Specifier DecList SEMI
    */
    Type spe_type = Specifier(node->child);
    Node Dec_List = node->child->bro;
    /*
        DecList -> Dec
        DecList -> Dec COMMA DecList
    */
    struct Symbol_table_item *p = NULL;
    FieldList temp_field = NULL,head_field = NULL;
    //有逗号有变量则循环填表
    while(Dec_List->child->bro != NULL)
    {
        p=Dec_in_structure(Dec_List->child,spe_type);
        //printf("%s %d",p->f->name,p->f->type->kind);
        //print_hash_table();
        if(search_struct_table(p))
        {
            printf("Error type 15 at Line %d: Redefined field \"%s\".\n",node->line,p->f->name);
        }
        else
        {
            //printf("[Def]添加结构体变量\n");
            add_struct_table(p);
            //print_hash_table();
        }
        //与普通def的区别在于：需要把这些结构体变量串起来，类似函数形参
        if(head_field == NULL)
        {
            temp_field = p->f;
            head_field = p->f;
        }
        else
        {
            temp_field->tail = p->f;
            temp_field = p->f;
        }
        Dec_List = Dec_List->child->bro->bro;
    }

    p=Dec_in_structure(Dec_List->child,spe_type);
    // printf("%s %d",p->f->name,p->f->type->kind);
    //print_hash_table();
    if(search_struct_table(p))
    {
        printf("Error type 15 at Line %d: Redefined field \"%s\".\n",node->line,p->f->name);
    }
    else
    {
        //printf("[Def]添加结构体变量\n");
        add_struct_table(p);
        //print_hash_table();
    }

    if(head_field == NULL)
    {
        temp_field = p->f;
        head_field = p->f;
    }
    else
    {
        temp_field->tail = p->f;
        temp_field = p->f;
    }
    return head_field;
}


Type Specifier(Node node)
{
    Type spe_type=(Type)malloc(sizeof(struct Type_));
    if(strcmp(node->child->name,"TYPE")==0){//TYPE
        spe_type->kind=BASIC;
        if(strcmp(node->child->data.var_type,"int")==0)
            spe_type->u.basic=VAR_INT;
        else spe_type->u.basic=VAR_FLOAT;
        return spe_type;
    }
    else
    {
        /*
            StructSpecifier -> STRUCT OptTag LC DefList RC
            StructSpecifier -> STRUCT Tag
        */
        /*
            Tag -> ID
        */
        spe_type->kind=STRUCTURE;
        Node struct_specifier = node->child;
        if(strcmp(struct_specifier->child->bro->name,"Tag")==0)
        {
            //print_hash_table();
            struct Symbol_table_item *p = find_items_s_table(struct_specifier->child->bro->child->data.var_ID);
            if(p == NULL || p->f->type->kind != STRUCTURE)
            {
                printf("Error type 17 at Line %d: Undefined structure \"%s\".\n", node->line, struct_specifier->child->bro->child->data.var_ID);
            }
            else if(p->f->type != NULL)
                return p->f->type;
            spe_type->u.structure_.structure = NULL;
            return spe_type;
        }
        else
        {
            Node def_list = NULL;
            struct Symbol_table_item *p = (struct Symbol_table_item *)malloc(sizeof(struct Symbol_table_item));
            p->next_hash_item = NULL;
            p->next_symbol = NULL;
            p->symbol_depth = cur_stack_deep;
            p->f = (FieldList)malloc(sizeof(struct FieldList_));
            p->f->tail= NULL;
            spe_type->u.structure_.structure = NULL;
            if(strcmp(struct_specifier->child->bro->name, "OptTag")==0)
            {
                p->f->name = struct_specifier->child->bro->child->data.var_ID;
                spe_type->u.structure_.name = p->f->name;
                p->f->type = spe_type;
                if(search_s_table(p))
                {
                    printf("Error type 16 at Line %d: Duplicated name \"%s\".\n",node->line,struct_specifier->child->bro->child->data.var_ID);

                }
                def_list = struct_specifier->child->bro->bro->bro;

            }
            else
            {
                def_list = struct_specifier->child->bro->bro;
                strcat(anonymous_struct_name,"1");
                p->f->name = anonymous_struct_name;
                spe_type->u.structure_.name = anonymous_struct_name;
            }

            //空结构体
            if(strcmp(def_list->name,"DefList")!=0)
            {
                spe_type->u.structure_.structure = NULL;
            }
            else
            {
                FieldList temp_field = NULL;
                FieldList head_field = NULL;
                while(def_list != NULL)
                {
                    FieldList ret_field = Def_in_structure(def_list->child);
                    if(temp_field == NULL)
                    {
                        temp_field = ret_field;
                        head_field = ret_field;
                    }
                    else
                    {
                        while(temp_field->tail!= NULL)
                            temp_field = temp_field->tail;
                        temp_field->tail = ret_field;
                        temp_field = ret_field;
                    }
                    def_list = def_list->child->bro;
                }

                spe_type->u.structure_.structure = head_field;
            }


            p->f->type = spe_type;
            add_s_table(p);
            //printf("%s\n",p->f->name);
            /*FieldList test = p->f->type->u.structure_.structure;
            if(test == NULL)
                printf("aaaaaaaaaaaaaaaaaaaaaaaaa\n");
            while(test != NULL)
            {
                printf("%s\n", test->name);
                test=test->tail;
            }*/

            //printf("[Specifier]添加结构体\n");
            //print_hash_table();
            return spe_type;
        }
    }

}


struct Symbol_table_item *VarDec(Node node, Type type)
{
    //printf("VarDec\n");
    struct Symbol_table_item *p = (struct Symbol_table_item *)malloc(sizeof(struct Symbol_table_item));
    p->next_hash_item = NULL;
    p->next_symbol = NULL;
    p->symbol_depth = cur_stack_deep;
    p->f = (FieldList)malloc(sizeof(struct FieldList_));
    p->f->tail = NULL;
    //Type top = (Type)malloc(sizeof(struct Type_));
    //top->kind = BASIC;
    //top->u.basic = type;
    //先获取该变量名称
    Node VarDec_child_1 = node->child;

    while(VarDec_child_1->child != NULL)
    {
        VarDec_child_1 = VarDec_child_1->child;
    }
    p->f->name=VarDec_child_1->data.var_ID;
    //printf("%s",VarDec_child_1->data.var_ID);
    VarDec_child_1 = node->child;
    //基本类型
    if(strcmp(VarDec_child_1->name, "ID")==0)
    {
        p->f->type = type;
        //printf("exit VarDec\n");
        return p;
    }

    //printf("%d\n",type->kind);
    //数组类型
    Type type_temp[100] = {NULL};
    int next = 0;
    while(VarDec_child_1->child != NULL)
    {

        Type var1=(Type)malloc(sizeof(struct Type_));
        var1->kind = ARRAY;
        var1->u.array.size = VarDec_child_1->bro->bro->data.val_int;
        //printf("%d,%d\n",var1->u.array.size,VarDec_child_1->bro->bro->data.val_int);
        if(next==0)
        {
            var1->u.array.elem = type;
        }
        else
            var1->u.array.elem = type_temp[next-1];
        type_temp[next] = var1;

        next++;
        VarDec_child_1 = VarDec_child_1->child;
        //if(VarDec_child_1->child == NULL)
        //	var1->u.array.elem = type;
    }
    p->f->type = type_temp[next-1];

    /*Type xx = p->f->type;
    while(xx != NULL)
    {
        printf("%d\n", xx->kind);
        if(xx->kind == ARRAY)
            xx =xx->u.array.elem;
        else
            break;
    }*/
    //printf("exit VarDec\n");
    return p;

}


Type Exp(Node node)
{
    /*	Exp -> Exp ASSIGNOP Exp		1
            | Exp AND Exp			1
            | Exp OR Exp			1
            | Exp RELOP Exp			1
            | Exp PLUS Exp			1
            | Exp MINUS Exp			1
            | Exp STAR Exp			1
            | Exp DIV Exp			1
            | LP Exp RP				1
            | MINUS Exp				1
            | NOT Exp				1
            | ID LP Args RP			1
            | ID LP RP				1
            | Exp LB Exp RB			1
            | Exp DOT ID
            | ID					1
            | INT					1
            | FLOAT					1
    */
//printf("[Exp]\n");
//print_hash_table();
//printf("%s\n",node->child->name);
    if(strcmp(node->child->name, "Exp")==0)
    {
        Type type_1 = Exp(node->child);
        if(strcmp(node->child->bro->name, "ASSIGNOP")==0)
        {
            Type type_3 = Exp(node->child->bro->bro);

            //左值三种情况：ID、Exp LB Exp RB、Exp DOT ID
            if(node->child->child->bro == NULL && strcmp(node->child->child->name,"ID")!=0)			// 1个子节点
            {
                printf("Error type 6 at Line %d: The left-hand side of an assignment must be a variable.\n", node->line);

                return NULL;
            }
            else if(node->child->child->bro != NULL && node->child->child->bro->bro != NULL && node->child->child->bro->bro->bro == NULL) //3个子节点
            {
                if(!(strcmp(node->child->child->name,"Exp")==0 && strcmp(node->child->child->bro->name,"DOT")==0 && strcmp(node->child->child->bro->bro->name,"ID")==0))
                {
                    printf("Error type 6 at Line %d: The left-hand side of an assignment must be a variable.\n", node->line);
                    return NULL;
                }
            }
            else if(node->child->child->bro != NULL && node->child->child->bro->bro != NULL &&  node->child->child->bro->bro->bro != NULL && node->child->child->bro->bro->bro->bro == NULL) //4个子节点
            {
                if(!(strcmp(node->child->child->name,"Exp")==0 &&
                     strcmp(node->child->child->bro->name,"LB")==0 &&
                     strcmp(node->child->child->bro->bro->name,"Exp")==0 &&
                     strcmp(node->child->child->bro->bro->bro->name,"RB")==0))
                {
                    printf("Error type 6 at Line %d: The left-hand side of an assignment must be a variable.\n", node->line);
                    return NULL;
                }
            }
            if(check_type(type_1, type_3)==0 && semantic_line != node->line)
            {
                printf("Error type 5 at Line %d: Type mismatched for assignment.\n", node->line);
                return NULL;
            }
            else
                return type_1;
        }
        else if(strcmp(node->child->bro->name, "AND")==0 ||
                strcmp(node->child->bro->name, "OR")==0 ||
                strcmp(node->child->bro->name, "RELOP")==0)
        {
            Type type_3 = Exp(node->child->bro->bro);
            if(check_type(type_1, type_3)==0)
            {
                if(semantic_line==node->line)
                    printf("Error type 7 at Line %d: Type mismatched for operands.\n", node->line);
                return NULL;
            }
            else
            {
                Type type=(Type)malloc(sizeof(struct Type_));
                type->kind=BASIC;
                type->u.basic=VAR_INT;
                return type;
            }
        }
        else if(strcmp(node->child->bro->name, "PLUS")==0 ||
                strcmp(node->child->bro->name, "MINUS")==0 ||
                strcmp(node->child->bro->name, "STAR")==0 ||
                strcmp(node->child->bro->name, "DIV")==0)
        {
            Type type_3 = Exp(node->child->bro->bro);
            if(check_type(type_1, type_3)==0)
            {
                printf("Error type 7 at Line %d: Type mismatched for operands.\n", node->line);

                return NULL;
            }
            else
                return type_1;
        }
        else if(strcmp(node->child->bro->name, "LB")==0)
        {

            Node child_1 = node->child;
            Node child_3 = child_1->bro->bro;
            Type child_1_type = Exp(child_1);
            Type child_3_type = Exp(child_3);
            //printf("%d\n",child_1_type->kind);
            if(child_1_type == NULL)
                return NULL;
            if(child_1_type != NULL && child_1_type->kind != ARRAY)
            {
                printf("Error type 10 at Line %d: Illegal use of \"[]\"\n",node->line);

                return NULL;
            }
            if(child_3_type->kind != BASIC || child_3_type->u.basic == VAR_FLOAT)
            {
                printf("Error type 12 at Line %d: Array index is not an integer.\n",node->line);

                return NULL;
            }

            return child_1_type->u.array.elem;
        }
        else if(strcmp(node->child->bro->name, "DOT")==0)
        {
            Type stru = type_1;

            if(stru == NULL)
                return NULL;
            if(stru->kind != STRUCTURE)
            {
                printf("Error type 13 at Line %d: Illegal use of \".\".\n",node->line);

                return NULL;
            }
            Node id = node->child->bro->bro;
            char *id_name = id->data.var_ID;
            //printf("%s",id_name);

            FieldList temp=stru->u.structure_.structure;
            while(temp!=NULL)
            {
                if(strcmp(temp->name,id_name)==0)
                    return temp->type;
                temp=temp->tail;
            }
            printf("Error type 14 at Line %d: Non-existent field \"%s\".\n",node->line,id_name);

            return NULL;
        }

    }
    else
    {
        if(strcmp(node->child->name, "LP")==0 || strcmp(node->child->name, "MINUS")==0 ||strcmp(node->child->name, "NOT")==0)
        {
            return Exp(node->child->bro);
        }
        if(strcmp(node->child->name, "ID")==0 && node->child->bro == NULL)
        {
            //printf("%s\n",node->child->data.var_ID);
            struct Symbol_table_item *temp = find_items_s_table(node->child->data.var_ID);
            //printf("%d",temp->f->type->u.basic);
            if(temp == NULL)
            {
                printf("Error type 1 at Line %d: Undefined variable \"%s\".\n",node->line,node->child->data.var_ID);
                semantic_line=node->line;
                return NULL;
            }
            else
                return temp->f->type;
        }
        if(strcmp(node->child->name, "INT")==0)
        {
            Type type = (Type)malloc(sizeof(struct Type_));
            type->kind = BASIC;
            type->u.basic = VAR_INT;
            return type;
        }
        if(strcmp(node->child->name, "FLOAT")==0)
        {
            Type type = (Type)malloc(sizeof(struct Type_));
            type->kind = BASIC;
            type->u.basic = VAR_FLOAT;
            return type;
        }
        if(strcmp(node->child->name, "ID")==0 && node->child->bro != NULL)
        {
            //函数调用
            //printf("%s\n",node->name);
            Node id = node->child;
            struct Symbol_table_item *func_item = find_items_s_table(id->data.var_ID);
            if(func_item == NULL)
            {
                printf("Error type 2 at Line %d: Undefined function \"%s\".\n",node->line,id->data.var_ID);

                return NULL;
            }
            if(func_item->f->type->kind != FUNCTION)
            {
                printf("Error type 11 at Line %d: \"%s\" is not a function.\n",node->line, id->data.var_ID);

                return NULL;
            }

            //获取参数列表
            FieldList real_args_type = func_item->f->type->u.function.params;
            if(strcmp(id->bro->bro->name, "Args")==0)
            {
                Node args = id->bro->bro;
                int param_num=1;
                while(args->child->bro != NULL)
                {
                    param_num++;
                    Type args_type = Exp(args->child);
                    if(real_args_type != NULL && !check_type(args_type,real_args_type->type))
                    {
                        printf("Error type 9 at Line %d: Type mismatched for arguments.\n",node->line);
                        return NULL;
                    }
                    args = args->child->bro->bro;
                    real_args_type = real_args_type==NULL?NULL:real_args_type->tail;
                }

                Type args_type = Exp(args->child);
                if(real_args_type != NULL && !check_type(args_type,real_args_type->type))
                {
                    printf("Error type 9 at Line %d: Type mismatched for arguments.\n",node->line);
                    return NULL;
                }

                if(param_num != func_item->f->type->u.function.paramNum)
                {
                    printf("Error type 9 at Line %d: The number of arguments is wrong.\n",node->line);
                    return NULL;
                }
            }
            return func_item->f->type->u.function.funcType;
        }
    }
    return NULL;
}


struct Symbol_table_item *Dec(Node node, Type type)
{
    //printf("[Dec]\n");
    Node child_1 = node->child;//VarDec
    struct Symbol_table_item *p = VarDec(child_1, type);

    if(child_1->bro != NULL)
    {
        Node child_3 = child_1->bro->bro;//Exp
        Type exp_type = Exp(child_3);
        if(check_type(p->f->type, exp_type)==0) {
            if (node->line == semantic_line)
                printf("Error type 5 at Line %d: Type mismatched for assignment.\n", node->line);

        }
        //判断Exp和VarDec类型相等
    }

    return p;
}

void Def(Node node)
{
    /*
        Def -> Specifier DecList SEMI
    */
    //printf("Def");
    Type spe_type = Specifier(node->child);
    //printf("return[Spec]");
    Node Dec_List = node->child->bro;
    /*
        DecList -> Dec
        DecList -> Dec COMMA DecList
    */
    struct Symbol_table_item *p = NULL;
    //有逗号有变量则循环填表
    while(Dec_List->child!= NULL)
    {
        p=Dec(Dec_List->child,spe_type);
        //printf("1");
        if(search_s_table(p)) {
            printf("Error type 3 at Line %d: Redefined variable \"%s\".\n", node->line, p->f->name);
        }
        else
        {
            //printf("[Def]添加局部变量: %s\n",p->f->name);
            add_s_table(p);
            //print_hash_table();
        }
        if (Dec_List->child->bro)
            Dec_List = Dec_List->child->bro->bro;
        else
            break;
        //Dec_List = Dec_List->child->bro;
    }

    p=Dec(Dec_List->child,spe_type);
    //printf("%d\n",p->symbol_depth);
    if(search_s_table(p)) {
        if (node->line == semantic_line)
            printf("Error type 3 at Line %d: Redefined variable \"%s\".\n", node->line, p->f->name);
    }
    else
    {
        //printf("[Def]添加局部变量: %s\n",p->f->name);
        add_s_table(p);
        //print_hash_table();
    }
}

/*
Stmt: Exp SEMI
    | CompSt
    | RETURN Exp SEMI
    | IF LP Exp RP Stmt %prec LOWER_THAN_ELSE
    | IF LP Exp RP Stmt ELSE Stmt
    | WHILE LP Exp RP Stmt
    | IF LP error RP Stmt %prec LOWER_THAN_ELSE
    | IF LP error RP Stmt ELSE Stmt
    | WHILE LP error RP Stmt
 */
void Stmt(Node node, Type function_type)
{
    if(strcmp(node->child->name,"Exp")==0)
        Exp(node->child);
    else if(strcmp(node->child->name,"CompSt")==0)
        CompSt(node->child, function_type);
    else if(strcmp(node->child->name,"RETURN")==0)
    {
        Type ret_type = Exp(node->child->bro);

        if(!check_type(function_type, ret_type))
            printf("Error type 8 at Line %d: Type mismatched for return.\n",node->line);
    }
    else if(strcmp(node->child->name,"IF")==0)
    {
        Node exp = node->child->bro->bro;
        Node stmt = exp->bro->bro;
        Exp(exp);
        Stmt(stmt, function_type);
        if(stmt->bro != NULL)
            Stmt(stmt->bro->bro, function_type);
    }
    else if(strcmp(node->child->name,"WHILE")==0)
    {
        Node exp = node->child->bro->bro;
        Node stmt = exp->bro->bro;
        Exp(exp);
        Stmt(stmt, function_type);

    }
}


void CompSt(Node node, Type function_type)
{
    /*
        CompSt -> LC DefList StmtList RC
    */
    //printf("[Compst]\n");
    Node CompSt_child_1 = node->child;//LC
    cur_stack_deep++;
    //print_hash_table();
    Node CompSt_child_2 = CompSt_child_1->bro;//DefList
    Node CompSt_child_3 = CompSt_child_2->bro;//StmtList
    if(strcmp(CompSt_child_2->name,"DefList")==0)//DefList不为空
    {
        if(strcmp(CompSt_child_3->name,"StmtList")!=0)
            CompSt_child_3 = NULL;
    }
    else
    {
        CompSt_child_3 = CompSt_child_2;
        CompSt_child_2 = NULL;
        if(strcmp(CompSt_child_3->name,"StmtList")!=0)
            CompSt_child_3 = NULL;
    }

    /*
        DefList -> Def DefList
        DefList -> ε
    */

    while(CompSt_child_2 != NULL)
    {
        //printf("[CompSt]DefList\n");
        Def(CompSt_child_2->child);
        //printf("from [Def]");
        CompSt_child_2 = CompSt_child_2->child->bro;
    }
    /*
        StmtList -> Stmt StmtList
        StmtList -> ε
    */

    while(CompSt_child_3 != NULL)
    {
        //printf("[CompSt]Stmt\n");
        Stmt(CompSt_child_3->child, function_type);
        CompSt_child_3 = CompSt_child_3->child->bro;
    }
    //print_hash_table();
    //退出大括号，删除该作用域的全部符号
//    struct Symbol_table_item *temp = stack[cur_stack_deep];
//
//    while(temp != NULL)
//    {
//        struct Symbol_table_item *t = temp;
//        temp = temp->next_symbol;
//        del_s_table(t);
//    }
//
//    stack[cur_stack_deep] = NULL;
//    cur_stack_deep--;
}



void ExtDef(Node node)
{
    /*
        ExtDef -> Specifier ExtDecList SEMI
          ExtDef -> Specifier SEMI
          ExtDef -> Specifier FunDec CompSt
    */
    //printf("ExtDef\n");
    Node child_1 = node->child; //Specifier
    Type spe_type =Specifier(child_1);
    Node child_2 = child_1->bro;//ExtDecList或FunDec
    if(strcmp(child_2->name,"ExtDecList")==0)//全局变量定义
    {
        //char *type_name[100];
        //strcpy(type_name, child_1->child->text);

        Node ExtDec_List = child_2;
        struct Symbol_table_item *p = NULL;
        //有逗号有变量则循环填表
        while(ExtDec_List->child->bro != NULL)
        {
            p=VarDec(ExtDec_List->child,spe_type);
            if(search_s_table(p))
                printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",node->line,p->f->name);
            else
            {
                //printf("[ExtDef]添加全局变量\n");
                add_s_table(p);
                //print_hash_table();
            }

            ExtDec_List = ExtDec_List->child->bro->bro;
        }

        p=VarDec(ExtDec_List->child,spe_type);
        if(search_s_table(p))
            printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",node->line,p->f->name);
        else
        {
            //printf("[ExtDef]添加全局变量\n");
            add_s_table(p);
            //print_hash_table();
        }
    }
    else if(strcmp(child_2->name,"FunDec")==0)//函数定义
    {
        /*
            FunDec -> ID LP VarList RP
            FunDec -> ID LP RP
        */
        //处理函数头
        struct Symbol_table_item *p = (struct Symbol_table_item *)malloc(sizeof(struct Symbol_table_item));
        p->next_hash_item = NULL;
        p->next_symbol = NULL;
        p->symbol_depth = cur_stack_deep;
        p->f = (FieldList)malloc(sizeof(struct FieldList_));

        p->f->name = child_2->child->data.var_ID;
        Type t = (Type)malloc(sizeof(struct Symbol_table_item));
        t->kind = FUNCTION;
        t->u.function.funcType = spe_type;
        t->u.function.paramNum=0;
        t->u.function.params=NULL;

        if(strcmp(child_2->child->bro->bro->name, "VarList")==0)
        {
            struct node *Var_List = child_2->child->bro->bro;

            cur_stack_deep++;

            struct Symbol_table_item *pp = NULL;
            //有多个参数则循环填表
            int par_num=1;
            FieldList field_root = NULL;
            FieldList temp_field = NULL;
            while(Var_List->child->bro != NULL)
            {
                par_num++;
                struct node *Param_Dec = Var_List->child;
                Type spe_type_1 = Specifier(Param_Dec->child);
                pp=VarDec(Param_Dec->child->bro,spe_type_1);
                if(search_s_table(pp))
                    printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",node->line,p->f->name);
                else
                {
                    //printf("[ExtDef]添加函数形参\n");
                    if(temp_field == NULL)
                    {
                        field_root = pp->f;
                        temp_field = pp->f;
                    }
                    else
                    {
                        temp_field -> tail = pp->f;
                        temp_field = pp->f;
                    }
                    add_s_table(pp);
                    //print_hash_table();
                }
                Var_List = Var_List->child->bro->bro;
            }


            struct node *Param_Dec = Var_List->child;
            Type spe_type_1 = Specifier(Param_Dec->child);
            pp=VarDec(Param_Dec->child->bro,spe_type_1);
            if(search_s_table(pp))
                printf("6Error type 3 at Line %d: Redefined variable \"%s\".\n",node->line,p->f->name);
            else
            {
                //printf("[ExtDef]添加函数形参\n");
                add_s_table(pp);
                if(temp_field == NULL)
                {
                    temp_field = pp->f;
                    field_root = pp->f;
                }
                else
                {
                    temp_field -> tail = pp->f;
                    temp_field = pp->f;
                }
                //print_hash_table();
            }

            //由于函数体还要用到，因此不删除此层符号表
            //cur_stack_deep--;
            t->u.function.params = field_root;
            t->u.function.paramNum=par_num;
        }

        p->f->type = t;
        if(search_s_table(p))
            printf("Error type 4 at Line %d: Redefined function \"%s\".\n",node->line,p->f->name);
        else
        {
            //printf("[ExtDef]添加全局函数\n");
            add_s_table(p);
            //print_hash_table();
        }

        //处理函数体
        //printf("处理函数体\n");
        Node child_3 = child_2->bro;//CompSt
        CompSt(child_3, p->f->type->u.function.funcType);//传入函数返回值类型

    }
    else //无意义或结构体定义
    {

    }
}

void traverse(Node this_node,int depth)
{
    if(this_node == NULL)
        return;

    if(strcmp(this_node->name,"ExtDef")==0)
        ExtDef(this_node);

    traverse(this_node->child,depth+1);
    traverse(this_node->bro,depth);
}
