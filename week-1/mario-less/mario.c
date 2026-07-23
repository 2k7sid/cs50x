// take user input for the height of an obstacle and then use it to create the stair-type obstacle found in super mario bros.

#include <stdio.h>
int main(void){
    int rows = 0;
    while (rows <= 0){
        printf("Enter the height of the obstacle to be generated: ");
        scanf("%d", &rows);
        if (rows <= 0){
            printf("Invalid value.\n");
        }
    }
    int i;
    for (i = 0; i < rows; i++){
        int block = (i + 1);
        int air = (rows - block);
        int j;

        for (j = 0; j < air; j++){
            printf(" ");
        }
        for (j = 0; j < block; j++){
            printf("#");
        }
        printf("\n");
    }
    return 0;
}