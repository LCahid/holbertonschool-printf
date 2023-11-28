#include <stdlib.h>
/**
  * itoa - function for make string from numbers
  * @a: number
  * Return: string
  */
char *itoa(int a)
{
	char *buffer;
	int temp = a, size = 0;

	while (temp)
	{
		temp /= 10;
		size++;
	}
	size++;
	buffer = malloc(size);
	temp = 0;
	for (temp = size - 1; temp >= 0; size--)
	{
		buffer[i] = a % 10 + '0';
		a /= 10;
	}
	return (buffer);
}
