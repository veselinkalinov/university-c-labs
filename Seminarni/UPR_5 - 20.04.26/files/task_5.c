#include <stdio.h>
#include <string.h>

int main() {
  char word[] = "concatenation";
  char display[100];
  int len = (int)strlen(word);
  int guesses = 0;
  int found_total = 0;
  int i;

  for (i = 0; i < len; i++) {
    display[i] = '_';
  }
  display[len] = '\0';

  printf("Guess the word\n");
  printf("Letters: %d\n\n", len);

  while (found_total < len && guesses < len + 2) {
    char letter;
    int found = 0;

    printf("Word: ");
    for (i = 0; i < len; i++) {
      printf("%c ", display[i]);
    }
    printf("\nEnter a letter: ");

    scanf(" %c", &letter);
    guesses++;

    for (i = 0; i < len; i++) {
      if (word[i] == letter && display[i] == '_') {
        display[i] = letter;
        found_total++;
        found = 1;
      }
    }

    if (found) {
      printf("Correct!\n\n");
    } else {
      printf("Wrong letter.\n\n");
    }
  }

  printf("Word: ");
  for (i = 0; i < len; i++) {
    printf("%c ", display[i]);
  }
  printf("\n");

  if (found_total == len) {
    printf("You win! Guesses used: %d\n", guesses);
  } else {
    printf("You lose! The word was: %s\n", word);
  }

  return 0;
}
