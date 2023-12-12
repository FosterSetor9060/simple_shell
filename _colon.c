#include "main.h"
void execute_toks(char **toks);
void _colon(char *arg);
/**
 * _colon - =======
 * @arg: ========
 */
void _colon(char *arg)
{

	/*char **tokens;*/
	char *token = NULL;
	int  i = 0;
	/*tokens = malloc(sizeof(char *) * 12000);*/
	char *tokens[12000] = {NULL};

	token = strtok(arg, ";");
	while (token != NULL)
	{
		if (token[0] == '#')
		{
			tokens[i] = NULL;
			break;
		}
		/*tokens[i] = malloc(sizeof(char) * (strlen(token) + 1));*/
		/*strcpy(tokens[i], token);*/
		/*strcat(tokens[i], "\0");*/
		/* run a second tokenize*/
		/* ================================*/
		tokens[i] = token;
		token = strtok(NULL, ";");
		i++;
	}
	tokens[i] = NULL;
	i = 0;
	execute_toks(tokens);
	reset_arg(tokens);
	/*free_memmory(tokens);*/
}
/**
 * execute_toks - ======
 * @toks: =====
 */
void execute_toks(char **toks)
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
			if (strcmp(args[0], "exit") == 0)
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
