#include <stdlib.h>
#include <limits.h>
/**
  * itoa - function for make string from numbers
  * @a: number
  * Return: string
  */
char *itoa(int a)
{
	char *buffer;
	int temp = a, size = 0, is_negative = 0, k = 0;

	if (a < 0)
		is_negative = 1;
	do {
		temp /= 10;
		size++;
	} while (temp);
	if (is_negative)
	{
		if (a == INT_MIN)
			a += 1, k = 1;
		size++;
		a *= -1;
	}
	buffer = malloc(size);
	if (buffer == NULL)
		exit(77);
	temp = 0;
	for (temp = size - 1; temp >= 0; temp--)
	{
		buffer[temp] = a % 10 + '0';
		a /= 10;
	}
	if (k)
		buffer[size - 1] += 1;
	if (is_negative)
		buffer[0] = '-';
	return (buffer);
}
