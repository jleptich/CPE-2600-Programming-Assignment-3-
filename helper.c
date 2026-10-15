/*  Assignment: Programming Assignment 3
*   Author: Joseph Leptich
*   Date: 10/14/2026
*   Description: Helper file that holds all the functions to convert strings into a complex number and complex number arithmetic
*   compile: either with make or: 
*   gcc -o calc imaginary.c helper.c -lm
*/




#include <complex.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//Finds the assignment character for the arithmetic between two complex numbers
char assignment(char* token){
            char op;
            if(!strcmp(token,"+")){
                op = '+';
            }
            else if(!strcmp(token,"-")){
                op = '-';
            }
            else if(!strcmp(token,"*")){
                op = '*';
            }
            else if(!strcmp(token,"|")){
                op = '|';
            }
            else if(!strcmp(token, "/")){
                op = '/';
            }
            else{
                op = 'a';
            }
            return op;
        }


//converts user input into a complex number
double complex StringToComp(char* token1, char* token2, char* token3){
    double complex real;
    double complex fake;
    double complex output;
    char assign = assignment(token3);
    if(assign == '+' || assign == '-'){     //ensures a valid assessment was used
    if(strchr(token1, 'j') != NULL){        //checks if token1 was the imaginary component
        if(!strcmp(token1,"j")){
            fake = 1;
        }
        else{
        fake = atof(token1);
        fake = fake * I;
        }
        real = atof(token2);
        if(assign == '-'){
            output = fake + real*-1;
            return output;
        }
        else{
            output = fake + real;
            return output;
        }
    }
    else if(strchr(token2, 'j') != NULL){   //checks if token2 is the imaginary component
        if(!strcmp(token2, "j")){
            fake = 1* I;
        }
        else{
        fake = atof(token2);
        fake = fake * I;
        }
        real = atof(token1);
        if(assign == '-'){
            output = fake*-1 + real;
            return output;
        }
        else{
            output = fake + real;
            return output;
        }
    }
    else{
        return 0;
    }
}
    return 0;
}

//Arithmetic function to do any arithmetic with complex numbers
double complex arithmetic(double complex num1, double complex num2, char op){
    switch(op){
        case('+'):
        return num1 + num2;
        case('-'):
        return num1 - num2;
        case('*'):
        return num1 * num2;
        case('/'):
        return num1 / num2;
        case('|'):
        double complex sum = num1 + num2;
        double complex mult = num1*num2;
        return mult / sum;

        default:
        return 0;
    }
}
//print function to print a complex number
void printComplex(double complex num1){
    double real = creal(num1);
    double  imag = cimag(num1);

    printf("Output = %.4f + %.4fj\n", real, imag);
}

void printPolar(double complex number1){
    double absolute = cabs(number1);
    double phase = carg(number1);
    printf("The magnitude is: %.2f Phase: %.2f\n", absolute, phase);
}

void printRectangular(double mag, double phase){
            double real = mag*cos(phase);
            double imag = mag*sin(phase);
            double complex output = real + imag*I;
            printComplex(output);
}