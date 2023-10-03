#include "header.h"

/*  convert integer values into hexadecimal  */

void	convert_hex(char *bin, int format_size, int x) {

	reset_values(bin, format_size, ' ');

	int i = 0, pos = 0;
	*(bin + pos++) = '0';
	*(bin + pos++) = 'x';
	for (; (x >>= i) && i < format_size; i+=4, ++pos) {
		if (x & 0x1)
			bin[pos] = '*';
#if DEBUG_VAL
		LOG(stdout, MAGENTA "[ %d ] val: %d%s\n",i,pos, CLEAR);
#endif
	}
}

/*
 * print hexadecimal values
 */

void	hex_format(char **argv, int *position) {

	int pos = ++(*position);
	if (strncmp("--U", argv[pos], 3) != 0 || strncmp("--u", argv[pos], 3) != 0) {
		LOG(stderr, RED "invalid format specifier: %s%s\n", argv[pos], CLEAR);
		return ;
	}
	
	// update position for next format
	int move_pos = find_args_limit(argv, ++pos);
	unsigned int len = move_pos - *position - 1;

	// allocate memory
	char **final_result = allocate_mem(len, 20);

	// start conversion
	for (unsigned int i = 0; i < len; ++i, ++pos) {

		if (invalid_digit(argv[pos]) == 1) {
			LOG(stderr, RED "invalid integer: %s%s\n", argv[pos], CLEAR);
			continue;
		}
		convert_hex(final_result[i], 20, atoi(argv[pos]));
		LOG(stdout, "input value: [%-4s]  hexadecimal value: ", argv[pos]); 
		LOG(stdout, CYAN "%s%s\n", final_result[i], CLEAR);
	}

	free_heap(final_result, len);
	*position += pos;
}
