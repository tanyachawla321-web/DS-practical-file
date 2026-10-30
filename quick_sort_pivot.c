
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int a[], int low, int high, int choice)
{
    int pivotIndex, pivot, i, j, temp;

    // Select pivot
    if (choice == 1)
        pivotIndex = low;
    else if (choice == 2)
        pivotIndex = high;
    else
        pivotIndex = low + rand() % (high - low + 1);

    // Move pivot to last position
    temp = a[pivotIndex];
    a[pivotIndex] = a[high];
    a[high] = temp;

    pivot = a[high];
    i = low - 1;

    // Partitioning
    for (j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    // Place pivot at correct position
    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    int pi = i + 1;

    // Display partition details
    printf("\nPivot Element: %d\n", pivot);

    printf("Left Section: ");
    if (low == pi - 1)
        printf("None");

    for (j = low; j < pi; j++)
        printf("%d ", a[j]);

    printf("\nRight Section: ");
    if (pi == high)
        printf("None");

    for (j = pi + 1; j <= high; j++)
        printf("%d ", a[j]);

    printf("\n-------------------------\n");

    return pi;
}

void quickSort(int a[], int low, int high, int choice)
{
    if (low < high)
    {
        int pi = partition(a, low, high, choice);

        quickSort(a, low, pi - 1, choice);
        quickSort(a, pi + 1, high, choice);
    }
}

int main()
{
    int a[100], n, i, choice;

    srand(time(0));

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
    {
        printf("Invalid array size!");
        return 0;
    }

    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nChoose Pivot Element:");
    printf("\n1. First Element");
    printf("\n2. Last Element");
    printf("\n3. Random Element");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 3)
    {
        printf("Invalid choice!");
        return 0;
    }

    printf("\nQUICK SORT PARTITION DETAILS\n");

    quickSort(a, 0, n - 1, choice);

    printf("\nFinal Sorted Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    return 0;
}
