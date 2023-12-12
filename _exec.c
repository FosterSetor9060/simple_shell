#include "main.h"
void  _exec(char **args, char *echo);
/**
 * _exec - ===========
 * @args:  =============
 * @echo: ==================
 */
void _exec(char **args, char *echo)
{
	int pid;
	int exit_status;

	if (foster.iscolon != 1)
		foster.errno++;
	(void)echo;
	pid  = fork();

	if (pid == 0)
	{
		if (strcmp(args[0], "echo") == 0)
		{
			if (strcmp(echo, "$$") == 0)
			{
				print_no1(getpid());
				write(1, "\n", 1);
				foster.exitcode = 0;
				free(foster.ptr);
				exit(0);
			}
			else if (strcmp(echo, "$?") == 0)
			{
				print_no1(foster.exitcode);
				write(1, "\n", 1);
				foster.exitcode = 0;
				free(foster.ptr);
				exit(0);
			}
			else
			{
				execve("/bin/echo", args, environ);
			}
		}
		else if (strcmp(args[0], "ls") == 0)
		{
			execve("/bin/ls", args, environ);
		}
		else
		{
			execve(args[0], args, environ);
		}
		write(2, foster.prog_name, strlen(foster.prog_name));
		write(2, ": ", 2);
		print_no(foster.errno);
		write(2, ": ", 2);/*./hsh: 1: qwerty: not found*/
		write(2, args[0], strlen(args[0]));
		write(2, ": not found\n", strlen(": not found\n"));
		foster.exitcode = 2;
		free(foster.ptr);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		foster.exitcode = 2;
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			if (exit_status != 0)
				foster.ANDstatus = exit_status;
			else
				foster.ANDstatus = 0;
			if (exit_status == 1)
				foster.exitcode = exit_status;

			if (exit_status  != 0 && (!isatty(STDIN_FILENO) && !(foster.iscolon == 1)))
			{
				foster.exitcode = exit_status;
				free(foster.ptr);
				if (exit_status == 1)
					exit(127);
				exit(exit_status);
			}
		}
	}
}
