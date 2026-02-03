#include <stdio.h>
#include <stdlib.h>

// swap elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify -> max heap
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if (left<n && arr[left]>arr[largest]){
        largest = left;
    }
    
    if (right < n && arr[right] > arr[largest]){
        largest = right;
    }
    
    if (largest != i) {
        swap(&arr[i],&arr[largest]);
        maxHeapify(arr,n,largest);
    }
}

// Heapify ->min heap
void minHeapify(int arr[], int n, int i) {
    int smallest =i;
    int left =2*i+1;
    int right = 2*i+2;

    if (left < n && arr[left] < arr[smallest]){
        smallest = left;
    }

    if (right < n && arr[right] < arr[smallest]){
        smallest = right;
    }

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

//Build Max Heap
void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

//Builds Min Heap
void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

// Prints the Heap
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements:");
    scanf("%d",&n);

    int *arr = (int *)malloc(n*sizeof(int));
    int *tempArr = (int *)malloc(n*sizeof(int));

    printf("Enter the elements");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        tempArr[i] = arr[i]; // copy of array to use it in min heap
    }

    //max heap
    buildMaxHeap(arr, n);
    printf("\nMax Heap array: ");
    printArray(arr, n);

    //min heap
    buildMinHeap(tempArr, n);
    printf("Min Heap array: ");
    printArray(tempArr, n);


    free(arr);
    free(tempArr);
    return 0;
}