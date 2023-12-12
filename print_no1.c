#include "main.h"
/**
 * _writechar1 - ========
 * @c: =====
 */
void _writechar1(char c)
{

	write(1, &c, 1);

}


/**
 * print_no1 - ====
 * @num: ===
 */
void print_no1(long num)
{
	if (num < 0)
	{
		_writechar1('-');
		num = num * -1;
	}

	if (num / 10)
		print_no1(num / 10);

	_writechar1(num % 10 + '0');
}
