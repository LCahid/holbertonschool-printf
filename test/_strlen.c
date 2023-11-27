/**
  * _strlen - calculate string length
  * @str: string
  *
  * Returns: length of string
  */
int _strlen(char *str)
{
	char *s;
	
	for (s = str; *s; s++);
	return (s - str);
}
