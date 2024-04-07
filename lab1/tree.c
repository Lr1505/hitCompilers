//
// Created by LR0515 on 24-4-2.
//
#include "tree.h"
void print_tree(struct node* mnode, int depth)  // 打印AST，depth表示深度
{
    if(mnode==NULL) return;
    for(int i=0;i<depth;i++)
        printf("  ");
    printf("%s",mnode->name);
    if(mnode->tokenFlag){
        switch (mnode->datatype) {
            case TYPE_ID:
                printf(": %s", mnode->data.var_ID);
                break;
            case TYPE_TYPE:
                printf(": %s", mnode->data.var_type);
                break;
            case TYPE_FLOAT:
                printf(": %.6f", mnode->data.val_float);
                break;
            case TYPE_INT:
                printf(": %u", mnode->data.val_int);
                break;
            default:
                break;
        }
    }
    else{
        printf(" (%d)",mnode->line);
    }
    printf("\n");
    print_tree(mnode->child,depth+1);
    print_tree(mnode->bro,depth);
}
struct node* token_node(const char* name, enum DATATYPE datatype,const char* val)
{
    struct node* mnode = (struct node*)malloc(sizeof(struct node));
    mnode->tokenFlag = 1;
    mnode->bro = NULL;
    mnode->child = NULL;
    mnode->datatype = datatype;
    sscanf(name, "%s", mnode->name);
    switch (mnode->datatype) {
        case TYPE_ID:
            sscanf(val, "%s", mnode->data.var_ID);
            break;
        case TYPE_TYPE:
            sscanf(val, "%s", mnode->data.var_type);
            break;
        case TYPE_FLOAT:
            sscanf(val, "%f", &mnode->data.val_float);
            break;
        case TYPE_INT:
            sscanf(val, "%u", &mnode->data.val_int);
            break;
        case TYPE_OCT:
            sscanf(val, "%o", &mnode->data.val_int);
            mnode->datatype = TYPE_INT;
            break;
        case TYPE_HEX:
            sscanf(val, "%x", &mnode->data.val_int);
            mnode->datatype = TYPE_INT;
            break;
        default:
            break;
    }
    return mnode;
}
struct node* nonterminal_node(const char* name, int line, int node_num,...)  // 添加非终结符结点，说明名称，以及列值
{
    struct node* mnode = (struct node*)malloc(sizeof(struct node));
    mnode->bro = NULL;
    mnode->child = NULL;
    mnode->line = line;
    mnode->tokenFlag = 0;
    sscanf(name, "%s", mnode->name);
    va_list valist;// va_list表示可变参数列表类型，实际上就是一个char指针
    va_start(valist, node_num);//初始化,获取函数参数列表中可变参数的首指针(获取函数可变参数列表)
    set_parent_brother(mnode, node_num, valist);
    va_end(valist);//结束对可变参数的处理。
    return mnode;
}
void set_parent_brother(struct node* parent, int node_num,va_list valist)//采用左儿子右兄弟方法，使生成的AST为二叉树格式
{
    struct node* node;
    int i=0;
    for (; i < node_num; i++) {
        node = va_arg(valist, struct node*);//返回当前指向的参数类型，node*,获取当前ap所指的可变参数并将并将ap指针移向下一可变参数
        if (node != NULL) break;
    }
    ++i;
    parent->child = node;
    for (; i < node_num; i++) {
        if ((node->bro = va_arg(valist, struct node*)) != NULL) node = node->bro;
    }
}