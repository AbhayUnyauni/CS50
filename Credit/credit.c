#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>


//finding length of the number
int count_digits(long long n){
    int count = 0;
    if(n == 0){
        return 1;
    }

    while(n != 0){
        n /= 10;
        count++;
    }
    return count;
}

// opting out number for first array
int calculate_value1 (long long num, int len)
{
    long long int f_divisor = 10;
    long long result = 0;
    long long place = 1;
    long long int remainder = 0;

    for (int i = 0; i < len; i++) {
        remainder = (num % f_divisor) / (f_divisor / 10);
        if (i % 2 == 1) {
                result = result + remainder * place;
                place *= 10;
            }
            f_divisor *= 10;
        }

        int arr[10];
        int count = 0;

        long long temp = result;
        while(temp > 0){
        arr[count++] = temp % 10;
        temp /= 10;
        }
        for(int i = count-1; i >= 0; i--){
        }
        int array1_sum = 0;
        for(int i = 0; i < count_digits(result); i++){
        arr[i] *= 2;
        if (arr[i] >= 10){
        int sum = arr[i] % 10 + arr[i] / 10;
        arr[i] = sum;

        }
        array1_sum += arr[i];

        }
        return array1_sum;
}


// opting out numbers for second array
int calculate_value2 (long long num, int len)
{
    long long int f_divisor = 10;
    long long result = 0;
    long long place = 1;
    long long int remainder = 0;

    for (int i = 0; i < len; i++) {
        remainder = (num % f_divisor) / (f_divisor / 10);
        if (i % 2 == 0) {
                result = result + remainder * place;
                place *= 10;
            }
            f_divisor *= 10;
        }

        int arr[10];
        int count = 0;

        long long temp = result;
        while(temp > 0){
            arr[count++] = temp % 10;
            temp /= 10;
        }
        for(int i = count-1; i >= 0; i--){
        }

        //multiplying each digit by two and adding up them with each other for second array
        int array2_sum = 0;
        for(int i = 0; i < count_digits(result); i++){
            array2_sum += arr[i];
        }
        return array2_sum;
}


// main function
int main(void)
{
    long long num;
    int len;

    //checking valid number
    while(true){
        num = get_long("Number: ");
        len = count_digits(num);
        if(len != 13 && len != 15 && len != 16){
            printf("INVALID\n");
        }else{
            long long value1 = calculate_value1(num, len);
            long long value2 = calculate_value2(num, len);
            int check_sum = value1 + value2;

            for(int i = 2; i < len; i++){
                int digit = num % 10;
                num = num / 10;
            }

            //   Check what type of card it is????
            if(check_sum % 10 == 0){

                if (len == 16 && (num == 51 || num == 52 || num == 53 || num == 54 || num == 55)){
                    printf("MASTERCARD\n");

                } else if(len == 15 && (num == 34 || num == 37)){
                    printf("AMEX\n");

                } else if(((len == 13) || (len == 16)) && (num / 10 == 4)){
                    printf("VISA\n");
                } else {
                    printf("INVALID\n");
                }
            }else {
                printf("INVALID\n");
            }
        }
        break;
    }
    return 0;
}
