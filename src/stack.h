#include<stdbool.h>
#define STACK_SIZE 256
typedef struct{
    char c_stack[STACK_SIZE];
    int position;
} stack;

void initStack(stack *s);

void Display(stack s);

void push(stack *s, char item);

char pop(stack *s);

char peek(stack s);

bool isEmpty(stack s);