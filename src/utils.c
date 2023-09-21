#include "header.h"

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
	for (; (pos = x >> i) && i < BIT_SIZE; ++i) {
		if (pos & 0x01)
			bin[BIT_SIZE - 1 - i] = '1';
#if DEBUG
		LOG(stdout, "[ %d ] val: %d\n",i,pos);
#endif
	}
}
