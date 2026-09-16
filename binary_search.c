#include <stdio.h>

int main() {
    int a[] = {4, 10, 15, 18, 23, 32};
    int n = 6, key = 23;
    int low = 0, high = n - 1, mid, found = -1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (a[mid] == key) {
            found = mid;
            break;
        }
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("Array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    if(found != -1)
        printf("\n%d found at index %d\n", key, found);
    else
        printf("\n%d not found\n", key);

    return 0;
}