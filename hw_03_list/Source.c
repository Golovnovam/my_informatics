#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include "Linked_list.h"
#include <stdlib.h>
int main( void)
{
	
	int   menu = -1;
	list* head = NULL;
		
	printf("1 - print list\n");
	printf("2 - add first\n");
	printf("3 - add last\n");
	printf("4 - add N node\n");
	printf("5 - delete first\n");
	printf("6 - delete last\n");
	printf("0 - Exit\n");
	while (menu != 0)
	{
		scanf("%d", &menu);
		if (menu == 1)
		{
			if (head == NULL)
				printf("Is Empty\n");
			else
			{
				
				print_linked_list(head);
				printf("\n");
			}
		}
		else if (menu == 2)
		{
			int a;
			printf("Enter your number: \n");
			scanf("%d", &a);
			add_first(&head, a);
			printf("\n");
		}
		else if (menu == 3)
		{
			int a;
			printf("Enter your number: \n");
			scanf("%d", &a);
			add_last(&head, a);
			printf("\n");
		}
		else if (menu == 4)
		{
			int a, n;
			printf("Enter position and your number: \n");
			scanf("%d %d", &n, &a);
			add_N(head, n, a);
			printf("\n");
		}
		else if (menu == 5)
		{
			delete_first(&head);
			printf("First number was deleted\n");
		}
		else if (menu == 6)
		{
			delete_last(&head);
			printf("Last number was deleted\n");
		}
		else if (menu == 0)
		{
			printf("\n");
		}
		else
		{
			printf("Wrong number\n");
		}
	}

	return 0;
}