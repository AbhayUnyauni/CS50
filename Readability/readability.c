#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int count_letters(string text, int len){
    int letter = 0;
    for(int i = 0; i < len; i++){
        if(isalpha(text[i])){
            letter++;
        }
    }
    return letter;
}

int count_words(string text, int len){

    int words = 1;
    for(int i = 0; i < len; i++){
        if(text[i] == ' '){
            words++;
        }
    }
    return words;
}

int count_sentences(string text, int len){

    int sentences = 0;
    for(int i = 0; i < len; i++){
        if(text[i] == '.' || text[i] == '?' || text[i] == '!'){
            sentences++;
        }
    }
    return sentences;
}
int main(){

    long double L;
    long double S;
    string text = get_string("Text: ");

    int len = strlen(text);
    double letters = count_letters(text, len);
    double words = count_words(text, len);
    double sentences = count_sentences(text, len);

    L = (letters / words) * 100;
    S = (sentences/ words) * 100;

    double index = 0.0588 * L - 0.296 * S - 15.8;
    printf("\n\n%f\n\n", index);
    printf("\n\n%f\n\n", round(index));
    int grade = (int) round(index);
    if (index < 1) {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16) {
        printf("Grade 16+\n");
    }
    else {
        printf("Grade %d\n", grade);
    }

    return 0;
}
