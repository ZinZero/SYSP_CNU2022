#include <stdio.h>

int main() {
    int nResult = 0;
    int nAlpha = 6, nBeta = 2;

    nResult = funcMul(nAlpha, nBeta);
    printf("%d * %d = %d\n", nAlpha, nBeta, nResult);
    nResult = funcDiv(nAlpha, nBeta);
    printf("%d / %d = %d\n", nAlpha, nBeta, nResult);
    return 0;
}
