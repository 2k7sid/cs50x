//create a command that takes inout of the amount of change to be returned to a customer then indicate the minimum number of coins needed for the same.

#include <stdio.h>
int main(void)
{
    int change = 0;
    while (change <= 0){
        printf("Please enter the amount of change (in cents) to be returned to the user:  ");
        scanf("%d", &change);
        if (change == 0){
            printf("No change to be returned.\n");
            break;
        }
        else if (change < 0){
            printf("Error: Invalid value for change.\n");
        }
    }
    if (change != 0){
        int c25 = 0;
        int c10 = 0;
        int c5 = 0;
        int c1 = 0;
        int amount = change;
        while (change >= 25){
            change = change - 25;
            c25++;
        }
        while (change >= 10){
            change = change - 10;
            c10++;
        }
        while (change >= 5){
            change = change - 5;
            c5++;
        }
        while (change >= 1){
            change = change - 1;
            c1++;
        }
        printf("The total amount of change to be retuned is %d cents requiring:\n%d 25-cent coins\n%d 10-cent coins\n%d 5-cent coins\n%d 1-cent coins\n", amount, c25, c10, c5, c1);
    }
    return 0;
}
