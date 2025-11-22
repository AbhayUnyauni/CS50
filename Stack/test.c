#include<stdio.h>

int compare(char str1[], char str2[]){
    int i = 0;
    while(str1[i] != '\0' && str2[i] != '\0'){
        if(str1[i] != str2[i]){
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}
int main(){
    int n, num;
    char side[100];
    char side1[] = "left";
    char side2[] = "right";
    char cmd1[] = "push";
    char cmd2[] = "pop";
    char cmd3[] = "print";
    char cmd4[] = "exit";
    char command[100];

    printf("Enter the length of array: ");
    scanf("%d", &n);
    if(n <= 0){
        printf("Invalid length!!\n");
        return 1;
    }
    int arr[n];
    for(int i = 0; i < n; i++){
       arr[i] = 0;
    }
    int left = 0;
    int right = n - 1;

    printf("General Instructions->>\n");
    printf("1) Operation = (push or pop)\n");
    printf("2) Side = (A) for left and (B) for right\n\n");

    while(1)
    {

        printf("What is the operation ? Push/Pop/Print or 'exit' to quit: ");
        scanf("%s", command);
        if(compare(command, cmd4) == 0)
        {
            printf("Exitting program....\n");
            break;
        }
        if(compare(command, cmd3) == 0){
            for(int i = 0; i < n; i++){
                printf("%d ", arr[i]);
            }
            printf("\n");
            continue;
        }

        printf("From which side: (Left/Right): ");
        scanf("%s", side);

        if(compare(command, cmd1)== 0)
        {
            printf("Enter the number which you want to push: ");
            scanf("%d", &num);

            if(compare(side, side1) == 0)
            {
                if(left > right)
                {
                    printf("OVERFLOW on LEFT! Cannot push %d\n", num);
                }
                else
                {
                    for(int i = left; i > 0; i--)
                    {
                        arr[i] = arr[i-1];
                    }
                    arr[0] = num;
                    left++;
                    printf("Pushed on LEFT.\n");
                }
            }
            else if(compare(side, side2) == 0)
            {
                if(left > right)
                {
                    printf("OVERFLOW on RIGHT! Cannot push %d\n", num);
                }
                else
                {
                    for(int i = right; i < n-1; i++)
                    {
                        arr[i] = arr[i+1];
                    }
                    arr[n-1] = num;
                    right--;
                    printf("Pushed on RIGHT.\n");
                }
            }
            else
            {
                printf("Invalid side!\n");
                continue;
            }
        }
        else if(compare(command, cmd2) == 0)
        {
            if(compare(side, side1) == 0)
            {
                if(left == 0)
                {
                    printf("UNDERFLOW on left nothing to pop\n");
                }
                else
                {
                    int removed_value = arr[0];

                    for(int i = 0; i < left-1; i++){
                        arr[i] = arr[i+1];
                    }
                    arr[left-1] = 0;
                    left--;
                    printf("Popped value from LEFT: %d\n", removed_value);
                }
            }
            else if(compare(side, side2) == 0)
            {
                if(right == n-1)
                {
                    printf("UNDERFLOW on right nothing to pop\n");
                }
                else
                {
                    int removed_value = arr[n-1];
                    for(int i = n-1; i > right+1; i--){
                        arr[i] = arr[i-1];
                    }
                    arr[right+1] = 0;
                    right++;
                    printf("Popped value from RIGHT: %d\n", removed_value);
                }
            }
            else
            {
                printf("Invalid Side\n");
                continue;
            }
        }
        else if(compare(command, cmd3) == 0)
        {
            for(int i = 0; i < n; i++){
                printf("%d ", arr[i]);
            }
        }
        else
        {
            printf("Invalid operation\n");
            continue;
        }
        printf("\n");
    }

    return 0;
}
