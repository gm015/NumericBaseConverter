#ifndef CONVERT_VALUES_H
#define CONVERT_VALUES_H

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
void	reset_values(char *arr, int size, char c);
char	**allocate_mem(unsigned int input_qty, unsigned int format_len);
void	free_heap(char **final_result, unsigned int len);
int		find_args_limit(char **argv, unsigned int pos);


// parsing
int		invalid_digit(const char *s);

// convert
void	convert_binary(char *bin, int format_size, int x);
void	convert_hex(char *bin, int format_size, int x);
void	convert_octal(char *bin, int format_size, int x);

void	binary_format(char **argv, int *position);
void	hex_format(char **argv, int *position);
void	octal_format(char **argv, int *position);

// tests
void	tests();

#endif
