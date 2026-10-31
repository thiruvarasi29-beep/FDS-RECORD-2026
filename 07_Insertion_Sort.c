#include <stdio.h>

/* Function to print the array elements */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\\n");
}

/* Function to implement insertion sort */
void insertionSort(int arr[], int size)
{
    int key, j;
    int i;

    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
        printArray(arr, size);
    }
}

int main()
{
    int data[] = {12, 11, 13, 5, 6};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Original array:\\n");
    printArray(data, size);
    insertionSort(data, size);
    printf("Sorted array in ascending order:\\n");
    printArray(data, size);

    return 0;
}
