#include <stdio.h>
#include <stdbool.h>

int c;
int min(int x, int y)
{
    if (x <= y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
//Time Complexcity is : O(n)
void linear_search(int arr[], int key, int size)
{
    bool ok = false;
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
            ok = true;
            break;
        }
    }
    if (ok)
        printf("Number of comparision is %d : \n", count);
    else
    {
        printf("key not found \n");
    }
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
    bool ok = false;
    while (high > low + 1)
    {
        count++;
        int m = (low + (high - low) / 2);
        if (arr[m] >= key)
        {
            low = m;
            if (arr[low] == key)
            {
                ok = true;
                break;
            }
        }
        else
        {
            high = m;
            if (arr[high] == key)
            {
                ok = true;
                break;
            }
        }
    }
    if (ok)
        printf("Number of comparision is : %d \n", count);
    else
    {
        printf("key not found \n");
    }
}
//Time complexcity : O(log(n))
int fibonacci_search_impl(int arr[], int key, int size)
{
    int fib2 = 0, fib1 = 1;
    int fib3 = fib1 + fib2;
    while (fib3 < size)
    {
        fib2 = fib1;
        fib1 = fib3;
        fib3 = fib1 + fib2;
    }
    int mark = -1;
    c = 0;
    while (fib3 > 1)
    {
        c++;
        int temp = min(mark + fib2, size - 1);
        if (arr[temp] < key)
        {
            fib3 = fib1;
            fib1 = fib2;
            fib2 = fib3 - fib1;
            mark = temp;
        }
        else if (arr[temp] > key)
        {
            fib3 = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib3 - fib1;
        }
        else
        {
            return temp;
        }
    }
    if (fib1 && arr[mark + 1] == key)
    {
        c++;
        return mark + 1;
    }
    return -1;
}
void fibonacci_search(int arr[], int key, int size)
{
    int res = fibonacci_search_impl(arr, key, size);
    if (res == -1)
    {
        printf("Key not found \n");
    }
    else
    {
        printf("Number of Comparision is : %d \n", c);
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Enter 1 for Linear Search : \n");
    printf("Enter 2 For Binary Search : \n");
    printf("Enter 3 For Fibonacci Search : \n");
    int choice;
    scanf("%d", &choice);
    int key;
    printf("Enter the Key : \n");
    scanf("%d", &key);
    switch (choice)
    {
    case 1:
        linear_search(arr, key, size);
        break;
    case 2:
        binary_search(arr, key, size);
        break;
    case 3:
        fibonacci_search(arr, key, size);
        break;
    default:
        printf("You have entered wrong choice \n");
    }
    return 0;
}