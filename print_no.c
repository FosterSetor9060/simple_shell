#include "main.h"
/**
 * _writechar - =======
 * @c: =====
 */
void _writechar(char c)
{

	write(2, &c, 1);

}


/**
 * print_no - ====
 * @num: ===
 */
void print_no(long num)
{
	if (num < 0)
	{
		_writechar('-');
		num = num * -1;
	}

	if (num / 10)
		print_no(num / 10);

	_writechar(num % 10 + '0');
}
