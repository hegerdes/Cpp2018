/*
    @author: Henrik Gerdes, Manuel Eversmeyer
    
    Reads 4 Numbers in a line and 4 lines of a txt File 
    and prints it to the terminal with the mean value of each
    line.

    The files are given by commandline arguments.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printUse(){
    printf("Bitte Datei als Komandozeilenparameter angeben\n");
}



int main(int argc, char* argv[] ){

    if(argc != 2){
        printf("Unzulaessige Parameter \n");
        printUse;
         return -1;
    }
    
    FILE *fp;
    fp = fopen(argv[1],"r");

    
    if(fp == NULL){
        printf("Deteien nicht lesbar\n");
        printUse;
        return -1;
    }
    char buffer1[20];
    char fehler[64];

    int i,l, sum = 0;

    for(l = 0;l<4;l++){
        char fehler[64];
        fehler[0] = '\0';
        for(i = 0; i<4; i++){
            buffer1[0] = '\n';
            fscanf(fp, "%s", &buffer1);
            int num;
            //sscanf(buffer1, "%d", &num);
            num = atoi(buffer1);
            // Rückgabewert von atoi ist problematisch
            if(num == 0){
                strcpy(fehler,buffer1);
            }
            sum += num;
            printf("%3d", num);
        }
        double mean = sum/4;
        if(fehler[0] != '\0'){
            printf("    Es ist ein Fehler beim Umwandeln von Zeichen %s passiert", fehler);
        }
        printf("    Durchschnitt ist: %5.2f\n", mean);
    }

    fclose(fp);
    return 0;
}