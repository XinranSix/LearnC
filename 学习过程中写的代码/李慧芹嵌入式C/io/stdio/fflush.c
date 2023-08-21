#include <stdio.h>
#include <stdlib.h>

int main(int avgc, char **argv) {

    int i;

    printf("Before while()");
    fflush(stdout);

    while (1)
        ;

    printf("Before while()");
    fflush(NULL);

    exit(0);
}
