#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Zad 1:

typedef struct {
  char title[50];
  char id[7];
  int year;
  float price;
} Book;

Book *addBook(Book *arr, int *count) {
  (*count)++;
  arr = realloc(arr, (*count) * sizeof(Book));
  if (arr == NULL) {
    printf("arr realloc error");
    exit(1);
  }

  Book *b = &arr[(*count) - 1];
  printf("Title: ");
  scanf(" %49[^\n]", b->title);
  printf("ID: ");
  scanf("%6s", b->id);
  printf("Year: ");
  scanf("%d", &b->year);
  printf("Price: ");
  scanf("%f", &b->price);

  FILE *ft = fopen("library.txt", "a");
  if (ft == NULL) {
    printf("ft error");
    exit(1);
  }

  fprintf(ft, "%d;%s;%s;%d;%.2f\n", (int)strlen(b->title), b->title, b->id,
          b->year, b->price);

  fclose(ft);
  return arr;
}

// Zad 2:

int countByYear(Book *arr, int count, int year) {
  int n = 0;
  printf("\nBooks after %d:\n", year);
  for (int i = 0; i < count; i++) {
    if (arr[i].year > year) {
      n++;
      printf("%s - %s - %d - %.2f\n", arr[i].title, arr[i].id, arr[i].year,
             arr[i].price);
    }
  }
  if (n == 0) {
    printf("No such books");
    return 0;
  }

  return n;
}

// Zad 3:

void saveLibraryBin(Book *arr, int count) {
  FILE *fb = fopen("books.bin", "wb");
  if (fb == NULL) {
    printf("fb error");
    exit(1);
  }

  fwrite(arr, sizeof(Book), count, fb);

  fclose(fb);
}

void findBookById(char *id) {
  FILE *fb = fopen("books.bin", "rb");
  if (fb == NULL) {
    printf("fb error");
    exit(1);
  }

  int found = 0;
  Book b;
  while (fread(&b, sizeof(Book), 1, fb) == 1) {
    if (strcmp(b.id, id) == 0) {
      found = 1;
      printf("Bin Title: %49s\n", b.title);
      printf("Bin ID: %6s\n", b.id);
      printf("Bin Year: %d\n", b.year);
      printf("Bin Title: %.2f\n", b.price);
      break;
    }
  }

  if (!found) {
    printf("Book ID not found");
    exit(1);
  }

  fclose(fb);
}

int main(void) {
  Book *arr = NULL;
  int count = 0;

  // Zad 1:
  arr = addBook(arr, &count);
  arr = addBook(arr, &count);
  arr = addBook(arr, &count);

  // Zad 2:
  int year = 2015;
  int n = 0;
  n = countByYear(arr, count, year);
  printf("Count of books after %d: %d\n", year, n);

  // Zad 3:
  char id[7];
  printf("Search id (example id: A1234B): ");
  scanf("%6s", id);
  saveLibraryBin(arr, count);
  findBookById(id);

  free(arr);
  return 0;
}
