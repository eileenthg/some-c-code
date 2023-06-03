// Lab 02-Task 1
// Name :Ahmad Aieman Akmal
// Matric no: A182997
// Group Name: The Big 3

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

int square(int x);
int cube (int x);
int sqrt_rt(int x);
int cube_rt(int x);

int circle(int x);
int triangle (int x,int y);
int rectangle(int x,int y);

int cylinder (int x, int y);
int prism (int x, int y,int z);


void selection();




int main() {
    printf("%s","What would you like to do today?\n");

    printf("%s","   a. Calculate square\n");
    printf("%s","   b. Calculate cube\n");
    printf("%s","   c. Calculate square root\n");
    printf("%s","   d. Calculate cube root\n");
    printf("%s","   e. Calculate area of circle\n");
    printf("%s","   f. Calculate area of triangle\n");
    printf("%s","   g. Calculate area of rectangle\n");
    printf("%s","   h. Calculate volume of cylinder\n");
    printf("%s","   i. Calculate volume of prism\n");
    selection();

    return 0;
}

int square(int x){
    return x*x;
}
int cube(int x){
    return x*x*x;
}
int square_rt(int x){
    float y=sqrt(x);
    int out=round(y);
    return out ;
}
int cube_rt(int x){
    float y=cbrt(x);
    int out=round(y);
    return out ;
}

int circle (int x){
    float y=M_PI*x*x;
    int out = round(y);
    return out;
}
int triangle (int x,int y){
    float z=x*y*0.5;
    int out = round(z);
    return out;
}
int rectangle (int x,int y){
    return x*y;
}

int cylinder (int x,int y){
    float z=M_PI*x*x*y;
    int out = round(z);
    return out;
}
int prism (int x,int y,int z){
    float a=x*y*z*0.333333333;
    int out = round(a);
    return out;
}
//////////////////////////
int input_check(){
    long input;
    char *p, s[100];
    char ignore[1024];
    fgets(ignore, sizeof(ignore), stdin);
    while (fgets(s, sizeof(s), stdin)) {
        input = strtol(s, &p, 10);
        if (p == s || *p != '\n' || input <= 0) {
            printf("Input should be a positive integer.\n"
                   "Please re-enter the number: ");
        } else if (input > INT_MAX) {
            printf("Number is too big. \n"
                   "Please re-enter the number: ");
        } else {
            return (int) input;
            break;
        }
    }
}

///////////////////////////
void selection(){
    long input;
    long input2;
    long input3;
    bool check=true;
    char select;
//
    while(check) {
        scanf("%s",&select);
        if(strcmp(&select,"a")==0) {
            printf("%s","Please insert value:");
            input = input_check();
            printf("%s", "Square value of ");
            printf("%ld", input);
            printf(" = %d", square(input));
            check = false;
        }
        else if(strcmp(&select,"b")==0) {
            printf("%s", "Please insert value:");
            input = input_check();
            printf("%s", "Cube value of ");
            printf("%ld", input);
            printf(" = %d", cube(input));
            check = false;
        }
        else if(strcmp(&select,"c")==0) {
            printf("%s", "Please insert value:");
            input = input_check();
            printf("%s", "Square root value of ");
            printf("%ld", input);
            printf(" = %d", square_rt(input));
            check = false;
        }
        else if(strcmp(&select,"d")==0) {
            printf("%s", "Please insert value:");
            input = input_check();
            printf("%s", "Cube root value of ");
            printf("%ld", input);
            printf(" = %d", cube_rt(input));
            check = false;
        }
        else if(strcmp(&select,"e")==0) {
            printf("%s", "Please insert radius length:");
            input = input_check();
            printf("%s", "Area of circle");
            printf(" = %d", circle(input));
            check = false;
        }
        else if(strcmp(&select,"f")==0) {
            printf("%s", "Please insert base length:");
            input = input_check();
            printf("%s", "Please insert height length:");
            input2 = input_check();
            printf("%s", "Area of triangle");
            printf(" = %d", triangle(input, input2));
            check = false;
        }
        else if(strcmp(&select,"g")==0) {
            printf("%s", "Please insert length:");
            input = input_check();
            printf("%s", "Please insert width:");
            input2 = input_check();
            printf("%s", "Area of Rectangle");
            printf(" = %d", rectangle(input, input2));
            check = false;
        }
        else if(strcmp(&select,"h")==0) {
            printf("%s", "Please insert radius length:");
            input = input_check();
            printf("%s", "Please insert height length:");
            input2 = input_check();
            printf("%s", "Volume of cylinder");
            printf(" = %d", cylinder(input, input2));
            check = false;
        }
        else if(strcmp(&select,"i")==0) {
            printf("%s", "Please insert width of base:");
            input = input_check();
            printf("%s", "Please insert length of base:");
            input2 = input_check();
            printf("%s", "Please insert height:");
            input3 = input_check();
            printf("%s", "Volume of prism");
            printf(" = %d", prism(input, input2, input3));
            check = false;
        }

        else {
            printf("%s", "Sorry, please enter the correct choice\n");
        }
    }
}
