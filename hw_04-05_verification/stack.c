#include <stdio.h>
#include <stdlib.h>

// структура для элемента стека
typedef struct node_t
 {
    char value; 
    struct node_t *next; 
} node_t;

// структура для стека
typedef struct stack_t {
    node_t *top; // указатель на вершину стека
} stack_t;

void push(stack_t *stack, char value)
 {
    node_t *node = (node_t *) malloc(sizeof(node_t)); 
    node->value = value; 
    node->next = stack->top; 
    stack->top = node; 
}
char pop(stack_t *stack) {
    char value = stack->top->value; 

    node_t *tmp = stack->top; 
    stack->top = stack->top->next; 
    free(tmp);

    return value; 
}

int is_empty(stack_t stack) {
    return stack.top == NULL;  
}

//проверяем буква ли
int is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main(void) {
    stack_t stack; 
    stack.top = NULL;
    for (char c = getchar(); c != '='; c = getchar())
        if (is_letter(c)) 
            push(&stack, c); 
        
    while (!is_empty(stack))
        printf("%c", pop(&stack));

    printf("\n");
    
    return 0;
}