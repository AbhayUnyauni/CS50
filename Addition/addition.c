#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000

int add(int a[], int n1, int b[], int n2, int result[]){
    int i = n1 - 1;
    int j = n2 - 1;
    int k = 0;
    int carry = 0;

    while(i >=0 || j >= 0 || carry){
        int sum = carry;
        if(i >= 0){
            sum += a[i--];
        }
        if(j >= 0){
            sum += b[j--];
        }
        result[k++] = sum % 10;
        carry = sum / 10;
    }
    for(int x = 0; x < k/2; x++){
        int temp = result[x];
        result[x] = result[k - x - 1];
        result[k -x - 1] = temp;
    }
    return k;
}

int main(void){

    FILE *file = fopen("numbers.txt", "r");
    if(file == NULL){
        printf("Error opening file\n");
        return 1;
    }
    char num1[MAX], num2[MAX];
    if(fscanf(file, "%s %s", num1, num2) != 2){
        printf("Invalid number of arguments\n");
        fclose(file);
        return 1;
    }
    fclose(file);

    int a[MAX], b[MAX];
    int n1 = strlen(num1);
    int n2 = strlen(num2);

    for(int i = 0; i < n1; i++)
        a[i] = num1[i] - '0';
    for(int i = 0; i < n2; i++)
        b[i] = num2[i] - '0';

    int result[MAX + 1];
    int len = add(a, n1, b, n2, result);
    printf("Number 1: %s\n", num1);
    printf("Number 2: %s\n", num2);
    printf("Sum: ");
    for (int i = 0; i < len; i++)
        printf("%d", result[i]);
    printf("\n");

    return 0;

}
