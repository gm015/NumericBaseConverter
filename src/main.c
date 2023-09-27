#include "header.h"

void	binary_format(const char *s, int *pos) {

	// set:
	// - necessary format: 8, 16, 32, 64 0 bit
	// - signed / unsigned int
}

void	hex_format(const char *s, int *pos) {

	// set:
	// - upper / UPPER case
	// functionality
}

void	octal_format(const char *s, int *pos) {

	// functionality
}

/*
 * @param: input args of the program:
 *	1: -b --[s/u] --f[8/16/32/64]  / -x --[u/U] / -o
 *  2: $ARG
 */

 int main(int argc, char **argv) {

	// input error
	if (argc < 3) {
		LOG(stderr, RED "Invalid input. Two arguments needed.\n" CLEAR);
		return 1;
	}

	// heap allocation
	int	max_store = argc - 1;
	char **output_format = malloc(sizeof(*output_format) * max_store);
	if (output_format == NULL) {
		LOG(stderr, RED "Failed to allocate memory\n" CLEAR);
		return 1;
	}

	for (int i = 0; i < max_store; ++i) {
		output_format[i] = malloc(sizeof(char) * (BIT_SIZE + 1));
		if (output_format[i] == NULL) {
			LOG(stderr, RED "Failed to allocate memory\n" CLEAR);
			return 1;
		}
	}

	// parse args' format: binary / hexadecimal / octal
	char opt;
	for (int i = 1; i <= argc; ++i) {
		if (argv[i][0] != '-' || argv[i][1] == '\0') {
			LOG(stderr, RED "invalid argument\n" CLEAR);
			continue;
		}
		opt = argv[i][1];
		switch (opt) {
			case 'b':
				binary_format(argv[i], &i);
			case 'x':
				hex_format(argv[i], &i);
			case 'o':
				octal_format(argv[i], &i);
				break;
			default:
				LOG(stderr, RED "invalid format\n" CLEAR);
		}
	}


	// conversion
	for (int i = 0; i < max_store; ++i) {
		int pos = i + 1;
		if (invalid_digit(argv[pos]) == 1) {
			LOG(stderr, RED "Invalid number : %s%s\n", argv[pos], CLEAR);
			continue;
		}
		convert(output_format[i], atoi(argv[pos]));
		LOG(stdout, "input value: [%-4s] -- binary value: %s%s\n", \
				argv[pos],CYAN,(char *)output_format[i]);
		LOG(stdout, CLEAR);
	}

	// free allocated memory
	for (int i = 0; i < max_store; ++i)
		free(output_format[i]);
	free(output_format);

	return 0;
}

