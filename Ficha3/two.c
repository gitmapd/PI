#include <stdio.h>

size_t twoDuplicates_rem(int nums[], size_t size)
{
	if (size == 0)
		return 0;

	size_t ptr = 0;

	for (size_t i = 1; i < size; i++) {
		if (nums[i] != nums[ptr]) {
			ptr++;
			nums[ptr] = nums[i];
		}
	}

	return ptr + 1;
}


int main(void)
{
	int a[] = { 1, 1, 1, 2, 2, 1, 1, 2, 3 };
	size_t len = sizeof a / sizeof a[0];

	size_t res = twoDuplicates_rem(a, len);

	for (size_t i = 0; i < res; i++)
		printf("%d ", a[i]);

	printf("\n");
	return 0;
}