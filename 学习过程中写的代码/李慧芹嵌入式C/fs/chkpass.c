#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <shadow.h>
#include <string.h>

int main(int argc, char **argv) {

    char *crypted_pass;
    char *input_pass;
    struct spwd *shadowline;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <>", argv[0]);
        exit(1);
    }

    input_pass = getpass("Password:");

    getspnam(argv[1]);

    crypted_pass = crypt(input_pass, shadowline->sp_pwdp);

    if (strcmp(shadowline->sp_pwdp, crypted_pass) == 0) {
        puts("ok!");
    } else {
        puts("faile!");
    }

    exit(0);
}
