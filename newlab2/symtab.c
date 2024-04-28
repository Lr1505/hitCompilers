#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "symtab.h"

struct Symbol_table_item *s_table[HASH_TABLE_SIZE] = {NULL};//hashtable
struct Symbol_table_item *struct_table[HASH_TABLE_SIZE] = {NULL};
struct Symbol_table_item *stack[STACK_DEEP] = {NULL};
struct Symbol_table_item *cur_depth_symbol[STACK_DEEP] = {NULL};

int cur_stack_deep=0;

void print_hash_table()
{
    printf("---------------hash_table----------------\n");
    for(int i=0;i<HASH_TABLE_SIZE;i++)
    {
        if(s_table[i] != NULL)
        {
            printf("[%d]  ",i);
            struct Symbol_table_item *temp=s_table[i];
            int num=0;
            while(temp!=NULL)
            {
                if(num == 10)
                    break;
                printf("%s %d -> ",temp->f->name, temp->symbol_depth);
                temp=temp->next_hash_item;
                num++;
            }
            printf("\n");
        }
    }
    printf("---------------end----------------\n");
}

unsigned int hash(char* name)
{
    unsigned int val = 0, i;
    for (; *name; ++name)
    {
        val = (val << 2) + *name;
        if (i = val & ~0x3fff)
            val = (val ^ (i >> 12)) & 0x3fff;
    }
    return val%HASH_TABLE_SIZE;
}

//查找表项
struct Symbol_table_item *find_items_s_table(char *name)
{
    int index = hash(name);
    if(s_table[index] == NULL)
        return NULL;
    else
    {
        struct Symbol_table_item* temp = s_table[index];
        while(temp != NULL)
        {
            if(strcmp(temp->f->name,name)==0)
                return temp;
            temp = temp->next_hash_item;
        }
        return NULL;
    }
}

//查看是否有冲突,查重定义
int search_s_table(struct Symbol_table_item *p)
{
    int index = hash(p->f->name);
//printf("%d",index);
    if(s_table[index] == NULL)
        return 0;
    else
    {
        struct Symbol_table_item* temp = s_table[index];
        //printf("%d,%d\n", temp->symbol_depth,cur_stack_deep);
        while(temp != NULL)
        {
            if(strcmp(temp->f->name,p->f->name)==0 && temp->symbol_depth == cur_stack_deep)
            {
                if(temp->f->type->kind == FUNCTION && p->f->type->kind == FUNCTION)
                    return 1;
                else if((temp->f->type->kind>=0 && temp->f->type->kind<=2) &&
                        (p->f->type->kind>=0 && p->f->type->kind<=2))
                    return 1;
            }
            else if(strcmp(temp->f->name,p->f->name)==0 && temp->symbol_depth != cur_stack_deep)
            {
                if(temp->f->type->kind == STRUCTURE)
                    return 1;
            }
            temp = temp->next_hash_item;
        }
        return 0;
    }
}

//填表，默认没有重名
void add_s_table(struct Symbol_table_item *p)
{

    int index = hash(p->f->name);

    //十字连表，当前作用域指针
    if(stack[cur_stack_deep] == NULL)
    {
        cur_depth_symbol[cur_stack_deep] = p;
        stack[cur_stack_deep] = p;
    }
    else
    {
        cur_depth_symbol[cur_stack_deep]->next_symbol = p;
        cur_depth_symbol[cur_stack_deep] = p;
    }

    //填表，有重复键值则插入头部
    if(s_table[index] == NULL)
        s_table[index]=p;
    else
    {
        //printf("重复\n");
        struct Symbol_table_item *temp = s_table[index];
        p->next_hash_item = temp;
        s_table[index]=p;
    }
}

int search_struct_table(struct Symbol_table_item *p)
{
    int index = hash(p->f->name);
    if(struct_table[index] == NULL)
        return 0;
    else
    {
        struct Symbol_table_item* temp = struct_table[index];
        while(temp != NULL)
        {
            if(strcmp(temp->f->name,p->f->name)==0)
            {
                if(temp->f->type->kind == FUNCTION && p->f->type->kind == FUNCTION)
                    return 1;
                else if((temp->f->type->kind>=0 && temp->f->type->kind<=2) &&
                        (p->f->type->kind>=0 && p->f->type->kind<=2))
                    return 1;
            }
            temp = temp->next_hash_item;
        }
        return 0;
    }
}

void add_struct_table(struct Symbol_table_item *p)
{
    int index = hash(p->f->name);

    if(struct_table[index] == NULL)
        struct_table[index]=p;
    else
    {
        //printf("重复\n");
        struct Symbol_table_item *temp = struct_table[index];
        p->next_hash_item = temp;
        struct_table[index]=p;
    }
}
void del_s_table(struct Symbol_table_item *p)
{

    int index = hash(p->f->name);
    struct Symbol_table_item *cur=s_table[index];
    struct Symbol_table_item *last=s_table[index];

    while(cur != p)
    {
        last = cur;
        cur = cur->next_hash_item;
    }
    last->next_hash_item = cur->next_hash_item;
    if(cur != s_table[index])
        free(cur);
    else if(cur == s_table[index] && cur->next_hash_item == NULL)
        s_table[index] = NULL;
    else if(cur == s_table[index] && cur->next_hash_item != NULL)
        s_table[index] = cur->next_hash_item;
}


int check_type(Type type1, Type type2)//正确1  错误0
{
    if(type1 == NULL && type2 == NULL)
        return 1;
    else if(type1 == NULL || type2 == NULL)
    {
        //printf("NULL\n");
        return 0;
    }
    if(type1->kind != type2->kind)
        return 0;
    else
    {
        if(type1->kind == BASIC)//均为基本类型
        {
            if(type1->u.basic != type2->u.basic)
                return 0;
            else
                return 1;
        }
        if(type1->kind == ARRAY)
        {
            if(check_type(type1->u.array.elem,type2->u.array.elem)==0)
                return 0;
            else return 1;
        }
        if(type1->kind == STRUCTURE)
        {
            if(strcmp(type1->u.structure_.name, type2->u.structure_.name)==0)
                return 1;
            else return 0;
        }
        /*if(type1->kind == FUNCTION)
        {

        }
*/
    }
}


