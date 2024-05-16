#include <stdio.h>

#include "tree.h"
#include "syntax.tab.h"
#include "semantic.h"
#include "translate.h"

extern FILE *yyin;                        // This is the file pointer from which the lexer reads its input.
int lexical_errs = 0;              // 出现的词法错误
int syntax_errs = 0;               // 出现的语法错误
int semantic_line = 0;
extern int translate_correct;
extern int yydebug;                // bison debug mode
extern YYSTYPE yylval;                    // 存储终结符的语义值
struct node *root;             // AST语法树的根结点
int yylex();                       // 词法分析的接口
int yyparse(void);                 // 语法分析的接口
void yyrestart(FILE *input_file);  // 将yyin指针重置

int main(int argc, char **argv) {
    yydebug = 0;
    if(argc <= 1)
    {
        yyparse();
        return 1;
    }
    FILE* f = fopen(argv[1], "r");
    if (!f)
    {
        perror(argv[1]);
        return 1;
    }
    FILE* fp = fopen(argv[2], "wt+");
    if (!fp)
    {
        perror(argv[2]);
        return 1;
    }
    yyrestart(f);
    yyparse();
    if (lexical_errs || syntax_errs) {
        /* meet erros */
        if (yydebug) printf("totally meet %d lexical errors and %d syntax errors\n", lexical_errs, syntax_errs);
    } else {
        /* Print the AST tree */
        //print_tree(root, 0);
        init_table();
        traverse(root,0);
        //print_hash_table();
        traverse_gen_intercode(root);
        if(translate_correct)
            //print_intercode();
            print_intercode_to_file(fp);
    }
    return 0;
}
//int main(int argc, char **argv) {
//    // yydebug = 1;
//    if (argc == 1) return 1;
//    if (argc > 1) {
//        if (!(yyin = fopen(argv[1], "r"))) {
//            perror(argv[1]);
//            return 1;
//        }
//    }
//    yylex();
//    return 0;
//}