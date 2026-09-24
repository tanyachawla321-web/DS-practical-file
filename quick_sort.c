#include <stdio.h>

void quickSort(int arr[], int low, int high)
{
    int i, j, pivot, temp;

    if (low < high)
    {
        pivot = arr[low];
        i = low;
        j = high;

        while (i < j)
        {
            while (arr[i] <= pivot && i < high)
                i++;

            while (arr[j] > pivot)
                j--;

            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;

        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}

int main()
{
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("Sorted array in ascending order:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}