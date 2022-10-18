#include <stdarq.h>
#include "main.h"

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
    char *pp;
    char *s;
    char c;
    int int_val;

	va_start(arg_p, format);
	for (pp = format; *pp; pp++)
	{
		if (*pp != '%')
		{
			_putchar(*pp);
			continue;
		}

		switch (*++pp)
		{
			case 'd':
				int_val = va_arg(arg_p, int);
				print_digits(int_val);
				break;
			case 'i':
				int_val = va_arg(arg_p, int);
				print_digits(int_val);
				break;
			case 'c':
				c = va_arg(arg_p, int);
				_putchar(c);
				break;
			case 's':
				s = va_arg(arg_p, char *);
				_puts_recursion(s);
				break;
			default:
				_putchar(*pp);
				break;
		}

	}
	va_end(arg_p);
}

/**
 * print_digits - use _putchar to print every digits in number
 * @n: number input
 * Return: void
 **/

void print_digits(int n)
{
	// If number is smaller than 0, put a - sign
	// and change number to positive
	if (n < 0) {
		_putchar('-');
		n = -n;
	}

	// Remove the last digit and recur
	if (n/10)
		print_digits(n/10);

	// Print the last digit
	_putchar(n%10 + '0');
}

/**
 * _puts_recursion - recursion function
 * @s: input string
 * Return: void
 */

void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n');
		return;
	}

	_putchar(*s);
	_puts_recursion(++s);
}
