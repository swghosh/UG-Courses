%{
int a = 0;
%}

%%
[ ] a++;
%%

int main() {
yylex();
printf("Spaces = %d \n", a);
return 0;
}
