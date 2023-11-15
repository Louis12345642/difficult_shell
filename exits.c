#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: string to be copied
 *@src: the main string
 *@n: number of characters to copy
 *Return: conected charaters
 */
char *_strncpy(char *d, char *st, int h)
{
	int i, j;
	char *s = d;

	i = 0;
	while (st[i] != '\0' && i < h - 1)
	{
		d[i] = st[i];
		i++;
	}
	if (i < h)
	{
		j = i;
		while (j < h)
		{
			d[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: the number string
 *@src: the number two string
 *@n: the amount the bytes
 *Return: the connected string
 */
char *_strncat(char *ds, char *sr, int n)
{
	int l, h;
	char *s = ds;

	l = 0;
	h = 0;
	while (ds[l] != '\0')
		l++;
	while (sr[h] != '\0' && h < n)
	{
		ds[l] = sr[h];
		l++;
		h++;
	}
	if (h < n)
		ds[l] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@s: parsing the string
 *@c: looking for the characters
 *Return: memory the pointer
 */
char *_strchr(char *t, char h)
{
	do {
		if (*t == h)
			return (t);
	} while (*t++ != '\0');

	return (NULL);
}
