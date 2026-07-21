// commmand that takes full name user input and displays a hello messag for it

#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[100];
    printf("Please enter your name:  ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("Hello, %s! \n", name);
    return 0;
}