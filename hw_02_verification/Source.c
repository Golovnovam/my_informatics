#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
int main()
{
	double* a = NULL;
	double* b = NULL;
	double* bufa = NULL;
	double* bufb = NULL;
	int n,i,j;
	double eps;
	eps = 1e-30;
	printf("Enter number N: ");
	scanf("%d", &n);
	a = (double*)malloc(n * sizeof(double));
	b = (double*)malloc(n * sizeof(double));
	if (a == 0) return 1;
	if (b == 0) return 1;
	printf("Enter numbers for filing the array A ");
	for (i = 0; i < n; i++)
		 scanf("%lf", &a[i]);
		printf("Enter numbers for filing the array B ");
		for (i = 0; i < n; i++)
			scanf("%lf", &b[i]);

		for (i = 1; i < n; i++)
		{
			if ((a[i]+eps) > b[i])
			{
				for (j = i; j < (n-1); j++)
				{
					a[j] = a[j + 1];
					b[j] = b[j + 1];

				};
			
				bufa = (double*)realloc(a, (n - 1) * sizeof(double));
				if (bufa == NULL)
				{
					free(a);
					return 1;
				}
				bufb = (double*)realloc(b, (n - 1) * sizeof(double));
				if (bufb == NULL)
				{
					free(b);
					return 1;
				}
				a = bufa;
				b = bufb;
				n--;
			};

		};
		if ((bufa == NULL) || (n == 0))
			printf("Empty\n");
		else
		{
			printf("A =   ");
			for (i = 0; i < n; i++)
				printf(" %.3lf ", *(a + i));
			printf("\n");
			printf("B =   ");
			for (i = 0; i < n; i++)
				printf(" %.3lf ", *(b + i));
		}
		free(a);
		free(b);
	while (getchar() != '\n');
	getchar();
	return 0;
}