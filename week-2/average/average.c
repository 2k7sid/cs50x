/// program to ask the user for all the scores of different subjects and use it to calculate the average score, implementing the concept of arrays

#include <stdio.h>

float average(int length, float scores[]);

int main(void)
{
    int size;
    printf("Enter the number of subjects: ");
    scanf("%i", &size);
    printf("Enter the scores obtained in all the %i subjects:\n", size);
    float scores[size];
    int i;
    for (i = 0; i < size; i++){
        printf("Enter the score for subject %i: ", (i+1));
        scanf("%f", &scores[i]);
    }
    printf("The average of all the obtained scores is %f\n", average(size, scores));
    return 0;
}

float average(int length, float scores[])
{
    float sum = 0;
    int i;
    for (i = 0; i < length; i++){
        sum += scores[i];
    }
    float avg = (sum / (float) length);
    return avg;
}