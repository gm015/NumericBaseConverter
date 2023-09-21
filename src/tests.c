#include "header.h"

static void	run_tests(char arr[][BIT_SIZE + 1], int num_arr[], int size) {

	LOG(stdout, "\n");
	for (int i = 0; i < size; ++i) {
		convert(arr[i], num_arr[i]);
		LOG(stdout, "arr:[%d] %-4d : %s\n", i,num_arr[i], (char *)&arr[i]);
	}
}

// tests
void	tests() {

	char	output_format[7][BIT_SIZE + 1] = {0};

	int	 m[] = {128,64,32,16,8,4,2};
	int	 n[] = {256, 255, 150, 149, 99, 33,22};
	int	 o[] = {-1,-2,-4,-127,0,-128, -129};

	// 1. TEST
	int i = 1, j = 0;
	while (i < 128) {
		i *= 2;
		convert(output_format[j], i);
		LOG(stdout, "arr:[%-3d] binary value : %s\n", i,(char *)output_format[j]);
		j += 1;
	}

	// NEW TESTS
	LOG(stdout, "\n------   new tests  ------\n");
	int size = sizeof(output_format) / sizeof(output_format[0]);
	run_tests(output_format, m, size);
	run_tests(output_format, n, size);
	run_tests(output_format, o, size);

}

