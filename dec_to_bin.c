#include <stdio.h>
#include <stdlib.h>

#define BIT_SIZE	32
#define LOG			printf

int	invalid_digit(const char *s) {

	int i = 0, skip_neg = 0;
	while (s[i]) {
		if (s[0] == '-' && s[1] != '\0' && !skip_neg)
			++skip_neg;
		else if (s[i] > '9' || s[i] < '0') {
			return 1;
		}
		++i;
	}
	return 0;
}

void	reset_values(char bin[BIT_SIZE]) {

	for (int i = 0; i < BIT_SIZE; ++i)
		bin[i] = '0';
	bin[BIT_SIZE]='\0';
}

void	convert(char bin[BIT_SIZE + 1], int x) {

	reset_values(bin);

	int i = 0, pos = x;
	for (; x >> i && i < BIT_SIZE; ++i) {
		pos = x >> i;
		if (pos & 0x01)
			bin[BIT_SIZE - 1 - i] = '1';
#if DEBUG
		LOG("[ %d ] val: %d\n",i,pos);
#endif
	}
}

void	run_tests(char arr[][BIT_SIZE + 1], int num_arr[], int size) {

	LOG("\n");	
	for (int i = 0; i < size; ++i) {
		convert(arr[i], num_arr[i]);
		LOG("arr:[%d] %-4d : %s\n", i,num_arr[i], (char *)&arr[i]);
	}
}


////////////////////////////////////////////////////////////////////

int main(int argc, char **argv) {

	if (argc < 2) {
		LOG("Invalid input. Need at least one argument.\n");
		return 1;
	}

	char	output_format[7][BIT_SIZE + 1] = {0};
	int		max_store = 7;

	if (argc - 1 < max_store)
		max_store = argc - 1;
	for (int i = 0; i < max_store; ++i) {

		if (invalid_digit(argv[i + 1]) == 1) {
			LOG("Invalid number : %s\n", argv[i + 1]);
			continue;
		}
		convert(output_format[i], atoi(argv[i + 1]));
		LOG("input value: [%-3s] -- binary value : %s\n", argv[i+1],(char *)output_format[i]);
	}

	return 0;
}


// tests
////////////////////////////////////////////////////////////////////
void	tests() {

	char	output_format[7][BIT_SIZE + 1] = {0};

	int	 m[] = {128,64,32,16,8,4,2};
	int	 n[] = {256, 255, 150, 149, 99, 33,22};
	int	 o[] = {-1,-2,-4,-127,0,-128, -129};


	// TEST
	int i = 1, j = 0;
	while (i < 128) {
		i *= 2;
		convert(output_format[j], i);
		LOG("arr:[%-3d] binary value : %s\n", i,(char *)output_format[j]);
		j += 1;
	}

	// NEW TESTS
	LOG("\n------   new tests  ------\n");
	int size = sizeof(output_format) / sizeof(output_format[0]);
	run_tests(output_format, m, size);
	run_tests(output_format, n, size);
	run_tests(output_format, o, size);

}

