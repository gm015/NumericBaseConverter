#ifndef CONV_BIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	test_unsigned_int();

#define LOG			fprintf

//colors
#define CYAN		"\x1b[36m"
#define MAGENTA		"\x1b[35m"
#define RED			"\x1b[31m"
#define CLEAR		"\x1b[0m"

// utils
void	reset_values(char *arr, int size);

// parsing
int		invalid_digit(const char *s);

// convert
void	convert(char *bin, int format_size, int x);

// tests
void	tests();

#endif
