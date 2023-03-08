#include "main.h"

/**
 * find_other - A function that finds the presence of a character in a string
 * @c: input character
 * @str: input string
 * @counter: counter
 * Return: 1 if the character is present
 */
int find_other(char s, char *str, int *counter)
{
	if (s == *str)
		return (1);
	else if (*str == '\0')
		return (0);
	else if (s == '*')
		return (0);
	else
	{
		*counter += 1;
		return (find_other(s, ++str, &*counter));
	}
}

/**
 * wildcmp - A function that compares two strings
 * @s1: First input string
 * @s2: Second input string
 * Return: 1 if strings identical and 0 in otherwise
 */
int wildcmp(char *s1, char *s2)
{
	int counter;

	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else if (*s1 == *s2)
		return (wildcmp(++s1, ++s2));
	else if (*s1 == '*')
	{
		counter = 0;
		find_other(*++s1, s2, &counter);
		s2 += counter;
		return (wildcmp(s1++, s2++));
	}
	else if (*s2 == '*')
	{
		counter = 0;
		find_other(*++s2, s1, &counter);
		s1 += counter;
		return (wildcmp(s1++, s2++));
	}
	else
		return (0);
}
