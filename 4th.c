/*
Design, Develop and Implement a Program in C for converting an Infix Expression to Postfix
Expression. Program should support for both parenthesized and free parenthesized expressions with
the operators: +, -, *, /, %( Remainder), ^ (Power) and alphanumeric operands.
*/

/*
ALGORITHM:
Step 1: Start.
Step 2: Read an infix expression with parenthesis and without parentesis.
Step 3: convert the infix expression to postfix expression.
Step 4: stop.
*/


#include<stdio.h>
#include<string.h>

int F(char symbol){
    switch(symbol){
        case '+':
        case '-': return 2;
                

        case '*':
        case '/': return 4;
                
        case '^':
        case '$': return 5;

        case '(': return 0;

        case '#': return -1;

        default: return 8;
    }
}

int G(char symbol){
    switch(symbol){
        case '+':
        case '-': return 1;

        case '*':
        case '/': return 3;

        case '^':
        case '$': return 6;

        case '(': return 9;
        
        case ')': return 0;

        default: return 7;
    }
}

void infix_postfix(char infix[], char postfix[]){
    int top = -1, i, j = 0;
    char s[30], symbol;
    s[++top] = '#';
    
    for(i=0; i<strlen(infix); i++){
        symbol = infix[i];
        while(F(s[top]) > G(symbol)){
            postfix[j] = s[top--];
            j++;
        }
        if(F(s[top]) != G(symbol)){
            s[++top] = symbol;
        }
        else{
            top--;
        }
    }
    while(s[top] != '#'){
        postfix[j++] = s[top--];
    }
    postfix[j] = '\0';
}

void main(){
    char infix[20], postfix[20];
    printf("\n enter a valid infix expression \n");
    gets(infix);
    infix_postfix(infix, postfix);
    printf("\n the infix expression is: \n");
    printf("%s", infix);
    printf("\n the postfix expression is: \n");
    printf("%s", postfix);
}