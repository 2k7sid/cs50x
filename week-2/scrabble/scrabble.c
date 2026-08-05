/// simple two-player game of scrabble, comparing the scores obtained by two players based on the points given for each letter of the word to declare the winner

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void rmenter(char word[]);
int wordscore(char word[]);

int main(void)
{
    char word1[100];
    char word2[100];

    printf("Starting new scrabble game:\n");

    printf("Input word by player 1:  ");
    fgets(word1, sizeof(word1), stdin);
    rmenter(word1);

    printf("Input word by player 2:  ");
    fgets(word2, sizeof(word2), stdin);
    rmenter(word2);

    if (wordscore(word1)!= -1 && wordscore(word2)!= -1){
        if (wordscore(word1) > wordscore(word2)){
            printf("Player 1 wins! \n");
        }
        else if (wordscore(word1) < wordscore(word2)){
            printf("Player 2 wins!\n");
        }
        else {
            printf("Its a tie!\n");
        }
    }
    else {
        if (wordscore(word1) == -1 && wordscore(word2) != -1){
            printf("Player 1 has given an invalid entry, player 2 wins.\n");
        }
        else if (wordscore(word2) == -1 && wordscore(word1) != -1){
            printf("Player 2 has given an invalid entry, player 1 wins.\n");
        }
        else {
            printf("Both players have provided an incorrect value. Tie on extraordinary grounds.\n");
        }
    }
    return 0;
}

void rmenter(char word[])
{
    word[strcspn(word, "\n")] = '\0';
}

int wordscore(char word[])
{
    int playerscore = 0;

    for (int i = 0; word[i] != '\0'; i++){
        if (islower(word[i])){
            word[i] = toupper(word[i]);
        }
        else { 
            ;
        }
    }

    for (int i = 0; i < strlen(word); i++){
        if (word[i] == 65 || word[i] == 69 || word[i] == 73 || word[i] == 76 || word[i] == 78 || word[i] == 79 || word[i] == 82 || word[i] == 83 || word[i] == 84 || word[i] == 85){
            playerscore += 1;
        }
        else if (word[i] == 68 || word[i] == 71){
            playerscore += 2;
        }
        else if (word[i] == 66 || word[i] == 67 || word[i] == 77 || word[i] == 80){
            playerscore += 3;
        }
        else if (word[i] == 70 || word[i] == 72 || word[i] == 86 || word[i] ==  87 || word[i] == 89){
            playerscore += 4;
        }
        else if (word[i] == 75){
            playerscore += 5;
        }
        else if (word[i] == 74 || word[i] == 88){
            playerscore += 8;
        }
        else if (word[i] == 81 || word[i] ==  90){
            playerscore += 10;
        }
        else {
            playerscore = -1;
            break;
        }
    }
    return playerscore;
} 