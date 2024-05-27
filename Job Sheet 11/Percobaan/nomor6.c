#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main(void)
{
    int arr[] = {1, 3, 55, 92, 21, 24, 55};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 55;
    int result = binarySearch(arr, 0, n - 1, x);

    system("cls");
    if (result == -1)
    {
        printf("[ Elemen tidak ditemukan dalam array! ]");
    }
    else
    {
        printf("[ Elemen ditemukan pada indeks ke-%d ]", result);
    }
    return 0;
}