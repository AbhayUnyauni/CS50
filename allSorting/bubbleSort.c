#include<stdio.h>
#include<cs50.h>

int main(){
    int n;
    n = get_int("Enter the number of elements: ");
    if(n <= 0){
        printf("Invalid number of elements\n");
        return 1;
    }
    int arr[n];

    for(int i = 0; i < n; i++){
        arr[i] = get_int("Enter the value for each: ");
    }

    
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("sorted list: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
