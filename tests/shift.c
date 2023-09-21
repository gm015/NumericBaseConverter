#include <stdio.h>

void    shift(int x) {

    int i = 0;
    printf(" value: %d\n",x);
    while (x >>= 1) {
    //while (x > 0) {
        //`x = x >> 1;
        printf("[ %d ] value: %d\n",i,x);
        ++i;
    }
}

int is_even(int x) {

    int i = 0, tmp = 0;
    for (; (tmp = x >> i); ++i)
        printf("[ %d ] value: %d\n",i,tmp);
    return i;
}

int main() {
    int a[] = {4096,256,255,2,1,0};

    shift(a[0]);
    shift(a[1]);
    shift(a[2]);

    printf("\nODD or EVEN:\n");
    printf("result for %d  is: %d\n", a[0], is_even(a[0]));       // 4096
    printf("result for %d  is: %d\n", a[1], is_even(a[1]));       // 256
    printf("result for %d  is: %d\n", a[2], is_even(a[2]));       // 255
    printf("result for %d  is: %d\n", a[3], is_even(a[3]));       // 2
    printf("result for %d  is: %d\n", a[4], is_even(a[4]));       // 1
    printf("result for %d  is: %d\n", a[5], is_even(a[5]));       // 0
    return 0;                                    
}

