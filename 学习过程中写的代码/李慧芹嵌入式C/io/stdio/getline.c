#include <stddef.h>
#include <string.h>
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    FILE *fp;
    char *linebuf;
    size_t linesize;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen()");
        exit(1);
    }

    // 非常重要
    linebuf = NULL;
    linesize = 0;

    // 注意：此处空间未释放
    while (getline(&linebuf, &linesize, fp) >= 0) {
        printf("%zu\n", strlen(linebuf));
        printf("%zu\n", linesize);
    }

    fclose(fp);

    exit(1);
}
