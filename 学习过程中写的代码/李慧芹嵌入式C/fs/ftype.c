#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

static int ftype(const char *fname) {

    struct stat statres;

    if (stat(fname, &statres) < 0) {
        perror("stat()");
        exit(1);
    }
    if (S_ISREG(statres.st_mode)) { // regular file
        return '-';
    }
    if (S_ISDIR(statres.st_mode)) { // directory
        return 'd';
    }
    if (S_ISCHR(statres.st_mode)) { // block devuce
        return 'c';
    }
    if (S_ISBLK(statres.st_mode)) { // block device
        return 'b';
    }
    if (S_ISFIFO(statres.st_mode)) { // named pipe
        return 'p';
    }
    if (S_ISLNK(statres.st_mode)) { // symbolic link
        return 'l';
    }
    if (S_ISSOCK(statres.st_mode)) { // socket
        return 's';
    }
    return '?';
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_name>", argv[0]);
        exit(1);
    }

    printf("%c\n", ftype(argv[1]));

    exit(0);
}
