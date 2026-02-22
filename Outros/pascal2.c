
#include <stdio.h>
#include <stdlib.h>

void next_row(int row[], int n)
{
	int *next = malloc((n + 1) * sizeof(int));
	next[0] = 1;
	next[n] = 1;

	for (int i = 1; i < n; i++)
		next[i] = row[i - 1] + row[i];
	

	for (int i = 0; i < n + 1; i++)
		row[i] = next[i];
	
	free(next);
}

void pascal(int v[], int n)
{
	v[0] = 1;
	v[1] = 1;

	for (int i = 1; i < n; i++) {
		next_row(v, i + 1);
	}
}

int main(void)
{
	int row[100] = { 0 };
	int N = 6;
	pascal(row, N);

	for (int i = 0; i < N; i++)
		printf("%d ", row[i]);

	printf("\n");
	return 0;
}
