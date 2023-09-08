#include<stdio.h>
#include <stdbool.h>
#include<string.h>
#include "stack.h"
#include "token.h"
bool validate_Expression(char* expr){
    if(strlen(expr) == 0)return false; // if string is of length 0

    // Check if there are the correct number of parenthesis
    stack myStack;
    initStack(&myStack);

    for(int i = 0; i < strlen(expr);i++){
        if(expr[i] == '[' ||expr[i] == '(' || expr[i] == '{' ){
            //printf("PUSH: %c\n", expr[i]);
            push(&myStack, expr[i]);
            //Display(myStack);
        }
        if(expr[i] == ']' ||expr[i] == ')' || expr[i] == '}' ){
            //printf("POP: %c\n", expr[i]);
            pop(&myStack);
        }
        else{
            printf("ITEM: %c\n", expr[i]);
        }
    }
    if(isEmpty(myStack))
        return true;
    return false;
}

int main(){
    char buffer[STACK_SIZE];
    Token tokens[50];

    printf(" ' is NOT \n . is AND \n + is OR\n");

    printf("Enter in Your Equation: ");

    scanf("%s", buffer);

    printf("You have entered: %s\n", buffer);
    printf("%zu\n", strlen(buffer));
    if(validate_Expression(buffer))
        printf("Valid Expression\n");
    else
        return 1;
    
    int tokenCount = tokenize(buffer, tokens, sizeof(tokens) / sizeof(tokens[0]));

    printf("Tokens:\n");
    for (int i = 0; i < tokenCount; i++) {
        printf("Type: %d, Value: %s\n", tokens[i].type, tokens[i].value);
    }

    return 0;
}