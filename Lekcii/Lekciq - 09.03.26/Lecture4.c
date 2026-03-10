#include <stdio.h>
#include <string.h>

int main() {
  char name[] = "Ivan";
  // printf(name);
  char newName[] = "Petkanka";
  int check = strcmp(newName, name);
  // strcpy(newName, name);

  printf("%d", check);
  return 0;
}
