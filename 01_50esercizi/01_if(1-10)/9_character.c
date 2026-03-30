#include <stdio.h>

int main() {
    printf("\n exercise n9 \n");

    char character;
    printf("Enter a character (a-z): \n");
    scanf(" %c", &character);

    char c = tolower(character);
    
    if(c =='a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        printf("The character '%c' is a vowel.\n", c);
    } else {
        printf("The character '%c' is a consonant.\n", c);
    }        

    return 0;
}