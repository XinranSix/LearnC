#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

void printArray(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {

    int len1 = 10;
    int len2 = 20;

    int *arr1 = (int *)malloc(sizeof(int) * len1);
    int *arr2 = (int *)malloc(sizeof(int) * len2);

    for (int i = 0; i < len1; ++i) {
        arr1[i] = i * 2;
    }
    for (int i = 0; i < len2; ++i) {
        arr2[i] = i * 2 + 1;
    }

    int *tmp = (int *)malloc(sizeof(int) * (len1 + len2));

    int idx = 0;
    for (int i = 0; i < len1; ++i) {
        tmp[idx++] = arr1[i];
    }
    for (int i = 0; i < len2; ++i) {
        tmp[idx++] = arr2[i];
    }

    realloc(arr1, sizeof(int) * len2);
    realloc(arr2, sizeof(int) * len1);

    idx = 0;
    for (int i = 0; i < len2; ++i) {
        arr1[i] = tmp[idx++];
    }
    for (int i = 0; i < len1; ++i) {
        arr2[i] = tmp[idx++];
    }

    printArray(arr1, len2);
    printArray(arr2, len1);

    return 0;
}
