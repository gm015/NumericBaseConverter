#include <stdio.h>
#define DEBUG printf

void	convert(int x, char bin[]) {

	// reset values
	bin[0]='0';
	bin[1]='0';
	bin[2]='0';
	bin[3]='0';
	bin[4]='0';
	bin[5]='0';
	bin[6]='0';
	bin[7]='0';
	bin[8]='\0';

	int i = 0, pos = x;
	for (; x >> i; ++i) {
		pos = x >> i;
		if (pos & 0x01)
			bin[7 - i] = '1';
		//DEBUG("[ %d ] pos: %d\n",i,pos);
	}

}

int main() {
	__int8_t	 m[] = {128,64,32,16,8,4};
	__int8_t	 n[] = {256, 255, 150, 149, 99, 33};
	__int8_t	 o[] = {-1,-2,-4,-127,0,-128};

	char	a[7][9] = {0};

	// TEST
	int i = 1, j = 0;
	while (i < 128) {
		i *= 2;
		convert(i,a[j]);
		DEBUG("i:[%d] value: %s\n", i,(char *)a[j]);
		j += 1;
	}
	

	return 0;
}

// 0101 0101
// 0000 0001
//
// 1010 1010

