%{
#include "syntax.tab.h"
#include "tree.h"
extern int lexical_errs;
extern int syntax_errs;
void add_token_node(const char* name, enum DATATYPE datatype, const char* val);
void lexical_error_handler(char *msg);
int yycolumn = 1;
extern int yyerr_line;
extern int yydebug;
extern YYSTYPE yylval;
#define YY_USER_ACTION \
    yylloc.first_line = yylloc.last_line = yylineno; \
    yylloc.first_column = yycolumn; \
    yylloc.last_column = yycolumn + yyleng - 1; \
    yycolumn += yyleng;
int yylex();
%}

%option yylineno

TYPE int|float
SEMI ;
COMMA ,
RELOP >|<|>=|<=|==|!=
ASSIGNOP =
PLUS "+"
MINUS -
STAR "*"
DIV "/"
AND &&
OR \|\|
DOT \.
NOT !
LP \(
RP \)
LB \[
RB \]
LC \{
RC \}
STRUCT struct
RETURN return
IF if
ELSE else
WHILE while

INT   0|([1-9][0-9]*)
INTERROR [0-9]+[a-wA-Wy-zY-Z]+[0-9a-dA-Df-zF-Z]*|[0-9]+[0-9]+[a-dA-Df-zF-Z]+[0-9]*[0-9a-dA-Df-zF-Z]*

OCT 0[0-7]+
OCTERROR 0[0-7]*[8-9]+[0-9]*
HEX 0[xX][0-9a-fA-F]+
HEXERROR 0[xX][0-9a-fA-F]*[g-zG-Z]+[0-9a-zA-Z]*

letter_ [A-Za-z_]
digit [0-9]
digits [0-9]+
FLOAT   {digits}\.{digits}|(\.{digits}|{digits}\.|{digits}\.{digits}|{digits})([eE][+-]?{digits})?
FLOATERROR ({digits}\.{digits}|\.{digits}|{digits}\.|{digits})([eE][+-]?({digits}\.{digits}|\.{digits}|{digits}\.|{digits})?)
ID {letter_}({letter_}|{digit})*
WhiteSpace  [ \t\f\r\v]+

%x INLINE_COMMENT

%%
"/*" {
    char c;
    int meet = 0;
    int flag = 0;
    while((c=input())!='\0'){
        if(c==EOF) break;
        else if(c=='*') meet=1;
        if(meet) {
            if(c=='/') {flag=1; break;}
            else if(c!='*') meet=0;
        }
    }
    if(!flag) {syntax_errs++;yyerr_line=yylineno;printf("Error type B at Line %d: Syntax error.\n",yylineno);}
}
    /* Inline Comments */
"*/"                                {syntax_errs++;yyerr_line=yylineno;printf("Error type B at Line %d: Syntax error.\n",yylineno);}
"//"                                { BEGIN(INLINE_COMMENT); }
<INLINE_COMMENT>[^\n]*              {}
<INLINE_COMMENT>\n                  { BEGIN(INITIAL); }

{SEMI}                              { add_token_node("SEMI", OTHER, NULL);return (SEMI); }
{COMMA}                             { add_token_node("COMMA", OTHER, NULL);return (COMMA); }
{RELOP}                             { add_token_node("RELOP", OTHER, NULL);return (RELOP); }
{ASSIGNOP}                          { add_token_node("ASSIGNOP", OTHER, NULL);return (ASSIGNOP); }
{PLUS}                              { add_token_node("PLUS", OTHER, NULL);return (PLUS); }
{MINUS}                             { add_token_node("MINUS", OTHER, NULL);return (MINUS); }
{STAR}                              { add_token_node("STAR", OTHER, NULL); return (STAR); }
{DIV}                               { add_token_node("DIV", OTHER, NULL); return (DIV);}
{AND}                               { add_token_node("AND", OTHER, NULL);return (AND); }
{OR}                                { add_token_node("OR", OTHER, NULL);return (OR); }
{DOT}                               { add_token_node("DOT", OTHER, NULL);return (DOT); }
{NOT}                               { add_token_node("NOT", OTHER, NULL);return (NOT); }
{TYPE}                              { add_token_node("TYPE", TYPE_TYPE, yytext);return (TYPE); }
{LP}                                { add_token_node("LP", OTHER, NULL);return (LP); }
{RP}                                { add_token_node("RP", OTHER, NULL);return (RP); }
{LB}                                { add_token_node("LB", OTHER, NULL);return (LB); }
{RB}                                { add_token_node("RB", OTHER, NULL);return (RB); }
{LC}                                { add_token_node("LC", OTHER, NULL);return (LC); }
{RC}                                { add_token_node("RC", OTHER, NULL);return (RC); }
{STRUCT}                            { add_token_node("STRUCT", OTHER, NULL);return (STRUCT); }
{RETURN}                            { add_token_node("RETURN", OTHER, NULL);return (RETURN); }
{IF}                                { add_token_node("IF", OTHER, NULL);return (IF); }
{ELSE}                              { add_token_node("ELSE", OTHER, NULL);return (ELSE); }
{WHILE}                             { add_token_node("WHILE", OTHER, NULL);return (WHILE); }
{INT}                               { add_token_node("INT", TYPE_INT, yytext);return (INT); }
{INTERROR}                          { lexical_error_handler("illegal int");}
{OCT}                               { add_token_node("INT", TYPE_OCT, yytext);return (INT); }
{OCTERROR}                          { lexical_error_handler("illegal octal number");}
{HEX}                               { add_token_node("INT", TYPE_HEX, yytext);return (INT); }
{HEXERROR}                          { lexical_error_handler("illegal hexadecimal number");}
{FLOAT}                             { add_token_node("FLOAT", TYPE_FLOAT, yytext);return (FLOAT); }
{FLOATERROR}                        { lexical_error_handler("illegal floating point number");}
{ID}                                { add_token_node("ID", TYPE_ID, yytext);return (ID); }
<<EOF>>                             { return 0; }
"\n"                                { yycolumn = 1; }
{WhiteSpace}                        {}
.                                   { lexical_error_handler("Mysterious characters"); }

%%

void lexical_error_handler(char *msg){
    if(yyerr_line==yylineno)return;
    yyerr_line=yylineno;
    lexical_errs++;
    printf("Error type A at Line %d: %s \"%s\".\n", yylineno, msg ,yytext);
}
void add_token_node(const char* name, enum DATATYPE datatype, const char* val)
{
    yylval.node = token_node(name, datatype, val);
    if(yydebug) print_tree(yylval.node,0);
}