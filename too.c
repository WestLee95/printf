#include "main.h"

/**
 * _printf - Custom implementation of printf for 'c', 's', '%', 'd' and 'i' specifiers.
 * @format: Format string with conversion specifiers.
 * Return: Number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
    int pr = 0;
    int i = 0;
    va_list args;
    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] != '%')
        {
            putchar(format[i]);
            pr++;
        }
        else
        {
            i++;
            switch (format[i])
            {
                case 'c':
                {
                    char c = va_arg(args, int);
                    putchar(c);
                    pr++;
                    break;
                }
                case 's':
                {
                    char *str = va_arg(args, char *);
                    while (*str)
                    {
                        putchar(*str);
                        str++;
                        pr++;
                    }
                    break;
                }
                case '%':
                {
                    putchar('%');
                    pr++;
                    break;
                }
                case 'd':
                case 'i':
                {
                    int num = va_arg(args, int);
                    printf("%d", num);
                    pr++;
                    break;
                }
                default:
                {
                    putchar('%');
                    putchar(format[i]);
                    pr += 2;
                    break;
                }
            }
        }
        i++;
    }

    va_end(args);
    
    putchar('\n');
    return (pr);
}

