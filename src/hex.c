#include "header.h"

/*  convert integer values into hexadecimal  */

void	mod(char *bin, int x, int pos) {

		int mod = x % 16;
		if (mod > 15)
			bin[pos] = mod - 9 + 'A';
		else
			bin[pos] = mod + '0';
}

void	convert_hex(char *bin, int x) {

	int lvl = 0, num = x;
	while ((num /= 16) > 0)
		++lvl;
	reset_values(bin, 20, ' ');

	int i = 0, pos = 0;
	*(bin + pos++) = '0';
	*(bin + pos++) = 'x';
	for (; i < lvl; ++i, ++pos) {	
		//int new_x = 0;

		x = x / 16;
		if (x > 15) {
			mod(bin, x, pos);
			x = x / 16;
		}
		else if (x > 9)
			bin[pos] = x - 9 + 'A';
		else
			bin[pos] = x + '0';
		mod(bin, x, pos);
#if DEBUG_VAL
		LOG(stdout, MAGENTA " [lvl: %d / %d] [x: %d] [pos: %d] %s\n",i,lvl,x,pos, CLEAR);
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

	// update position for next format specifier
	unsigned int move_pos = find_args_limit(argv, pos);
	unsigned int len = move_pos - *position;
	*position += len;

	int tmp_size = 20;
	// allocate memory
	char **final_result = allocate_mem(len, tmp_size);

	// start conversion
	for (unsigned int i = 0; i < len; ++i, ++pos) {

		if (invalid_digit(argv[pos]) == 1) {
			LOG(stderr, RED "invalid integer: %s%s\n", argv[pos], CLEAR);
			continue;
		}
		convert_hex(final_result[i], atoi(argv[pos]));
		LOG(stdout, "input value: [%-4s]  hexadecimal value: ", argv[pos]); 
		LOG(stdout, CYAN "%s%s\n", final_result[i], CLEAR);
	}

	free_heap(final_result, len);
}
