#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "binary_tree.h"
int main()
{
    struct node* root = NULL;
    int menu = -1, value;
    printf("1 - Add new \n");
    printf("2 - Breadth first search \n");
    printf("3 - Depth first search \n");
    printf("4 - Search number \n");
    printf("5 - Max and count \n");
    printf("0 - Exit \n");
    printf("Enter number: ");
    while (menu != 0)
    {
        scanf("%d", &menu);
        if (menu == 1)
        {
            printf("Enter your number: ");
            scanf("%d", &value);
            add_new(&root, value);
        }
        else if (menu == 2)
        {
            bfs(root);
        }
        else if (menu == 3)
        {
            dfs(root);
            printf("\n");
        }
        else if (menu == 4)
        {
            printf("Enter your number: ");
            scanf("%d", &value);
            search(root, value);
        }
        else if (menu == 5) {
            if (root == NULL) {
                printf("Tree is empty\n");
            }
            else {
                int max_value = max_tree(root); 
                int count = count_of_value(root, max_value); 

                printf("Max is: %d\n", max_value);
                printf("Count is: %d\n", count);
            }
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
    while (getchar() != '\n');
    getchar();
}