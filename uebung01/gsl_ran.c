/*
    Prints a Gaussian distribution with the 
    standard deviation sigma from -5 to 5 on 
    stdout/terminal
    
*/
#include <stdio.h>
#include <gsl/gsl_randist.h>

int main(){

    double counter;
    double sigma = 1.0;



    for(counter = -5.0; counter < 5.0; counter+=0.1){
        printf("%5.2f   %.6f\n", counter, gsl_ran_gaussian_pdf(counter, sigma));
    }

    

    return 0;
}