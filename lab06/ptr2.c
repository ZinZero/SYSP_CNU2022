#include <stdio.h>

void adder1(int a){
    a = a +10;
}

void adder2(int* a) {
    *a = *a + 10;
}

int main() {
    int x = 4;
    adder1(x);
    printf("%d\n", x); // 4

    int y = 54;
    adder2(&y);
    printf("%d\n", y); // 64

    return 0;
}