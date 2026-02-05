#include<stdio.h>
#include<stdlib.h>

long long comparisons = 0;
long long swaps = 0;

// swap function
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
    swaps++;
}

// selection sort
void selectionSort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            comparisons++;
            if(a[j] < a[min])
                min = j;
        }
        if(min != i)
            swap(&a[i], &a[min]);
    }
}

// bubble sort
void bubbleSort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            comparisons++;
            if(a[j] > a[j + 1])
                swap(&a[j], &a[j + 1]);
        }
    }
}

// insertion sort
void insertionSort(int a[], int n){
    for(int i = 1; i < n; i++){
        int key = a[i];
        int j = i - 1;
        while(j >= 0){
            comparisons++;
            if(a[j] > key){
                a[j + 1] = a[j];
                swaps++;
                j--;
            } else
                break;
        }
        a[j + 1] = key;
    }
}

// merge function
void merge(int a[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for(int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2){
        comparisons++;
        if(L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while(i < n1)
        a[k++] = L[i++];

    while(j < n2)
        a[k++] = R[j++];
}

// merge sort
void mergeSort(int a[], int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

// print array
void printArray(int a[], int n){
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(){
    int n, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    // generate random numbers
    for(int i = 0; i < n; i++)
        a[i] = rand() % 1000 + 1;

    printf("\nArray before sorting:\n");
    printArray(a, n);

    printf("\nChoose sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    comparisons = swaps = 0;

    switch(choice){
        case 1:
            bubbleSort(a, n);
            break;
        case 2:
            selectionSort(a, n);
            break;
        case 3:
            insertionSort(a, n);
            break;
        case 4:
            mergeSort(a, 0, n - 1);
            break;
        default:
            printf("Invalid choice\n");
            return 0;
    }

    printf("\nArray after sorting:\n");
    printArray(a, n);

    printf("\nTotal comparisons: %lld\n", comparisons);
    if(choice != 4)
        printf("Total swaps: %lld\n", swaps);
    else
        printf("Total swaps: Not applicable for Merge Sort\n");

    return 0;
}
