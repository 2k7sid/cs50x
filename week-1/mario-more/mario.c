///In a file called mario.c in a folder called mario-more, implement a program in C that recreates that pyramid, using hashes (#) for bricks
#include <stdio.h>

int main(void)
{
    int rows = 0; 
    while (rows <= 0){
        printf("Enter the height of the obstacle to be made: ");
        scanf("%d", &rows);

        if (rows < 0){
            printf("Invalid value \n");
        }
        if (rows == 0){
            printf("No obstacle to be formed.\n");
            break;
        }
    }
    int i;
    for (i = 0; i < rows; i++){
        int blocks = (i+1);
        int air = (rows - blocks);
        int j;

        for (j = 0; j < air; j++){
            printf(" ");
        }
        for (j = 0; j < blocks; j++){
            printf("#");
        }
        printf("  ");
        for(j = 0; j < blocks; j++){
            printf("#");
        }
        for (j = 0; j < air; j++){
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}