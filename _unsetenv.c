#include "main.h"
void _unsetenv(char *arg);
/**
 * _unsetenv - ====
 * @arg: ======
 */
void _unsetenv(char *arg)
{
	char copy[6000];
	char  *temp = NULL;
	int i = 0;
	int keep = 0;
	char *token = NULL;
	int isfree = 0;

	(void)temp;

	while (foster.data[i])
	{
		strcpy(copy, foster.data[i]);
		token =  strtok(copy, "=");
		if (strcmp(token, arg) == 0)
		{
			isfree = 1;
		}
		memset(copy, 0, 6000);
		i++;
	}
	memset(copy, 0, 6000);
	i = 0;
	while (environ[i] != NULL)
	{
		strcpy(copy, environ[i]);
		token =  strtok(copy, "=");
		if (strcmp(token, arg) == 0)
		{
			temp = environ[i];
			keep = keep + 1;
			environ[i] = environ[keep];
			foster.envlen--;
		}
		else
		{
			environ[i] = environ[keep];

		}
		/*memset(copy, 0, 6000);*/
		keep++;
		i++;
	}
	environ[i] = NULL;

	if (isfree)
	{
		/*free(temp);*/
	}
}
