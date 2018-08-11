#include<stdio.h>
/*  Write a C program to input electricity unit charges and calculate total electricity bill according to the given condition:
 *  For first 50 units Rs. 0.50/unit
 *  For next 100 units Rs. 0.75/unit
 *  For next 100 units Rs. 1.20/unit
 *  For unit above 250 Rs. 1.50/unit
 *  An additional surcharge of 20% is added to the bill.
 */

int main() {
    int units; float  bill, rate, part, surcharge;
    bill = 0.0, units = 0, rate = 0.0, part = 0.0;
    // take user input
    printf("Enter number of electricity units -> ");
    scanf("%d", &units);
    // bill when units are more than 250
    if(units > 250) {
        rate = 1.50;
        part = rate * (units - 250);
        printf("%f\n", part);
        bill = bill + part;
        part = (100 * 1.20) + (100 * 0.75) + (50 * 0.50);
        bill = bill + part;
    }
    // bill when units are more than 150    
    else if(units > 150) {
        rate = 1.20;
        part = rate * (units - 150);
        bill = bill + part;
        part = (100 * 0.75) + (50 * 0.50);
        bill = bill + part;
    }
    // bill when units are more than 50    
    else if(units > 50) {
        rate = 0.75;
        part = rate * (units - 50);
        bill = bill + part;
        part = (50 * 0.50);
        bill = bill + part;
    }
    // bill when units are less than 50
    else {
        rate = 0.50;
        part = rate * units;
        bill = bill + part;
    }
    printf("Bill value = %f (without surcharge).\n", bill);
    surcharge = bill * 0.2; // 20 % of bill
    bill = bill + surcharge;
    printf("Total Bill value = %f (with surcharge).\n", bill);
    return 0;
}