#include <stdio.h>

int main() {
    int nResult = 0;
    int nAlpha = 5, nBeta = 3;

    nResult = funcAdd(nAlpha, nBeta);
    printf("%d + %d = %d\n", nAlpha, nBeta, nResult);
    nResult = funcSub(nAlpha, nBeta);
    printf("%d - %d = %d\n", nAlpha, nBeta, nResult);
    return 0;
}