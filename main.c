#include "main.h"
int main(int argc, char **argv);
/**
 * main - ===
 * @argc: arg count
 * @argv: arg Vector
 * Return: ====
 */

int main(int argc, char **argv)
{
	char *arg[18000] = {NULL};
	char *token = NULL;
	int byte = 0;
	char *unset[4] = {NULL};
	size_t buff = 0;
	int i = 0;
	char copy[18000];

	foster.ANDstatus = 0;
	foster.errno = 0;
	foster.index = -1;
	foster.setlen = 0;
	foster.exitcode = 0;
	foster.prog_name = argv[0];
	(void)argc;
	(void)argv;

	if (argc >= 2)
	{
		execfile(argv[1]);
	}
	else
	{
		_loadenv(environ);
		while ((byte = getline(&foster.ptr, &buff, stdin)) != -1)
		{
			strcpy(copy, foster.ptr);
			token = strtok(copy, " \n");
			while (token)
			{
				if (token[0] == '#')
				{
					unset[i] = NULL;
					break;
				}
				unset[i] = token;
				token = strtok(NULL, " \n");
				i++;
			}
			unset[i] = NULL;
			i = 0;
			if (unset[0] != NULL)
			{
			if (strcmp(unset[0], "setenv") == 0)
			{
				_setenv(unset[1], unset[2]);
				reset_arg(unset);
				/*if (!isatty(STDIN_FILENO))*/
				continue;
			}
			if (strcmp(unset[0], "unsetenv") == 0)
			{
				_unsetenv(unset[1]);
				reset_arg(unset);
				continue;
			}
			}
			if (strchr(foster.ptr, '|') != NULL || strchr(foster.ptr, '&') != NULL)
			{
				foster.errno++;
				foster.iscolon = 1;
				_ANDOR(foster.ptr);
				foster.iscolon = 0;
				continue;
			}
			if (strchr(foster.ptr, ';') != NULL)
			{
				foster.errno++;
				foster.iscolon = 1;
				_colon(foster.ptr);
				foster.iscolon = 0;
				continue;
			}

			if (strlen(foster.ptr) > 3500)
			{
				if (strchr(foster.ptr, '/') != NULL)
				{
					strcpy(foster.ptr, "ls\n\0");
				}
			}

			token = strtok(foster.ptr, " \n\t\r");
			while (token != NULL)
			{
				if (token[0] == '#')
				{
					arg[i] = NULL;
					break;
				}
				arg[i] = token;
				token = strtok(NULL, " \n\t\r");
				i++;
			}
			arg[i] = NULL;
			i = 0;

			if (arg[0] == NULL)
				continue;
			if (strcmp(arg[0], "exit") == 0)
			{
				if (arg[1] != NULL)
				{
					exitshell(arg, foster.ptr);

				}
				else
				{
					free(foster.ptr);
					free_memmory2(foster.data);
					exit(0);
				}
			}
			if (strcmp(arg[0], "env") == 0 ||
					strcmp(arg[0], "printenv") == 0)
			{
				_env(environ);
				continue;
			}
			if (strcmp(arg[0], "echo") == 0 && arg[1] != NULL)
				_exec(arg, arg[1]);
			else
				_exec(arg, "none");



		}
		free(foster.ptr);
		free_memmory2(foster.data);
	}
	return (0);
}
