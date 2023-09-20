#include <stdio.h>
#define LOG		printf
#define BIT_SIZE	32

// reset values
void	reset_values(char **bin) {

	for (int i = 0; i < BIT_SIZE; ++i)
		bin[0][i] = '0';
	bin[0][BIT_SIZE]='\0';
}

void	convert(int x, char **bin) {

	reset_values(bin);

	int i = 0, pos = x;
	for (; x >> i && i < BIT_SIZE; ++i) {
		pos = x >> i;
		if (pos & 0x01)
			bin[0][BIT_SIZE - 1 - i] = '1';
#ifndef DEBUG
		LOG("[ %d ] pos: %d\n",i,pos);
#endif
	}
}

void	run_tests(char **arr, int num_arr[], int size) {

	LOG("\n");	
	for (int i = 0; i < size; ++i) {
		convert(num_arr[i], &arr[i]);
		LOG("arr:[%d] %-3d : %s\n", i,num_arr[i], (char *)&arr[i]);
	}
}

int main() {

	int	 m[] = {128,64,32,16,8,4,2};
	int	 n[] = {256, 255, 150, 149, 99, 33,22};
	int	 o[] = {-1,-2,-4,-127,0,-128, -129};

	char	a[7][BIT_SIZE + 1] = {0};

	// TEST
//	int i = 1, j = 0;
//	while (i < 128) {
//		i *= 2;
//		convert(i,(char **)&a[j]);
//#ifndef DEBUG
//		LOG("arr:[%-3d] binary value : %s\n", i,(char *)a[j]);
//#endif
//		j += 1;
//	}

	// REAL TESTS
	LOG("\n------   new tests  ------\n");
	int size = sizeof(a) / sizeof(a[0]);
	run_tests((char **)a, m, size);
	run_tests((char **)a, n, size);
	run_tests((char **)a, o, size);

	return 0;
}

