#include "main.h"

/**
 * print_alphabet - a function that prints alphabets
 * 
 * Return: nothing
 */

void print_alphabet(void)
{
	char i;
	
	for ( i = 'A'; i <= 'Z'; i++)
	{
		_putchar(i);
	}
	_putchar('\n');
}