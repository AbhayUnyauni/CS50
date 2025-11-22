#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SIZE 512

int main(int argc, char *argv[])
{
 if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    FILE *card = fopen(argv[1], "r");
    if(card == NULL){
        printf("File could not be open!\n");
        exit(1);
    }
    uint8_t buffer[SIZE];

    char fName[8];
    FILE *img;
    int counter = 0;

    while(fread(buffer, SIZE, 1, card) == 1){
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0){
            if(counter != 0){
                fclose(img);
            }
            sprintf(fName, "%0.3i.jpg", counter++);
            img = fopen(fName, "w");
            fwrite(buffer, SIZE, 1, img);
        }
        else if(counter > 0){
            fwrite(buffer, SIZE, 1, img);
        }
    }
    fclose(card);
    fclose(img);
}
