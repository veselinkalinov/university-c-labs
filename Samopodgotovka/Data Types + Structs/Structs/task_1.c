#include <stdio.h>

typedef struct {
  char title[51];
  char author[41];
  char isbn[10];
  float price;
} Book;

void inputBook(Book *b) {
  printf("Title: ");
  scanf("%50s", b->title);

  printf("Author: ");
  scanf("%40s", b->author);

  printf("ISBN: ");
  scanf("%9s", b->isbn);

  printf("Price: ");
  scanf("%f", &b->price);
}

void printBook(Book b) {
  printf("Title: %s\nAuthor: %s\nISBN: %s\nPrice: %.2f\n", b.title, b.author,
         b.isbn, b.price);
}
int main() {

  Book b;
  inputBook(&b);
  printBook(b);

  return 0;
}
