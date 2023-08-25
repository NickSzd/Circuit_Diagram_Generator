#include <string.h>
#include <ctype.h>

// Token Types
typedef enum {
    TOKEN_LETTER,
    TOKEN_VAR,
    TOKEN_OPERATOR,
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