
#include<stdio.h>
#include<cs50.h>

typedef struct{
    string name;
    int votes;
}candidate;

int main(void){

    const int num = 3;
    candidate candidates[num];

    for(int i = 0; i < num; i++){
        candidates[i].name = get_string("Name: ");
        candidates[i].votes = get_int("Votes: ");
    }

    int highest_vote = 0;
    for(int i = 0; i < num; i++){
        if(candidates[i].votes > highest_vote){
            highest_vote = candidates[i].votes;
        }
    }
    printf("%i\n", highest_vote);

    for(int i = 0; i < num; i++){

        if(candidates[i].votes == highest_vote){
            printf("%s\n", candidates[i].name);
        }
    }
}
