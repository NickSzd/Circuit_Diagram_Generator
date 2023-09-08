#include <string.h>
#include <ctype.h>

// Token Types
typedef enum {
    TOKEN_LETTER,
    TOKEN_VAR, // Variable
    OR_OPERATOR, // Or Operator
    AND_OPERATOR, // And Operator
    NOT_OPERATOR, // Not Operator
    TOKEN_LEFT_PAREN,
    TOKEN_RIGHT_PAREN,
    TOKEN_LEFT_BRACKET,
    TOKEN_RIGHT_BRACKET
} tokenType ;

// Token

typedef struct {
    tokenType type;
    char value[256];
}Token ;

int tokenize(const char* expr, Token tokens[], int numTokens);