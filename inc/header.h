#ifndef CONV_BIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BIT_SIZE	32
#define LOG			fprintf

// utils
void	reset_values(char bin[BIT_SIZE]);

// parsing
int		invalid_digit(const char *s);

// convert
void	convert(char bin[BIT_SIZE + 1], int x);

// tests
void	tests();

#endif
