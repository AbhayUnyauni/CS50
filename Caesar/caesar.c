#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>



int main(int argc, string argv[]){
    if(argc != 2){
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int key = atoi(argv[1]);
    string plain_text = get_string("plaintext: ");
    int len = strlen(plain_text);
    char cipher_text[len];

    for (int i = 0; i < len; i++)
    {
        if (isupper(plain_text[i]))
        {
            cipher_text[i] = 'A' + (((plain_text[i] - 'A') + key) % 26 + 26) % 26;
        }
        else if (islower(plain_text[i]))
        {
            cipher_text[i] = 'a' + (((plain_text[i] - 'a') + key) % 26 + 26) % 26;
        }
        else
        {
            cipher_text[i] = plain_text[i];
        }
    }
    cipher_text[len] = '\0';
    printf("Ciphertext: %s\n", cipher_text);
    return 0;
}
