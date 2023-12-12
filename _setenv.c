#include "main.h"
int isenv(char **e, char *find);
void _setenv(char *ptr1, char *ptr2);
/**
 * isenv - ==
 * @e: ====
 * @find: ===
 * Return: int
 */
int isenv(char **e, char *find)
{
	int i = 0;
	char *token = NULL;
	char copy[6000];
	int j = -1;

	while (foster.custom_env[i])
	{
		strcpy(copy, foster.custom_env[i]);
		token =  strtok(copy, "=");
		if (strcmp(token, find) == 0)
		{
			j = i;
		}
		i++;

	}
	i = 0;
	memset(copy, 0, 6000);
	while (e[i])
	{
		strcpy(copy, e[i]);
		token =  strtok(copy, "=");
		if (strcmp(token, find) == 0)
		{
			free(e[i]);
			foster.index = i;
			return (j);
		}
		i++;
	}
	return (j);

}
/**
 * _setenv - ====
 * @ptr1: ===
 * @ptr2: ====
 */
void _setenv(char *ptr1, char *ptr2)
{
	int target;

	if (ptr1 != NULL && ptr2 != NULL)
	{
		target = isenv(foster.data, ptr1);
		if (target >= 0 && foster.index == -1)
		{
			foster.data[foster.setlen] =
				malloc(sizeof(char) * (strlen(ptr1) + strlen(ptr2) + 2));
			strcpy(foster.data[foster.setlen], ptr1);
			strcat(foster.data[foster.setlen], "=");
			strcat(foster.data[foster.setlen], ptr2);
			foster.custom_env[target] = foster.data[foster.setlen];
			environ = foster.custom_env;
			foster.setlen++;
		}
		else if (target >= 0 && foster.index != -1)
		{
			foster.data[foster.index] =
				malloc(sizeof(char) * (strlen(ptr1) + strlen(ptr2) + 2));
			strcpy(foster.data[foster.index], ptr1);
			strcat(foster.data[foster.index], "=");
			strcat(foster.data[foster.index], ptr2);
			foster.custom_env[target] = foster.data[foster.index];
			environ = foster.custom_env;

		}
		else
		{
			foster.data[foster.setlen] =
				malloc(sizeof(char) * (strlen(ptr1) + strlen(ptr2) + 2));
			strcpy(foster.data[foster.setlen], ptr1);
			strcat(foster.data[foster.setlen], "=");
			strcat(foster.data[foster.setlen], ptr2);
			foster.envlen++;
			foster.custom_env[foster.envlen - 1] = foster.data[foster.setlen];
			environ = foster.custom_env;
			foster.setlen++;
		}
	}
	else
	{
		write(2, "wrong format\n", strlen("wrong format\n"));
	}
	foster.index = -1;
}
