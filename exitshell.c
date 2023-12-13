#include "main.h"

/**
 * isletter - ====
 * @arg: =====
 * Return: int
 */
int isletter(char *arg)
{
	int i = 0;

	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (2);
		i++;
	}
	return (0);
}



/**
 * exitshell - ======
 * @cmd: =====
 * @arg: ====
 */
void exitshell(char **arg, char *cmd)
{
	int no;

	if (isletter(arg[1]) == 2)
	{
		write(2, "./hsh: 1: exit: Illegal number: ",
				strlen("./hsh: 1: exit: Illegal number: "));
		write(2, arg[1], strlen(arg[1]));
		write(2, "\n", 1);
		free(cmd);
		foster.exitcode = 2;
		free_memmory2(foster.data);
		exit(2);
	}
	else
	{
		no = atoi(arg[1]);
		free(cmd);
		foster.exitcode = no;
		free_memmory2(foster.data);
		exit(no);
	}
}
