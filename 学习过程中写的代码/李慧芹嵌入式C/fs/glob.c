#include <stdio.h>
#include <stdlib.h>
#include <glob.h>

// #define PAT "/etc/a*.conf"
#define PAT "/etc/.*"

#if 0
static int errfunc_(const char *errpath, int eerrno) {
    puts(errpath);
    fprintf(stderr, "ERROR MSG:%s\n", strerror(eerrno));
    return 0;
}
#endif

int main(int argc, char **argv) {

    glob_t globers;
    int err;
    int i;

    err = glob(PAT, 0, NULL, &globers);
    if (err) {
        printf("Error code = %d\n", err);
        exit(1);
    }

    for (i = 0; i < globers.gl_pathc; ++i) {
        puts(globers.gl_pathv[i]);
    }

    exit(0);
}
