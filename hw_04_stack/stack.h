#ifndef STACK_H
#define STACK_H
typedef struct stack
{
	char value;
	struct stack* next;
}stack;
push(stack** head, const char str);
char pop(stack** head);
is_empty(stack** head);
#endif