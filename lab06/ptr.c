#include <stdio.h>

int main() {
    int a =10;
    int* a_ptr = &a;
    printf("adr of a : %x, ard of a_ptr : %x\n", &a, a_ptr);
    printf("val of a : %d, val of a_ptr : %d\n", a, *a_ptr);

    a = 20;
    printf("a = 20\n");
    printf("val of a : %d, val of a_ptr : %d\n", a, *a_ptr);

    *a_ptr = 30;
    printf("a_ptr = 30\n");
    printf("val of a : %d, val of a_ptr : %d\n", a, *a_ptr);

    return 0;
}