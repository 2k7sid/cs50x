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
    int score1 = wordscore(word1);

    printf("Input word by player 2:  ");
    fgets(word2, sizeof(word2), stdin);
    rmenter(word2);
    int score2 = wordscore(word2);

    if (score1 != -1 && score2 != -1){
        if (score1 > score2){
            printf("Player 1 wins! \n");
        }
        else if (score1 < score2){
            printf("Player 2 wins!\n");
        }
        else {
            printf("Its a tie!\n");
        }
    }
    else {
        if (score1 == -1 && score2 != -1){
            printf("Player 1 has given an invalid entry, player 2 wins.\n");
        }
        else if (score2 == -1 && score1 != -1){
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
    }
    int length = strlen(word);
    for (int i = 0; i < length; i++){
        if (word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'L' || word[i] == 'N' || word[i] == 'O' || word[i] == 'R' || word[i] == 'S' || word[i] == 'T' || word[i] == 'U'){
            playerscore += 1;
        }
        else if (word[i] == 'D' || word[i] == 'G'){
            playerscore += 2;
        }
        else if (word[i] == 'B' || word[i] == 'C' || word[i] == 'M' || word[i] == 'P'){
            playerscore += 3;
        }
        else if (word[i] == 'F' || word[i] == 'H' || word[i] == 'V' || word[i] ==  'W' || word[i] == 'Y'){
            playerscore += 4;
        }
        else if (word[i] == 'K'){
            playerscore += 5;
        }
        else if (word[i] == 'J' || word[i] == 'X'){
            playerscore += 8;
        }
        else if (word[i] == 'Q' || word[i] ==  'Z'){
            playerscore += 10;
        }
        else {
            playerscore = -1;
            break;
        }
    }
    return playerscore;
} 