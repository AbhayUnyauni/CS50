#include<stdio.h>
#include<cs50.h>

int main(){
    int n = get_int("Enter the lenght of array:");
    if(n <= 0){
        printf("Invalid length!\n");
        return 1;
    }
    int arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = get_int("Enter the value of each: ");
    }
//sorting elements in ascending order using the bubble sort algorithm-->

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

//binary search starts here-->
    int search = get_int("Enter the number which you want to search: ");
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
         if (search == arr[mid]) {
            printf("Found %d at index %d\n", search, mid+1);
            return 0;
        }
        if(search > arr[mid]){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    printf("Value not found.\n");
    return 0;
}
