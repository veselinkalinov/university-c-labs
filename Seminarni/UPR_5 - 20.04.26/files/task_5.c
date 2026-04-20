#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const char *words[] = {
        "concatenation", "programming", "university", "algorithm", "keyboard"
    };
    int n = 5;

    srand((unsigned int)time(NULL));
    const char *word = words[rand() % n];
    int len = (int)strlen(word);
    int max_guesses = len + 2;

    char display[100];
    int i;
    for (i = 0; i < len; i++) display[i] = '_';
    display[len] = '\0';

    int guesses = 0;
    int found_total = 0;

    printf("Guess the word (%d letters). Max guesses: %d\n\n", len, max_guesses);

    while (found_total < len && guesses < max_guesses) {
        printf("Word: ");
        for (i = 0; i < len; i++) printf("%c ", display[i]);
        printf("\nEnter a letter: ");

        char letter;
        scanf(" %c", &letter);
        letter = (char)tolower((unsigned char)letter);
        guesses++;

        int found = 0;
        for (i = 0; i < len; i++) {
            if (word[i] == letter && display[i] == '_') {
                display[i] = letter;
                found_total++;
                found = 1;
            }
        }

        if (found) printf("Correct!\n\n");
        else        printf("Wrong letter.\n\n");
    }

    printf("Word: ");
    for (i = 0; i < len; i++) printf("%c ", display[i]);
    printf("\n");

    if (found_total == len)
        printf("You win! Guesses used: %d / %d\n", guesses, max_guesses);
    else
        printf("You lose! The word was: %s\n", word);

    return 0;
}
