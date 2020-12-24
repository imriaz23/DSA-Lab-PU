#include <stdio.h>
#include <stdbool.h>
//Time Complexcity is : O(n)
void linear_search(int arr[], int key, int size)
{
    if (size <= 0)
    {
        printf("The List is Empty : \n");
    }
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        count++;
        if (arr[i] == key)
        {
            break;
        }
    }
    printf("Number of comparision is %d : \n", count);
}
//Time Complexcity is : log(n)
void binary_search(int arr[], int key, int size)
{
    if (size <= 0)
    {
        printf("The List is empty. \n");
    }
    int low = -1;
    int high = size;
    int count = 0;
    while (high > low + 1)
    {
        int m = (low + (high - low) / 2);
        if (arr[m] >= key)
        {
            low = m;
            count++;
        }
        else
        {
            high = m;
            count++;
        }
    }
    printf("Number of comparision is : %d \n", count);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;
    printf("Enter the Key : \n");
    scanf("%d", &key);
    linear_search(arr, key, size);
    binary_search(arr, key, size);
    return 0;
}