#include <stdio.h>

int main(int arvc, char *argv[]) {

    int a;

    a = __builtin_expect(3, 1);
    printf("a = %d\n", a);

    a = __builtin_expect(3, 10);
    printf("a = %d\n", a);

    a = __builtin_expect(3, 100);
    printf("a = %d\n", a);

    return 0;
}
