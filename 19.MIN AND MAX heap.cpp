#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] < arr[smallest]) smallest = left;
    if (right < n && arr[right] < arr[smallest]) smallest = right;
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void heapSort(int arr[], int n, int ascending) {
    for (int i = n / 2 - 1; i >= 0; i--)
        ascending ? maxHeapify(arr, n, i) : minHeapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        ascending ? maxHeapify(arr, i, 0) : minHeapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7}, n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    heapSort(arr, n, 1);
    printf("\nSorted ascending: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    heapSort(arr, n, 0);
    printf("\nSorted descending: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    return 0;
}

