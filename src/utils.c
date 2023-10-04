#include "header.h"

int	invalid_digit(const char *s) {

	int i = 0, skip_neg = 0;
	while (s[i])
	{
#if DEBUG_PARS
		LOG(stdout, MAGENTA "char: [%c]%s\n", s[i], CLEAR);
#endif
		if (s[0] == '-' && s[1] != '\0' && !skip_neg)
			++skip_neg;
		else if (s[i] > '9' || s[i] < '0') {
			return 1;
		}
		++i;
	}
	return 0;
}

/*
 * reset values before setting them
 */

void	reset_values(char *arr, int size, char c) {

	int i = 0;
	for (; i < size; ++i)
		arr[i] = c;
	arr[size]='\0';
}

/* @param:
 * input_qty -> quantity of a user's input numbers
 * format_len -> length of displayed bytes
 */

char	**allocate_mem(unsigned int input_qty, unsigned int format_len) {

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

unsigned int	find_args_limit(char **argv, unsigned int pos) {

	int tmp = ++pos;
	while (argv[tmp] && strncmp("--",argv[tmp], 2) != 0)
		++tmp;
	return (tmp - 1);
}

void	store_data() {
	// store data into a file / csv
	//
	//
}
