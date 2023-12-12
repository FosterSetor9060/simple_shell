#include "main.h"

/**
 * free_memmory - ====
 * @arg: ===
 */
void free_memmory(char **arg)
{
	int i = 0;

	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);

}
