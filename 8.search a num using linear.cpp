#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50,60,70,80};
    int key;
    
    printf("Enter number to search: ");
    scanf("%d", &key);

    int result = linearSearch(arr, 7, key);
    if (result != -1)
        printf("Found at index %d\n", result);
    else
        printf("Not found\n");

    return 0;
}

