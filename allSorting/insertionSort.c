#include<stdio.h>
#include<cs50.h>

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++) {
        int curr = arr[i];
        int prev = i - 1;

        while(prev >= 0 && arr[prev] > curr){
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}
void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int n;
    n = get_int("Enter the size of array: ");
    if(n <= 0){
        printf("Invalid size!\n");
        return 1;
    }
    int arr[n];
    for(int i = 0; i < n; i++) {
        arr[i] = get_int("Enter the values: ");
    }
    insertionSort(arr, n);
    printArray(arr, n);
}
