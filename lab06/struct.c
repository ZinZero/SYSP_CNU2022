#include <stdio.h>

struct foo_s {
    int a;
    char b;
};

struct bar_s {
    char ar[10];
    struct foo_s baz;
};

int main() {
    struct bar_s biz;
    biz.ar[0] = 'a';
    biz.baz.a = 42;
    printf("biz.ar[0] : %c, biz.baz.a : %d \n", biz.ar[0], biz.baz.a);

    struct bar_s* boz = &biz;
    boz->baz.b = 'b';
    printf("boz->baz.b : %c \n", boz->baz.b);

    return 0;
}