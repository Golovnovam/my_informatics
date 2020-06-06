#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stack.h"
#include <string.h>
check(const char* str) //проверка первого символа
{
	struct stack* s = NULL;
	int len = strlen(str);
	int i;
	if (str[0] == '(')
		push(&s, str[0]);
	else if (str[0] == ')')
		return 0;
	if (str[0] == '{')
		push(&s, str[0]);
	else if (str[0] == '}')
		return 0;
	if (str[0] == '[')
		push(&s, str[0]);
	else if (str[0] == ']')
		return 0;

	for (i = 1; i < len; i++) //проверяем последовательность на correct
	{
		if (str[i] == '(')
			push(&s, str[i]);
		else if (str[i] == ')')
		{
			if (is_empty(&s))
				return 0;
			else
			{
				if (s->value == '(')
					pop(&s);
				else return 0;
			}
		}

		if (str[i] == '{')
			push(&s, str[i]);
		else if (str[i] == '}')
		{
			if (is_empty(&s))
				return 0;
			else
			{
				if (s->value == '{')
					pop(&s);
				else return 0;
			}

		}

		if (str[i] == '[')
			push(&s, str[i]);
		else if (str[i] == ']')
		{
			if (is_empty(&s))
				return 0;
			else
			{
				if (s->value == '[')
					pop(&s);
				else return 0;
			}
		}

	}

	if (is_empty(&s)) //проверяем стек на пустоту
		return 1;
	else return 0;
}
int main()
{
	char str[100];
	int sum;
	while (1)
	{
		printf("Print string:");
		gets_s(str, 100);
		sum = check(str); // 0 или 1
		if (sum) //1 correct, 0 not correct
			printf("correct\n");
		else printf("not correct\n");
	}
	while (getchar() != '\n');
}