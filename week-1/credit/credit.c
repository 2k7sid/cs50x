/*
In the file called credit.c in the credit directory, write a program that prompts the user for a credit card number 
and then reports (via printf) whether it is a valid American Express, MasterCard, or Visa card number, per the definitions of each’s format herein. 
we ask that your program’s last line of output be AMEX\n or MASTERCARD\n or VISA\n or INVALID\n, nothing more, nothing less. 
For simplicity, you may assume that the user’s input will be entirely numeric (i.e., devoid of hyphens) and that it won’t have leading zeroes. 
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    char cc[50];
    char cc_cleaned[50];
    printf("Enter the credit card number: ");
    fgets(cc, sizeof(cc), stdin);
    cc[strcspn(cc, "\n")] = '\0';
    int j = 0;
    int i;
    //cleaning input data from all spaces and hyphens:

    for (i = 0; cc[i] != '\0'; i++){
        if (isdigit(cc[i])){
            cc_cleaned[j] = cc[i];
            j++;
        }
    }
    cc_cleaned[j] = '\0';
    printf("the corrected card details are %s\n", cc_cleaned);
    return 0;
}