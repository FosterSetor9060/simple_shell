#include "main.h"

/**
 * free_memmory2 - ====
 * @arg: ===
 */
void free_memmory2(char **arg)
{
	int i = 0;

	while (arg[i])
	{
		if (arg[i] != NULL)
			free(arg[i]);
		i++;
	}

}
