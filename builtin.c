#include "shell.h"

/**
 * _myexit - gets out of the shell
 * @info: arguement structures . for maintining
 *             the code 
 *  Return: give the code status after exit
 *         (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int et;

	if (info->argv[1])  /* checks for arguements */
	{
		et = _erratoi(info->argv[1]);
		if (et == -1)
		{
			info->status = 2;
			print_error(info, "not accepted number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - change the current directory
 * @info: arguement structures . for maintining
 *             the code 
 *  Return: 0
 */
int _mycd(info_t *info)
{
	char *a, *dr, buffer[1024];
	int chdir_r;

	a = getcwd(buffer, 1024);
	if (!a)
		_puts("getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dr = _getenv(info, "HOME=");
		if (!dr)
			chdir_r = /*what do we here */
				chdir((dr = _getenv(info, "PWD=")) ? dr : "/");
		else
			chdir_r = chdir(dr);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(a);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /*what do we here */
			chdir((dr= _getenv(info, "OLDPWD=")) ? dr : "/");
	}
	else
		chdir_r = chdir(info->argv[1]);
	if (chdir_r == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - change the current directory
 * @info: arguement structures . for maintining
 *             the code 
 *  Return:  0
 */
int _myhelp(info_t *info)
{
	char **arg_ar;

	arg_ar = info->argv;
	_puts("call the work for function implementing \n");
	if (0)
		_puts(*arg_ar); /* tempure of unsude workdirectory */
	return (0);
}
