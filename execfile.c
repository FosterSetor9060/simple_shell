#include "main.h"
void execfile(char *file);
void reset_arg(char **arg);
/**
 * reset_arg - clear and sett all
 * arguments to NULL
 * @arg: Arguments to reset
 */
void reset_arg(char **arg)
{
	int i = 0;

	while (arg[i])
	{
		arg[i] = NULL;
		i++;
	}
}
/**
 * execfile - ======
 * @file: =====
 */
void execfile(char *file)
{
	char line[18000] = {'\0'};
	int fd;
	int j = 0;
	int k = 0;
	/*char **args = NULL;*/
	int nbytes = 0;
	char *token = NULL;
	char buffer[18000];
	int i = 0;
	char *arg[18000] = {NULL};

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(2, "./hsh: 0: Can't open ",
				strlen("./hsh: 0: Can't open "));
		write(2, file, strlen(file));
		write(2, "\n", 1);
		foster.exitcode = 127;
		exit(127);
	}
	while ((nbytes = read(fd, buffer, 18000)) > 0)
	{

		for (i = 0; i < nbytes; i++)
		{

			if (buffer[i] == '\n')
			{
				line[j] = '\0';
				token = strtok(line, " \t\n\r");
				while (token != NULL)
				{
					if (token[0] == '#')
					{
						arg[k] = NULL;
						break;
					}
					arg[k] = token;
					token = strtok(NULL,  " \t\n\r");
					k++;
				}
				arg[k] = NULL;
				k = 0;
				if (arg[0] != NULL)
				{
				if (strcmp(arg[0], "echo") == 0 && arg[1] != NULL)
					_exec(arg, arg[1]);
				else
					_exec(arg, "none");
				}
				reset_arg(arg);
				strcpy(line, "\0");
				j = 0;
			}
			else
			{
				line[j] = buffer[i];
				j++;
			}
		}
	}
}
