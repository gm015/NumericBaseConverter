#include "header.h"

/* @param:
 * input_qty -> quantity of a user's input numbers
 * format_len -> length of displayed bytes
 */

char **allocate_mem(unsigned int input_qty, unsigned int format_len) {

	char **final_result = malloc(sizeof(*final_result) * input_qty);
	if (final_result == NULL)
		exit(1);

	for (unsigned int i = 0; i < input_qty; ++i) {
		final_result[i] = malloc(sizeof(char) * (format_len + 1));
		if (final_result[i] == NULL)
			exit(1);
	}
	return final_result;
}

void	free_heap(char **final_result, unsigned int len) {

	for (unsigned int i = 0; i < len; ++i)
		free(final_result[i]);
	free(final_result);
}

/*
 * find the last value of the arg (integer) to convert before new type of format starts
 */

int	find_args_limit(char **argv, unsigned int format_len, unsigned int pos) { 

	int tmp = pos;
	while (argv[tmp] && strncmp("--",argv[tmp], 2) != 0)
		++tmp;
	return tmp;
}

/*
 * set necessary format: 8, 16, 32 or 64 -bit
 */

void	binary_format(char **argv, int *position) {

	int pos = ++(*position);
	if (strncmp("--f", argv[pos], 3) != 0 || argv[pos][3] == '\0') {
		LOG(stderr, RED "invalid format: %s%s\n", argv[pos], CLEAR);
		return ;
	}
	
	// update position for next format
	int	format = atoi((char *)&argv[pos][3]);
	int move_pos = find_args_limit(argv, format, ++pos);
	unsigned int len = move_pos - *position - 1;
	//*position += move_pos;

	// allocate memory
	char **final_result = allocate_mem(len, format);

	// start conversion
	for (unsigned int i = 0; i < len; ++i, ++pos) {

		if (invalid_digit(argv[pos]) == 1) {
			LOG(stderr, RED "invalid integer: %s%s\n", argv[pos], CLEAR);
			continue;
		}
		convert(final_result[i], format, atoi(argv[pos]));
		LOG(stdout, "input value: [%-4s]  binary value: ", argv[pos]); 
		LOG(stdout, CYAN "%s%s\n", final_result[i], CLEAR);
	}

	free_heap(final_result, len);
	*position += pos;
}

void	hex_format(char **argv, int *position) {

	int pos = ++(*position);
	(void)pos;
	return ;
	// set:
	// - upper / UPPER case
	// functionality
}

void	octal_format(char **argv, int *position) {

	int pos = ++(*position);
	(void)pos;
	return ;
	// functionality
}

/*
 * @param: input args of the program
 *	1: --b  --f[8/16/32/64]  / --x --[u/U] / --o
 *  2: $ARG
 */

 int main(int argc, char **argv) {

	// input error
	 if (argc < 3) {
		LOG(stderr, RED "Invalid input. Two arguments needed.\n" CLEAR);
		return 1;
	}

	// process into necessary format: binary / hexadecimal / octal
	char opt;
	for (int pos = 1; pos < argc; ++pos) {

		if (strncmp("--", argv[pos], 2) != 0) {

			LOG(stderr, RED "invalid format: %s%s\n", argv[pos], CLEAR);
			int tmp = pos;
			while (argv[tmp] && strncmp("--",argv[tmp], 2) != 0)
				++tmp;
			pos = tmp;
			continue;
		}
		opt = argv[pos][2];
		switch (opt) {
			case 'b':
				binary_format(argv, &pos);
			case 'x':
				hex_format(argv, &pos);
			case 'o':
				octal_format(argv, &pos);
				break;
			default:
			LOG(stderr, RED "invalid format: %s%s\n", argv[pos], CLEAR);
		}
	}

	return 0;
}

