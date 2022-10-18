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
	char *s, c;
	int int_val, printed_char = 0;
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
				printed_char += print_digits(int_val);
				break;
			case 'i':
				int_val = va_arg(arg_p, int);
				printed_char += print_digits(int_val);
				break;
			case 'c':
				c = va_arg(arg_p, int);
				_putchar(c);
				printed_char += 1;
				break;
			case 's':
				s = va_arg(arg_p, char *);
				printed_char += _print_string_number(s);
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

/**
 * print_digits - use _putchar to print every digits in number
 * @n: number input
 * Return: void
 **/
int print_digits(int n)
{
	int arr[MAX];
    int i = 0;
    int j, r;
	int printed_char = 0;
	if (n < 0)
	{
		_putchar('-');
		printed_char++;
		n = -n;
	}
	while (n >= 1)
	{
		r = n % 10;

		arr[i] = r;
		i++;
		n /= 10;
	}
	for (j = i - 1; j >= 0; j--)
	{
		_putchar(arr[j] + '0');
		printed_char += 1;
	}
	return (printed_char);
}


/**
 * _print_string_number - recursion function
 * @s: input string
 * Return: void
 */

int _print_string_number(char *s)
{
	int printed_char = 0;
	while (*s)
	{
		_putchar(*s);
		printed_char += 1;
		s++;
	}
	return (printed_char);
}
