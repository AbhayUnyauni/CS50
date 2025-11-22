#include<stdio.h>
#include<cs50.h>

int main(){
    int n;
    n = get_int("Enter the number of elements: ");
    if(n <= 0){
        printf("Invalid numer of elements\n");
        return 1;
    }
    int arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = get_int("Enter the value for each: ");
    }
    for(int i = 0; i < n; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
    printf("Sorted array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
