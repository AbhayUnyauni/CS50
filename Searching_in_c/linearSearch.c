#include<stdio.h>
#include<cs50.h>

int main(){
    int n;
    n = get_int("Enter the length of array: ");
    if(n <= 0){
        printf("Invalid length!\n");
        return 1;
    }
    int arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = get_int("Enter the values: ");
    }
    int search = get_int("Enter the value which you want to search: ");
    for(int i = 0; i < n; i++){
        if(arr[i] == search){
            printf("%d is present at location %d :)\n", search, i+1);
            break;
        } else {
            printf("%d is not in the array :(\n", search);
            break;
        }
    }
    return 0;
}
