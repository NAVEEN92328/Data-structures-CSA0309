#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50}, key;
    printf("Enter number to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, 5, key);
    if (result != -1) printf("Found at index %d\n", result);
    else printf("Not found\n");

    return 0;
}

