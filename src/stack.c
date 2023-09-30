#include "stack.h"
#include<stdbool.h>
#include <stdio.h>
#include <string.h>

void push(stack *s, char item){
    if(s->position < STACK_SIZE){
        s->position++;
        s->c_stack[s->position] = item;
    }else{
        return; // To do Make Error and return safely
    }
}

char pop(stack *s){
    if(s->position >= 0){
        char temp = ' ';
        temp = s->c_stack[s->position];
        s->c_stack[s->position] = '\0';
        s->position--;
        return temp;
    }
    else{
        return '\0';
    }
}

bool isEmpty(stack s){
    //printf("position: %d\n", s.position);
    if(s.c_stack[s.position] == '\0' && s.position == -1){
        return true;
    }
    return false;
}

char peek(stack s){
    return s.c_stack[s.position];
}

void initStack(stack *s){
    s->position = -1;
}

void Display(stack s){
    printf("STACK\n");
    for (int i = s.position; i >= 0; i--)
    {
        printf("%c\n",s.c_stack[i]);
    }
    
}