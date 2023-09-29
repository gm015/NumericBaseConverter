#include "header.h"

/*			start conversion		*/
int	find_args_limit(char **argv, int format_len, int pos) { 

	int tmp = pos;
	while (argv[tmp] && strncmp("--",argv[tmp], 2) != 0) {
		++tmp;
	}
	LOG(stdout, "values: format_len = %d, arg[%d], tmp = %d \n",format_len, pos,tmp);

	for (; pos < tmp; ++pos) {
		LOG(stdout, "argv[%d]: %s \n",pos,argv[pos]);
	}
	return pos;
}

// set necessary format: 8, 16, 32, 64 -bit
void	binary_format(char **argv, int *position) {

	int pos = ++(*position);
	if (strncmp("--f", argv[pos], 3) != 0 || argv[pos][3] == '\0'){	// TODO remove last check if not needed
		LOG(stderr, RED "invalid %s format%s\n", argv[pos], CLEAR);
		return ;
	}
	
	int	format = atoi((char *)&argv[pos][3]);
	int move_pos = find_args_limit(argv, format, ++pos);
	*position += move_pos;
}

void	hex_format(char **s, int *pos) {

	// set:
	// - upper / UPPER case
	// functionality
}

void	octal_format(char **s, int *pos) {

	// functionality
}

/*
 * @param: input args of the program:
 *	1: -b  --f[8/16/32/64]  / -x --[u/U] / -o
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
	for (int pos = 1; pos <= argc; ++pos) {

		if (argv[pos] && strncmp("--", argv[pos], 2) != 0) {
			//|| argv[pos][2] != '\0') {
			LOG(stderr, RED "invalid format\n" CLEAR);
			++pos;
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
				LOG(stderr, RED "invalid format\n" CLEAR);
		}
	}

	return 0;
}

