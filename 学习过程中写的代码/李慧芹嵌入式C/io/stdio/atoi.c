#include <stdio.h>
#include <stdlib.h>

int main() {
    char buf[1024];
    int year = 2014, month = 5, day = 13;

    sprintf(buf, "%d-%d-%d\n", year, month, day);

    fputs(buf, stdout);

    // char str[] = "123a456";
    // printf("%d\n", atoi(str));

    return 0;
}
