#include <stdio.h>

int linearSearch(int A[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (A[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int A[] = {10, 50, 30, 70, 80, 20, 90, 40};
    int n = sizeof(A) / sizeof(A[0]);
    int target = 70;

    int result = linearSearch(A, n, target);

    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}