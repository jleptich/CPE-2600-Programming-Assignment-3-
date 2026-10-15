/*  Assignment: Programming Assignment 3
*   Author: Joseph Leptich
*   Date: 10/14/2026
*   Description: Created a complex number calculator that does all airthmetic plus finding parallel impedence
*   compile: either with make or: 
*   gcc -o calc imaginary.c helper.c -lm
*/


#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>
#include <math.h>
#include "helper.h"
#define J I

int main(){
printf("Welcome to the complex number calculator, type -h if you need help: please enter a valid command\n\n");

while(1){
    //initializes the input array and the 7 string tokens
        char input[50];
        char* token1;
        char* token2;
        char* token3;
        char* token4;
        char* token5;
        char* token6;
        char* token7;
        printf("Enter your command:");
        fgets(input, 50, stdin);
        token1 = strtok(input, " \n");
        token2 = strtok(NULL, " \n");
        token3 = strtok(NULL, " \n");
        token4 = strtok(NULL, " \n");
        token5 = strtok(NULL, " \n");
        token6 = strtok(NULL, " \n");
        token7 = strtok(NULL, " \n");

        //If only one input was detected
        if(token2 == NULL && token3 == NULL && token4 == NULL && token5 == NULL && token6 == NULL && token7 == NULL){
            //help pagew
            if(!strcmp(token1, "-h")){
                printf("To use an imaginary number you must use j\n\n you can add (+), subtract (-), multiply (*), and divide (\\) two complex numbers\n\n");
                printf("You can also calculate two complex numbers in parallel with eachother with |\n\n");
                printf("You can also find the magnitude and phase of a complex number given one complex number in rectangular form as an argument\n\n");
                printf("You can also convert magnitude and phase into rectangular form if you just enter magnitude and phase\n\n");
                printf("PLEASE HAVE SPACES BETWEEN EVERY INPUT, IF NO SPACE IS PRESENT THE CALCULATOR WON'T RUN!!!!!\n\n");
                printf("To exit enter quit\n\n");
            }
            //Lets you exit out of the program
            else if(!strcmp(token1, "quit")){
                printf("Thank you for using the calculator!\n");
                return 0;
            }
            else{
                printf("You entered a invalid command: type -h for help\n");
                continue;
            }

        }

        //if the user wants to convert magnitude and phase into rectangular form
        else if(token3 == NULL && token4 == NULL && token5 == NULL && token6 == NULL && token7 == NULL){
            double mag = atof(token1);
            double phase = atof(token2);

            double real = mag*cos(phase);
            double imag = mag*sin(phase);
            double complex output = real + imag*I;
            printComplex(output);
            continue;
        }
        //converting rectangular form into magnitude and phase
        else if(token4 == NULL && token5 == NULL && token6 == NULL && token7 == NULL){
            char assign = assignment(token2);
            if(assign == '+' || assign == '-'){
            double complex number1 = StringToComp(token1, token3, token2);
            double absolute = cabs(number1);
            double phase = carg(number1);
            printf("The magnitude is: %.2f Phase: %.2f\n", absolute, phase);
            continue;
            }
            else{
                printf("You didn't enter a valid command: enter -h for help\n\n");
                continue;
            }
        }
        //Not valid inputs
        else if( (token5 == NULL && token6 == NULL && token7 == NULL) || (token6 == NULL && token7 == NULL) || (token7 == NULL)){
            printf("You didn't enter a valid command: enter -h for help\n\n");
            continue;
        }

        //If arithmetic between two complex numbers is detected
        else{
            double complex number1 = StringToComp(token1, token3, token2);
            double complex number2 = StringToComp(token5, token7, token6);
            char op = assignment(token4);
            double complex output;
            if(op == 'a' || number1 == 0 || number2 == 0){
                printf("You entered a invalid command: enter -h for help\n\n");
            }
            else{
                output = arithmetic(number1, number2, op);
                printComplex(output);
            }
        }

}
    return 0;
}