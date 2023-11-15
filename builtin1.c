#include "shell.h"

/**
 * _myhistory - display the history list of the program
 *              with line and numbers , starting at 0.
 * @info: structure containing the arguement used in mainting 
 *        constain for maintaining.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - set the alias to the begining
 * @info: arguement structure
 * @str: this is the alais
 *
 * Return: Always 0 on success, 1 when there is an error
 */
int unset_alias(info_t *info, char *str)
{
	char *d, q;
	int ret;

	d = _strchr(str, '=');
	if (!d)
		return (1);
	q = *d;
	*d = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*d = q;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @info: argument structures
 * @str: here is the string alais
 *
 * Return: Always 0 on success, 1 when there error
 */
int set_alias(info_t *info, char *str)
{
	char *q;

	q = _strchr(str, '=');
	if (!q)
		return (1);
	if (!*++q)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *j = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (j = node->str; a <= p; j++)
			_putchar(*j);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - copies the alais of the buitin1
 * @info: this is the structure containing the params. when maintaining
 *          function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int a = 0;
	char *u = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (a = 1; info->argv[a]; a++)
	{
		u = _strchr(info->argv[a], '=');
		if (u)
			set_alias(info, info->argv[a]);
		else
			print_alias(node_starts_with(info->alias, info->argv[a], '='));
	}

	return (0);
}
