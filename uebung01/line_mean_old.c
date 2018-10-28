/*
    @author: Henrik Gerdes, Manuel Eversmeyer
    
    Reads a txt File withe numbers and prints it
    to the terminal with the mean value of each
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
    char *isEnd[64];
    int zahlen[20];

    do{
        *isEnd = fgets(buffer1, 1024,fp);
        strtok(buffer1, "\n");
        printf("%10s", buffer1);
        if(buffer1[0] == '\n'){
            break;
        }

        int i = 0;
        int summe = 0;
        summe += atoi(strtok(buffer1," "));
        while(i != 3){
            summe += atoi(strtok(NULL," "));
            i++;
        };
        
        double mean = summe/4;
        printf("    Durchschnitt: %5.2f\n", mean);
        buffer1[0] = '\n';
    }while(isEnd !=NULL);


    fclose(fp);
    return 0;
}