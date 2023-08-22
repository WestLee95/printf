#include "main.h"

/**
 * _printf - Handles implementation of printf for 'd' and 'i' specifiers.
 * @format: Format string with conversion specifiers.
 * @num: Integer to be printed.
 * Return: Number of characters printed.
 */
int _printf(const char *format, int num)
{
	int pr = 0;
	int i = 0;

	while (format && format[i])
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			pr++;
		}
		else if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			printf("%d", num);
			pr++;
			i++;
		}
		else
		{
			putchar(format[i]);
			pr++;
		}
		i++;
	}

	return (pr);
}