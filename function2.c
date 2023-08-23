#include "main.h"

/**
 * print_bi - Convert decimal to binary
 * @n:Decimal number
 * Return: Number of characters printed or 0
 */
int print_bi(unsigned int n)
{
	int i, index = 0, count = 0, binary[32];

	if (n == 0)
	{
		putchar('0');
		count++;
	}
	else
	{

		while (n > 0)
		{
			binary[index] = n % 2;
			n /= 2;
			index++;
		}

		for (i = index - 1; i >= 0; i--)
		{
			putchar(binary[i] + '0');
			count++;
		}
	}

	return (count);
}
