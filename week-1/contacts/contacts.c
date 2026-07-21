// create a file called contacts.c that asks the user for their name, age, phone number, and email address, 
// then print all the information back to them in a structured manner.

#include <stdio.h>
#include <string.h>

void rmgarbage(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    ; //do nothing
}

int main(void)
{
    char name[100];
    char age[3];
    char phone[11];
    char mail[100];

    printf("Please enter your name: \n");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("enter your age: ");
    scanf("%2s", age);
    rmgarbage();
    printf("enter your phone number: ");
    scanf("%10s", phone);
    rmgarbage();
    printf("please enter your email address: ");
    scanf("%99s", mail);
    rmgarbage();

    printf("Data recorded. Please confirm your details below:\n\n  Name: %s\n  Age: %s\n  Phone Number: +91 %s\n  E-Mail Address: %s\n\n Thank You!\n", name,age,phone,mail);
    
    return 0;
}
