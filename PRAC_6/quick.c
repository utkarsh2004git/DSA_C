#include<stdio.h>
#include<stdlib.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
       
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr_size;
    
    printf("Enter the size of the array: ");
    scanf("%d", &arr_size);
   
    int *arr = (int *)malloc(arr_size * sizeof(int));
    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < arr_size; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Given array: \n");
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);

    quickSort(arr, 0, arr_size - 1);

    printf("\nSorted array: \n");
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
   
    free(arr);

    return 0;
}