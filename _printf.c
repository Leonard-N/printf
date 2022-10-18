#include "main.h"
#include <stdarg.h>
#define MAX 100

/**
 * _printf -  a function to mimic the printf fro
 *				the stdio.h library
 * @format: the first input
 * ...: other inputs
 * return: nothing
 **/
int _printf(const char *format, ...)
{
	va_list arg_p;
	const char *pp;
	char *s;
	char c;
	int int_val;
	int printed_char = 0;
	int arr[MAX];
    int i = 0;
    int j, r;

	va_start(arg_p, format);
	for (pp = format; *pp; pp++)
	{
		if (*pp != '%')
		{
			_putchar(*pp);
			printed_char++;
			continue;
		}

		switch (*++pp)
		{
			case 'd':
				int_val = va_arg(arg_p, int);
				while (int_val >= 1)
				{
					r = int_val % 10;

					arr[i] = r;
					i++;
					int_val /= 10;
				}
				for (j = i - 1; j >= 0; j--)
				{
					_putchar(arr[j] + '0');
					printed_char += 1;
				}
				break;
			case 'i':
				int_val = va_arg(arg_p, int);
				while (int_val >= 1)
				{
					r = int_val % 10;

					arr[i] = r;
					i++;
					int_val /= 10;
				}
				for (j = i - 1; j >= 0; j--)
				{
					_putchar(arr[j] + '0');
					printed_char += 1;
				}
				break;
			case 'c':
				c = va_arg(arg_p, int);
				_putchar(c);
				printed_char += 1;
				break;
			case 's':
				for (s = va_arg(arg_p, char *); *s; s++)
				{
					_putchar(*s);
					printed_char += 1;
				}
				break;
			default:
				_putchar(*pp);
				printed_char += 1;
				break;
		}
	}
	va_end(arg_p);
	return (printed_char);
}
