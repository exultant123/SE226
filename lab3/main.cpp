#include <iostream>

void swapValues(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;

}
void printArray(int* arr, int size) {
    printf("Array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr+i));
    }
    printf("\n");
}
int findMax(int* arr, int size) {
    int max = -1;
    for (int i = 0; i < size; i++) {
        if (max<*(arr+i)) max = *(arr+i);
    }
    return max;
}
void reverseArray(int* arr, int size) {

        int n = size-1;
        for (int i = 0; i < size/2; i++) {
            swapValues(arr+i,arr+n);
            --n;
        }

}

int* createArray(int size) {
    int *arr = (int*)malloc(sizeof(int)*size);
    return arr;
}
void deleteArray(int* arr) {
    free(arr);
    arr = NULL;
}
int main() {

    printf("Creating dynamic array...\n");
    printf("Enter array size: ");
    int size = 0;
    scanf("%d", &size);
    int* arr = createArray(size);
    printf("Enter values: ");
    for (int i=0; i<size; ++i) {
        int x;
        scanf("%d", &x);
        *(arr+i) = x;
    }
    printArray(arr,size);
    printf("\n");
    int m = findMax(arr,size);
    printf("Maximum element: %d\n", m);
    printf("\n----------------------------------\n");
    int a=5; int b = 9;
    printf("Swapping two numbers\n");
    printf("Before swap\n");
    printf("a = %d\n",a);
    printf("b = %d\n",b);
    swapValues(&a,&b);
    printf("After swap\n");
    printf("a = %d\n",a);
    printf("b = %d\n",b);
    printf("\n----------------------------------\n");
    printf("Reversing array...\n");
     printf("Array after reverseArray:\n");
    reverseArray(arr,size);
    printArray(arr,size);
    printf("Deleting array...\n");
    deleteArray(arr);
    printf("Memory released successfully.");
}