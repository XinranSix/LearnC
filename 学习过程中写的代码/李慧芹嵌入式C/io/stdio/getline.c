#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

    FILE *fp;
    char *linebuf;
    size_t linesize;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[1]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen()");
        exit(1);
    }

    /*非常有必要*/
    linebuf = NULL;
    linesize = 0;

    while (1) {
        if (getline(&linebuf, &linesize, fp) < 0) {
            break;
        }
        printf("%ld\n", strlen(linebuf));
        printf("%ld\n", linesize);
    }

    fclose(fp);

    return 0;
}
