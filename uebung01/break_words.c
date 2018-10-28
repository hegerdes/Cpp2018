/*
    @author: Henrik Gerdes, Manuel Eversmeyer
    
    A small programm that reads each character 
    form stdin and puts it to stdout while 
    replacing ' ' with a new line (\n)

*/    
#include <stdio.h>

int main(){

  int c;
  
  do {
    c=getchar();

    if(c == ' '){
      putchar('\n');
    }else{
      putchar (c);
    };

  } while (c != '\n');
  
  return 0;

}