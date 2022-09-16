#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * factor - factorizes a integer
 * @num: the integer to be factorized
 *
 *Return: the factor of the number
 */

void factor(const char *num_ptr)
{
	unsigned long int factor = 2;
	unsigned long int root;
	unsigned long long int num;

	num = atoll(num_ptr);
	root = sqrt(num);

	for (; factor <= root; factor++)
		if (num % factor == 0)
		{
			printf("%llu=%llu*%lu\n", num, num / factor, factor);
			return;
		}
}

/**
 * main - Factorize numbers into a product of two smaller numbers.
 * @argc: the number of command line args
 * @argv: pointer to the list of command lines args
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	FILE* ptr;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	if (argc != 2)
	{
		printf("Usage: %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	ptr = fopen(argv[1], "r");

	if (ptr == NULL)
	{
		printf("Unable to open the file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line, &len, ptr)) != -1)
	{
		factor(line);
	}
	free(line);
	fclose(ptr);

	exit(EXIT_SUCCESS);
}
