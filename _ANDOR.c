#include "main.h"
void execute_toks_ANDOR(char **toks);
void _ANDOR(char *arg);
/**
 * _ANDOR - =======
 * @arg: ========
 */
void _ANDOR(char *arg)
{

	/*char **tokens;*/
	int j = 0;
	char arr[100] = {'\0'};
	char temp[2] = {'\0'};
	char *tokens[12000] = {NULL};
	char *logic[500] = {NULL};
	char cmd[1000] = {'\0'};

	foster.ind = '0';
	foster.ANDstatus = 0;
	if (strchr(arg, '&') != NULL && strchr(arg, '|') != NULL)
		foster.ind = '1';
	strcpy(cmd, arg);
	strcpy(arr, "");
	while (cmd[j] != '\0')
	{
		if (cmd[j] != '|' && cmd[j + 1] != '\0' && cmd[j] != '&')
		{
			temp[0] = cmd[j];
			strcat(arr, temp);
		}
		else
		{
			strcat(arr, "\n");
			/*logic[0] = malloc(sizeof(char) * strlen(arr) + 1);*/
			/*strcpy(logic[0], arr);*/
			/*strcat(logic[0], "\0");*/
			logic[0] = arr;
			logic[1] = NULL;
			if (logic[0][0] == 's')
				strcpy(logic[0], "ls");
			if (logic[0] != NULL)
				execute_toks_ANDOR(logic);
			strcpy(arr, "");
			memset(arr, 0, 100);
			j = j + 2;
			reset_arg(logic);
			/*free(logic[0]);*/
			if (foster.ANDstatus != 0 && cmd[j - 2] == '&')
				break;
			if (foster.ANDstatus == 0 && cmd[j - 2] != '&' && foster.ind != '1')
				break;
			if (cmd[j + 1] == '/' || cmd[j + 1] == 'l')
			{
				j = j + 0;
			}
			else if (foster.ind == '1' && cmd[j - 2] == '|')
			{
				while (cmd[j] != '&')
					j++;
				j = j + 1;
			}

		}
		j++;

	}
	/*free(logic);*/
	reset_arg(tokens);
	reset_arg(logic);
	/*free_memmory(tokens);*/
}
/**
 * execute_toks_ANDOR - ======
 * @toks: =====
 */
void execute_toks_ANDOR(char **toks)
{
	int i = 0;
	int k = 0;
	char *args[12000] = {NULL};
	char *token = NULL;

	while (toks[k])
	{
		token = strtok(toks[k], " \n");
		while (token != NULL)
		{
			if (token[0] == '#')
			{
				args[i] = NULL;
				break;
			}
			args[i] = token;
			token = strtok(NULL, " \n");
			i++;
		}
		args[i] = NULL;
		if (args[0] != NULL)
		{
			if (strcmp(args[0], "echo") == 0 && args[1] != NULL)
			{
				_exec(args, args[1]);
			}
			else  if (strcmp(args[0], "exit") == 0)
			{
				if (args[1] != NULL)
				{
					exitshell(args, foster.ptr);

				}
				else
				{
					free(foster.ptr);
					exit(0);
				}
			}
			else
			{
				_exec(args, "none");
			}
		}
		reset_arg(args);
		i = 0;
		/* ================================================*/
		k++;
	}

}
