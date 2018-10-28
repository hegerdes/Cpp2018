/*
    @author: Henrik Gerdes, Manuel Eversmeyer
    
    Compares two txt Files and prints the first difference
    to the terminal.

    The files are given by commandline arguments.

    For testing reasons the files text1.txt und text2.txt have been created to be compaied
*/
#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[] ){

    if(argc != 3){
        printf("Unzulaessige Parameter \n");
         return -1;
    }
    
    FILE *fp1, *fp2;

    fp1 = fopen(argv[1],"r");
    fp2 = fopen(argv[2],"r");

    
    if(fp1 == NULL || fp2 == NULL){
        printf("Deteien nicht lesbar\n");
        return -1;
    }

    char buffer1[1024], buffer2[1024];


    char *isEnd1[64], *isEnd2[64];
    do{
        //Alternative: if(scanf("%[^\n]"),buffer)
        *isEnd1 = fgets(buffer1, 1024, fp1);
        *isEnd2 = fgets(buffer2, 1024, fp2);


        if(strcmp(buffer1,buffer2)!=0){
            printf("%s", buffer2);
            fclose(fp1);
            fclose(fp2);
            return -1;    
        }
    }
    while(isEnd1 != NULL || isEnd2 != NULL);


    fclose(fp1);
    fclose(fp2);


    return 0;
}