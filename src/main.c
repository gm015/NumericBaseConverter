#include "header.h"

/*
 * @param: input args of the program
 *	1: --b  --s[8/16/32/64]  / --x --[u/U] / --o
 *  2: $ARG
 */

int main(int argc, char **argv) {

	// input error
	 if (argc < 3) {
		LOG(stderr, RED "Invalid input. Two arguments needed.\n" CLEAR);
		return 1;
	}

	// process into necessary system: binary / hexadecimal / octal
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
