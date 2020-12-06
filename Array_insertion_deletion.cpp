# include <stdio.h>
// # include <stdlib.h>

void Display(int arr[], int size)
{
    printf("Array Elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int InsertAt(int arr[], int size, int capacity, int index, int element)
{
    if(size >= capacity)
    {
        return -1;
    }
    for (int i = size-1; i >= index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
    
}

int DeleteAt(int arr[], int size, int index)
{
    if(index >= size)
    {
        return -1;
    }
    for (int i = index; i < size-1; i++)
    {
        arr[i] = arr[i+1];
    }
    
    return 1;
}

int main(void)
{
    int const capacity = 100;
    int arr[capacity] = {1, 2, 3, 11, 19, 27, 40, 41};
    int size = 8;

    Display(arr, size);

    // *******************************INSERT OPERATION
    int index = 5;
    int element = 21;
    int isSuccess;
    isSuccess = InsertAt(arr, size, capacity, index, element);
    
    if(isSuccess)
    {
        size++;
        printf("After Insertion Element= %d at index= %d : \n", element, index);
        Display(arr, size);
    }
    else
    {
        printf("Error at Insertion");
        Display(arr, size);
    }
    
    // *******************************DELETION OPERATION
    index = 3;
    isSuccess = DeleteAt(arr, size, index);

    if(isSuccess)
    {
        size--;
        printf("After Deletion at index %d: \n", index);
        Display(arr, size);
    }
    else
    {
        printf("Deletion Error or Index Out of Range");
    }
    

    return 0;
}