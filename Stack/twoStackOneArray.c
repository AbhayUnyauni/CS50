#include<stdio.h>
#include<cs50.h>
#include<string.h>

int main(){
    int n;
    n = get_int("Enter the size of the array: ");
    if(n <= 0){
        printf("Invalid size\n");
        return 1;
    }

    int arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = 0;
    }
    int left = 0;
    int right = n-1;

    printf("--------General Instruction--------\n");
    printf("1) Operation: Push, Pop, Print, Exit\n");
    printf("2) Side: A for left & B for right\n");

    while(true){
        string command = get_string("\n Enter Command: Push, Pop, Print, Exit: ");
        if(strcmp(command, "exit") == 0){
            break;
        }
        if(strcmp(command, "print") == 0){
            for(int i = 0; i < n; i++){
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
        string side = get_string("From which side: Left or Right: ");

        if(strcmp(command, "push") == 0)
        {
            int num = get_int("Enter the number to push: ");
            if(strcmp(side, "left") == 0){
                if(left > right){
                    printf("OVERFLOW on LEFT, can't push %d\n", num);
                } else
                {
                    arr[left] = num;
                    left++;
                    printf("Pushed %d on LEFT\n", num);
                }
            }
            else if(strcmp(side, "right") == 0)
            {
                if(left > right){
                    printf("OVERFLOW on RIGHT, can't push %d\n", num);
                } else
                {
                    arr[right] = num;
                    right--;
                    printf("Pushed %d on RIGHT\n", num);
                }
            }
            else
            {
                printf("Invalid side!\n");
            }
        }
        else if(strcmp(command, "pop") == 0){
            if(strcmp(side, "left") == 0){
                if(left == 0){
                    printf("UNDERFLOW on LEFT, nothing to pop\n");
                }
                else
                {
                    left--;
                    printf("Poped %d from left\n", arr[left]);
                }
            }
            else if(strcmp(side, "right") == 0){
                if(right == n - 1){
                    printf("UNDERFLOW on RIGHT, nohting to pop\n");
                }
                else
                {
                    right++;
                    printf("Popped %d from right\n", arr[right]);
                }
            }
            else
            {
                printf("Invalid side!\n");
            }
        }
       
        else{
            printf("Invalid operation\n");
        }
        printf("\n");
    }
    return 0;
}
