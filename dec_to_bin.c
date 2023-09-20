#include <stdio.h>
#define DEBUG		printf
#define BIT_SIZE	32

// reset values
void	reset_values(char bin[]) {

	for (int i = 0; i < BIT_SIZE; ++i)
		bin[i] = '0';
	bin[BIT_SIZE]='\0';
}

void	convert(int x, char bin[]) {

	reset_values(bin);

	int i = 0, pos = x;
	for (; x >> i && i < BIT_SIZE; ++i) {
		pos = x >> i;
		if (pos & 0x01)
			bin[BIT_SIZE - 1 - i] = '1';
//		DEBUG("[ %d ] pos: %d\n",i,pos);
	}
}

int main() {

	int	 m[] = {128,64,32,16,8,4,2};
	int	 n[] = {256, 255, 150, 149, 99, 33,22};
	int	 o[] = {-1,-2,-4,-127,0,-128, -129};

	char	a[7][BIT_SIZE + 1] = {0};

	// TEST
	int i = 1, j = 0;
	while (i < 128) {
		i *= 2;
		convert(i,a[j]);
		DEBUG("arr:[%-3d] binary value : %s\n", i,(char *)a[j]);
		j += 1;
	}

	// REAL TESTS
	DEBUG("\n------   new tests  ------\n\n");	
	int size = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < size; ++i) {
		convert(m[i],a[i]);
		DEBUG("arr:[%d] %-3d : %s\n", i,m[i],(char *)a[i]);
	}

	DEBUG("\n");	

	for (int i = 0; i < size; ++i) {
		convert(n[i],a[i]);
		DEBUG("arr:[%d] %-3d : %s\n", i,n[i],(char *)a[i]);
	}

	DEBUG("\n");	
	for (int i = 0; i < size; ++i) {
		convert(o[i],a[i]);
		DEBUG("arr:[%d] %-4d : %s\n", i,o[i],(char *)a[i]);
	}
	return 0;
}

