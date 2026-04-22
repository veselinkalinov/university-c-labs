#include <ctype.h>
#include <stdio.h>

int is_anagram(char *s1, char *s2) {
  int str[26] = {0};

  int i;
  for (i = 0; s1[i] != '\0'; i++) {
    if (isalpha((unsigned char)s1[i]))
      str[tolower((unsigned char)s1[i]) - 'a']++;
  }

  for (i = 0; s2[i] != '\0'; i++) {
    if (isalpha((unsigned char)s2[i]))
      str[tolower((unsigned char)s2[i]) - 'a']--;
  }

  for (i = 0; i < 26; i++) {
    if (str[i] != 0)
      return 0;
  }

  return 1;
}

int main() {
  char s1[100], s2[100];

  printf("First string:  ");
  scanf("%99s", s1);
  printf("Second string: ");
  scanf("%99s", s2);

  if (is_anagram(s1, s2))
    printf("Result: 1 (anagram)\n");
  else
    printf("Result: 0 (not anagram)\n");

  return 0;
}
