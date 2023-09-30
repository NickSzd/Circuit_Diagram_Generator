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
        // If expr[i] is (, [, { push into the stack
        if(expr[i] == '[' ||expr[i] == '(' || expr[i] == '{' ){
            //printf("PUSH: %c\n", expr[i]);
            push(&myStack, expr[i]);
            // printf("Pushed: %c\n",peek(myStack));
            // Display(myStack);
            
        } // if the stack is empty and expr[i] is a closing symbol then return false
        else if(isEmpty(myStack) && (expr[i] == '}' || expr[i] == ')' || expr[i] == ']')){
            //printf("IsEmpty Error\n");
            return false;
        } // if the closing symbol does not match the opening symbol return false
        else if(((expr[i] == '}' && peek(myStack) != '{') || (expr[i] == ']' && peek(myStack) != '[')  || (expr[i] == ')' && peek(myStack) != '(') )){
            // Display(myStack);
            // printf("PEEK: %c\n", peek(myStack));
            // printf("Incorrect closing error\n");
            return false;
        } 
        else if(((expr[i] == '}' && peek(myStack) == '{') || (expr[i] == ']' && peek(myStack) == '[')  || (expr[i] == ')' && peek(myStack) == '(') )){
            pop(&myStack);
        }
        
    }
    
    return isEmpty(myStack);
}

int main(){
    char buffer[STACK_SIZE];
    Token tokens[50];

    printf(" ' is NOT \n . is AND \n + is OR\n");

    printf("Enter in Your Equation: ");

    scanf("%s", buffer);

    if(strlen(buffer) > STACK_SIZE){
        perror("BUFFER SIZE EXCEEDED");
        return 1;
    }

    printf("You have entered: %s\n", buffer);
    printf("%zu\n", strlen(buffer));
    if(validate_Expression(buffer))
        printf("Valid Expression\n");
    else{
        printf("Invalid Expression\n");
        return 1;
    }
    
    int tokenCount = tokenize(buffer, tokens, sizeof(tokens) / sizeof(tokens[0]));
    if(tokenCount >= 0){
        printf("Tokens:\n");
        for (int i = 0; i < tokenCount; i++) {
            printf("Type: %d, Value: %s\n", tokens[i].type, tokens[i].value);
        }
    }
    else{
        perror("Invalid Operator");
        return 1;
    }

    return 0;
}