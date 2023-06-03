//LAB02-TASK02
//Name: Zhou Qile
//Matric number: A179213

#include <stdio.h>
#include <stdlib.h>

int testInteger() {

    long number;

    char *p, s[100];

    while (fgets(s, sizeof(s), stdin)) {

        number = strtol(s, &p, 10);

        if (p == s || *p != '\n' || number < 0)
            printf("Input should be a non-negative integer. Please re-enter the number: ");

        else if (number > 2147483647)
            printf("Number is too big. Please re-enter the number: ");

        else
            break;

    }

    return (int) number;

}

int main() {

    printf("\nData below is based on the parking charges at KLIA.\n\n"
           "===============================\n"
           "HOURS\t\t\t\tRATE\n"
           "===============================\n"
           "1st - 3rd hours\t\tRM4.00/hour\n"
           "4th - 5th hours\t\tRM3.00/hour\n"
           "6th - 9th hours\t\tRM2.50/hour\n"
           "10th - 18th hours\tRM2.00/hour\n"
           "Maximum a day\t\tRM46.00\n"
           "===============================\n");

    printf("\nEnter number of days: ");
    int days = testInteger();

    printf("\nEnter number of hours of current day: ");
    int hours = testInteger();

    double charges = 0.00;

    while (hours > 24 || hours == 0) {

        if (hours > 24)
            printf("The number of hours should be at most 24. Please re-enter.: ");

        if (hours == 0)
            printf("The number of hours should be at least 1. Please re-enter.: ");

        hours = testInteger();

    }

    if (hours <= 3)
        charges = 46.00 * days + 4.00 * hours;
    else if (3 < hours && hours <= 5)
        charges = 46.00 * days + 3 * 4.00 + (hours - 3) * 3.00;
    else if (5 < hours && hours <= 9)
        charges = 46.00 * days + 3 * 4.00 + (5 - 3) * 3.00 + (hours - 5) * 2.50;
    else if (9 < hours && hours <= 18)
        charges = 46.00 * days + 3 * 4.00 + (5 - 3) * 3.00 + (9 - 5) * 2.50 + (hours - 9) * 2.00;
    else if (18 < hours && hours <= 24)
        charges =
                46.00 * days + 3 * 4.00 + (5 - 3) * 3.00 + (9 - 5) * 2.50 + (18 - 9) * 2.00;// Up to RM46.00 in one day

    if (charges > 46.00 * 1 + 3 * 4.00 + (5 - 3) * 3.00 + (9 - 5) * 2.50 + (12 - 9) * 2.00)//Get discount for exceeding 36 hours
        charges = charges * (1 - 0.1);

    printf("\nTotal charges: RM %.2lf\n", charges);

}