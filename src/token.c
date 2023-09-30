#include "token.h"
#include <ctype.h>
#include <stdio.h>


int tokenize(const char* expr, Token tokens[], int numTokens){
    int tokenCount = 0;
    int exprLen = strlen(expr);
    int i = 0;

    while(i < exprLen){
         // checks if it is a white space
        if(isspace(expr[i])) i++;

        // checks if the char is a letter
        if(isalpha(expr[i])){
            int j = 0;
            while(isalpha(expr[i])){
                tokens[tokenCount].value[j++] = expr[i++];
            }
            tokens[tokenCount].value[j] = '\0';
            tokens[tokenCount++].type = TOKEN_VAR;
        }

        // Check for NOT
        else if(expr[i] == '\'' ){
            tokens[tokenCount].value[0] = expr[i++];
            tokens[tokenCount].value[1] = '\0';
            tokens[tokenCount].type = NOT_OPERATOR;
        }

        // Check for AND
        else if(expr[i] == '.'){
            tokens[tokenCount].value[0] = expr[i++];
            tokens[tokenCount].value[1] = '\0';
            tokens[tokenCount].type = AND_OPERATOR;
        }

        // Check for OR
        else if(expr[i] == '+'){
            tokens[tokenCount].value[0] = expr[i++];
            tokens[tokenCount].value[1] = '\0';
            tokens[tokenCount].type = OR_OPERATOR;
        }

        // Check for Parenthesis
        else if(expr[i] == '('){
            tokens[tokenCount].value[0] = expr[i++];
            tokens[tokenCount].value[1] = '\0';
            tokens[tokenCount].type = TOKEN_LEFT_PAREN;
        }
        else if(expr[i] == ')'){
            tokens[tokenCount].value[0] = expr[i++];
            tokens[tokenCount].value[1] = '\0';
            tokens[tokenCount].type = TOKEN_RIGHT_PAREN;
        }

        // Check for Brackets
        else if(expr[i] == '['){
            tokens[tokenCount].value[0] = expr[i++];
            tokens[tokenCount].value[1] = '\0';
            tokens[tokenCount].type = TOKEN_LEFT_BRACKET;
        }
        else if(expr[i] == ']'){
            tokens[tokenCount].value[0] = expr[i++];
            tokens[tokenCount].value[1] = '\0';
            tokens[tokenCount].type = TOKEN_RIGHT_BRACKET;
        }
        // Unknown
        else{
            return -1;
        }

    }
    return tokenCount;
}