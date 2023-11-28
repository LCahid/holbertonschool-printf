#include <stdlib.h>
/**
  * itoa - function for make string from numbers
  * @a: number
  * Return: string
  */
char *itoa(int a)
{
	char *buffer;
	int temp = a, size = 0, is_negative = 0;

	if (a < 0)
		is_negative = 1;
	while (temp)
	{
		temp /= 10;
		size++;
	}
	if (is_negative)
	{
		size++;
		a *= -1;
	}
	buffer = malloc(size);
	temp = 0;
	for (temp = size - 1; temp >= 0; temp--)
	{
		buffer[temp] = a % 10 + '0';
		a /= 10;
	}
	if (is_negative)
		buffer[0] = '-';
	return (buffer);
}
