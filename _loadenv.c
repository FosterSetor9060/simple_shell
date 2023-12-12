#include "main.h"

/**
 * _loadenv - =====
 * @e: ==
 */
void _loadenv(char **e)
{
	int i = 0;

	while (i < 18000)
	{

		foster.custom_env[i] = NULL;
		if (i < 200)
			foster.data[i] = NULL;
		i++;
	}
	i = 0;

	while (e[i])
	{
		foster.custom_env[i] = e[i];
		i++;
		foster.envlen = i;
	}
}
