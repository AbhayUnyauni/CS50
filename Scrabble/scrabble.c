#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

//----------Calculate the values for each player-------------

int calculate_value(string entry, char Alpha[], int values[]){

  int length = 0;
  int total = 0;
  length = strlen(entry);
  for(int i = 0; i < length; i++){
    char c = toupper(entry[i]);
    for(int j = 0; j <= 25; j++){
      if(Alpha[j] == c){
        total += values[j];
        break;
      }
    }
  }
  return total;
}


int main(){

  char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  int values[26] = {1 , 3, 3, 2,	1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

  string entry1 = get_string("Player 1: ");
  string entry2 = get_string("Player 2: ");

  int point1 = calculate_value(entry1, Alpha, values);
  int point2 = calculate_value(entry2, Alpha, values);

//-----Checking who won-----

  if(point1 > point2){
    printf("Player 1 wins!\n");
  }else if(point1 < point2){
    printf("Player 2 wins!\n");
  }else{
    printf("Tie!\n");
  }
  return 0;
}
