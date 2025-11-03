#include<stdio.h>
#include<cs50.h>

int f(int n){
    if(n <= 0){
        return 1;
    }
    else{
        return n * f(n - 1);
    }
}

int main(void){

    int number;
    do{
        number = get_int("Numberr: ");
    }while(number < 0);

    int result = f(number);
    printf("Factorial of %i is %i \n", number, result);

}
