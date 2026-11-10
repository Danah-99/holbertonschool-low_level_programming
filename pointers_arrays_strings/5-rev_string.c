#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: the string to reverse
 *
 * Return: void
 */
void rev_string(char *s)
{
	int i = 0;
	int j = 0;
	char tmp;

	while (s[j] != '\0')
		j++;
	j--;

	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
}
