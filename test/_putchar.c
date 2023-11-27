#include <unistd.h>
/**
  * _putchar - put char
  * 
  * @c: char
  *
  */
void _putchar(char c)
{
	write(1, &c, 1);
}
