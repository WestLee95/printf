#include "main.h"
/**
 * _printf - produces output according to a format
 * @format:char string provided
 * @...:additional argument
 * Return:number of character printed
 */

int _printf(const char *format, ...)
{
    int char_print = 0;
    va_list args;
    
    if (format == NULL){
        return (-1);
    }
    
    va_start(args, format);
    
    while (*format) {
        if (*format != '%') {
            write(1, format, 1);
            char_print++;
        } else {
            format++; 
            
            if (*format == 'c') {
                char c = (char) va_arg(args, int); 
                write(1, &c, 1);
                char_print++;
            } else if (*format == 's') {
                char *str = va_arg(args, char*);
                int str_len = strlen(str);
                write(1, str, str_len);
                char_print += str_len;
            } else if (*format == '%') {
                write(1, format, 1);
                char_print++;
            }
        }
        format++;
    }
    va_end(args);
    return char_print;
}

