#include <complex.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



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
                op = '=';
            }
            else if(!strcmp(token, "/")){
                op = '/';
            }
            else{
                op = 'a';
            }
            return op;
        }

double complex StringToComp(char* token1, char* token2, char* token3){
    double complex real;
    double complex fake;
    double complex output;
    char assign = assignment(token3);
    if(assign == '+' || assign == '-'){
    if(strchr(token1, 'j') != NULL){
        if(!strcmp(token1, "j")){
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
    else if(strchr(token2, 'j') != NULL){
        if(!strcmp(token2, "j")){
            fake = 1;
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
        mult = mult * conj(sum);
        sum = sum * conj(sum);
        return mult/sum;
        default:
        return 0;
    }
}





void printComplex(double complex num1){
    double real = creal(num1);
    double  imag = cimag(num1);

    printf("Output = %f + %fj\n", real, imag);
}