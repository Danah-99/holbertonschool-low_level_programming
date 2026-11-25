#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: the first string
 * @s2: the second string
 *
 * Return: negative if s1 < s2, 0 if equal, positive if s1 > s2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;

	return (s1[i] - s2[i]);
}
