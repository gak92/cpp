# include <stdio.h>

int Linear_Search(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if(target == arr[i])
        {
            return i;
        }
    }
    return -1;    
}

int Binary_Search(int arr[], int size, int target)
{
    int low = 0, mid, high = size - 1;

    while(low<=high)
    {
        mid = (low + high) / 2;
        if(arr[mid] == target)
        {
            return mid;
        }
        if(arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        
    }
    return -1;

}


int main(void)
{
    int arr1[] = {54, 58, 5, 7, 87, 92, 45, 36, 22, 69, 11};
    int arr2[] = {1, 3, 7, 11, 19, 21, 27, 40, 41, 63, 70, 92, 99};
    int size_of_arr1 = sizeof(arr1)/sizeof(int);
    int size_of_arr2 = sizeof(arr2)/sizeof(int);
    printf("Size of arr1= %d and size of arr2= %d\n", size_of_arr1, size_of_arr2);

    int target = 11;
    int Index_of_target;

    // ***********************************************************FOR LINEAR SEARCH
    printf("\nLinear Search run at arr1\n");
    Index_of_target = Linear_Search(arr1, size_of_arr1, target);
    if(Index_of_target>=0)
    {
        printf("Target '%d' found at index = %d \n", target, Index_of_target);
    }
    else
    {
        printf("Not Found");
    }
    

    // ***********************************************************FOR BINARY SEARCH
    // For Binary Search Array Should be sorted so we use arr2 here:
    printf("\nBinary Search run at arr2\n");
    Index_of_target = Binary_Search(arr2, size_of_arr2, target);
    if(Index_of_target>=0)
    {
        printf("Target '%d' found at index = %d \n", target, Index_of_target);
    }
    else
    {
        printf("Not Found");
    }
    

    return 0;
}