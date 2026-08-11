/* readability program that takes the user input in the form of a text body and utilizes the 
coleman-liau index to check the reading level of the given text*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void rmenter(char word[]);

int main(void)
{
    char userint[1000]; 
    printf("Enter your text to analyze readbility as per the Coleman-Liau index (Maximum 1000 characters only!): \n");
    fgets(userint, sizeof(userint), stdin);

    int c;
    while ((c = getchar()) != '\n' && c != EOF){
        /// discard excess value from input stream.
    }
    rmenter(userint); /// to remove \n in case not present in overflowed input stream.

    /// initiating data analysis for coleman-liau indexing:

    int lettercount = 0;
    int wordcount = 0;
    int sentencecount = 0;

    int i = 0;
    while (userint[i] != '\0' && userint[i] != EOF){
        if (isdigit(userint[i])){  /// encountered numbers treated as irrelevant
            ;/// skip and ignore
        }
        else if (isalpha(userint[i])){  /// if alphabet (letter) encountered
            lettercount++;
        }
        else if (ispunct(userint[i]) || isspace(userint[i])){
            if (isspace(userint [i])){     /// space character and not just a word or sentence terminating character
                wordcount++;
            }
            else if (userint[i] == '.' || userint[i] == '!' || userint[i] == '?'){  /// sentence terminating punct encountered
                sentencecount++;
            }
            else if (userint[i] == '-' || userint[i] == '/' || userint[i] == '@' || userint[i] == '^'){   /// word-separating punct encountered
                wordcount++;
            }
            else{   /// punct neither word seperating, nor sentence terminating. OR unrecognized character (considered irrelevant)
                ;/// skip and ignore
            }
        }
        i++;
    }
    wordcount++;

    /// reading level calculated via coleman-liau index using: [ index = 0.0588 * L - 0.296 * S - 15.8 ]
    const float L = (((float)lettercount / wordcount)*100);
    const float S = (((float)wordcount / sentencecount)*100);
    const int INDEX = (int) round((0.0588*L)-(0.296*S)-(15.80));

    if (INDEX < 1){
        printf("Reading level of the given text is below grade 1.\n");
    }
    else if (INDEX >= 1 && INDEX <= 16){
        printf("The reading level of the given text is %i.\n", INDEX);
    }
    else{
        printf("Reading level of given text is above grade 16. \n");
    }
    
    return 0;
}

void rmenter(char word[])
{
    word[strcspn(word, "\n")] = '\0';
}

