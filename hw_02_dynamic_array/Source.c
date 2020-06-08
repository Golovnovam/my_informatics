#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
int main()
{
	int* main = NULL;
	int* store = NULL;
	int* buf = NULL;
	int n, m, s = 4, k, i, j, counter = 0, layer = 0, a = 0;
	printf("Enter size of array: ");
	scanf("%d %d", &n, &m);
	main = (int*)malloc(n * m * sizeof(int));
	store = (int*)malloc(s * sizeof(int));
	printf("Enter numbers for filing the array: ");
	for (i = 0; i < s; i++)
		scanf("%d", &store[i]);
	buf = (int*)realloc(store, n * m * sizeof(int));
	store = buf;
	k = s;
	s = n * m;
	if (n * m > k)
		for (i = k; i < s; i++)
		{
			if (a < k - 1)
			{
				store[i] = store[i - 1] - 1;
				a++;
			}
			else
			{
				store[i] = store[i - 1] + 1;
				a++;
			}
			if (a == 2 * k - 2)
				a = 0;
		}
	while (counter < s)
	{
		if (counter >= s) break;
		for (i = layer; i < m - layer; i++)
		{
			*(main + layer * m + i) = store[counter];
			counter++;
		}
		if (counter >= s) break;
		for (i = layer + 1; i < n - layer; i++)
		{
			*(main + i * m + m - layer - 1) = store[counter];
			counter++;
		}
		if (counter >= s) break;
		for (i = m - layer - 1; i > layer; i--)
		{
			*(main + (n - layer - 1) * m + i - 1) = store[counter];
			counter++;
		}
		if (counter >= s) break;
		for (i = n - layer - 2; i > layer; i--)
		{
			*(main + i * m + layer) = store[counter];
			counter++;
		}
		layer++;
	}
	printf("\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			printf("%d ", *(main + i * m + j));
		printf("\n");
	}
	free(main);
	free(store);
	while (getchar() != '\n');
	getchar();
}