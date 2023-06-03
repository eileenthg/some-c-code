//LAB02-TASK02
//Name: Eileen Tong Hui Guan
//Matric number: A180693

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int GCD(int num1, int num2);
int getPositiveInteger(char* s, char *p);

int getPositiveInteger(char* s, char *p) {
    // Returns a positive integer from the parsed string.
    // Returns -1 on failure.
    
    if(*s == '\n'){
        printf("Missing integers. \n");
        return -1;
    }
    
    long number;

    number = strtol(s, &p, 10);

    if (p == s || number <= 0){
        printf("Inputs should be a positive integer. \n"
               "Please enter two positive numbers with a space in between. \n");
        return -1;
    }
       

    else if (number > 2147483647){
        printf("One of the numbers are too big. \n"
               "Please enter two positive numbers with a space in between. \n ");
        return -1;
    }

    //For debugging
    //printf("Extracted %d \n", (int) number);
    
    return (int) number;
}

int GCD(int num1, int num2) {
	//Computes the greatest common denomiator between two numbers.
    if (num1 == num2)
        return num1;

    else if (num1 < num2)
        num2 = num2 - num1;
    else
        num1 = num1 - num2;

    return GCD(num1, num2);

}

int main() {

    int num1, num2;

    char s[100];
    char *p, *token;
    
    while(1){
        printf("Enter two positive integers: ");    
        if(!fgets(s, sizeof(s), stdin))
            break;
        printf("\n");
        token = strtok(s, " ");
        num1 = getPositiveInteger(token, p);
        if(num1 == -1){
            continue;
        }
        
        token = strtok(NULL, " ");
        if(token == NULL){
            printf("Missing second integer. \n");
            continue;
        }
        num2 = getPositiveInteger(token, p);
        if(num2 == -1){
            continue;
        }
        
        token = strtok(NULL, " ");
        if(token != NULL){
            printf("Extra iputs. \n");
            printf("Disregarding input after number %d. \n", num2);
        }
            
       break;
    }
    
    printf("GCD of %d and %d is %d", num1, num2, GCD(num1, num2) );

}