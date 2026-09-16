#include <stdio.h>

int main() {
    int a[] = {12, 7, 25, 18, 30, 9};
    int n = 6, key = 18, i, found = -1;

    printf("Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    for(i = 0; i < n; i++) {
        if(a[i] == key) {
            found = i;
            break;
        }
    }

    if(found != -1)
        printf("\n%d found at index %d\n", key, found);
    else
        printf("\n%d not found\n", key);

    return 0;
}