#include "header.h"

/*  convert integer values into binary  */

void	convert_binary(char *bin, int format_size, int x) {

	reset_values(bin, format_size, '0');

	int i = 0;
	for (; i < format_size; ++i) {
		if ((x >> i) & 0x1)
			bin[format_size - 1 - i] = '1';
#if DEBUG_VAL
		LOG(stdout, MAGENTA "[ %d ] val: %d%s\n",i,pos, CLEAR);
#endif
	}
}

/*
 * set necessary format: 8, 16, 32 or 64 -bit
 */

void	binary_format(char **argv, int *position) {

	int pos = ++(*position);
	int exit_code = 0;
	if (strncmp("--s", argv[pos], 3) != 0 || argv[pos][3] == '\0') {
		LOG(stderr, RED "invalid format specifier: %s%s\n", argv[pos], CLEAR);
		exit_code = pos;
	}

	// update position for next format specifier
	unsigned int move_pos = find_args_limit(argv, pos);
	unsigned int len = move_pos - *position;
	*position += len;

	char *inp = (char *)&argv[pos][3]; 
	if (exit_code || invalid_digit(inp) == 1) {
		LOG(stderr, RED "invalid format specifier: %s%s\n", inp, CLEAR);
		return ;
	}

	int	format = atoi(inp);
	char **final_result = allocate_mem(len, format);

	// start conversion
	++pos;
	for (unsigned int i = 0; i < len; ++i, ++pos) {

		if (invalid_digit(argv[pos]) == 1) {
			LOG(stderr, RED "invalid integer: %s%s\n", argv[pos], CLEAR);
			continue;
		}
		convert_binary(final_result[i], format, atoi(argv[pos]));
		LOG(stdout, "input value: [%-4s]  binary value: ", argv[pos]); 
		LOG(stdout, CYAN "%s%s\n", final_result[i], CLEAR);
	}

	free_heap(final_result, len);
}
