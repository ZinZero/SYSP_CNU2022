#include "diary.h"

int main(void) {
	int result = 0;
	int a = 5, b = 3;
	
	result = funcAdd(a, b);
	printf("%d + %d = %d\n", a, b, result);
	result = funcSub(a, b);
	printf("%d - %d = %d\n", a, b, result);
	result = funcMul(a, b);
	printf("%d * %d = %d\n", a, b, result);
	result = funcDiv(a, b);
	printf("%d / %d = %d\n", a, b, result);

	memo();
	calendar();

	return 0;
}
