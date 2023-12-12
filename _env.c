#include "main.h"
/**
 * _env - ======
 * @env: =====
 */

void _env(char **env)
{
	int i = 0;

	while (env[i])
	{
		write(1, env[i], strlen(env[i]));
		write(1, "\n", 1);
		i++;
	}
}
