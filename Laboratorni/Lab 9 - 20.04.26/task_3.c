#include <stdio.h>

/* --- Car structure --- */
typedef struct {
  char brand[20];    /* марка */
  char model[6];     /* модел - 5 знака + '\0' */
  float engine;      /* обем на двигателя в литри */
  float price;       /* цена */
  char registration; /* регистрация: 'Y' или 'N' */
} Car;

/* --- Write one car record to text file --- */
void write_text(FILE *ft, Car *c) {
  fprintf(ft, "%-20s | %-5s | %4.1fL | %10.2f lv | %c\n", c->brand, c->model,
          c->engine, c->price, c->registration);
}

/* --- Subtask A: Create database - write to binary and text simultaneously ---
 */
void create_database() {
  FILE *fb = fopen("cars.bin", "wb");
  FILE *ft = fopen("cars.txt", "w");
  if (fb == NULL || ft == NULL) {
    printf("Error: cannot open files.\n");
    return;
  }

  /* Text file header */
  fprintf(ft, "%-20s | %-5s | %6s | %14s | %s\n", "Brand", "Model", "Engine",
          "Price", "Reg");
  fprintf(ft,
          "--------------------------------------------------------------\n");

  int n;
  printf("Number of cars: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    Car c;
    printf("\n--- Car %d ---\n", i + 1);

    printf("Brand: ");
    scanf("%19s", c.brand);

    printf("Model (max 5 chars): ");
    scanf("%5s", c.model);

    printf("Engine volume (L): ");
    scanf("%f", &c.engine);

    printf("Price: ");
    scanf("%f", &c.price);

    printf("Registration (Y/N): ");
    scanf(" %c", &c.registration);

    fwrite(&c, sizeof(Car), 1, fb);
    write_text(ft, &c);
  }

  fclose(fb);
  fclose(ft);
  printf("\nDatabase saved to 'cars.bin' and 'cars.txt'.\n");
}

/* --- Subtask A (continued): Add a new record to both files --- */
void add_car() {
  FILE *fb = fopen("cars.bin", "ab");
  FILE *ft = fopen("cars.txt", "a");
  if (fb == NULL || ft == NULL) {
    printf("Error: cannot open files. Run option 1 first.\n");
    return;
  }

  Car c;
  printf("Brand: ");
  scanf("%19s", c.brand);

  printf("Model (max 5 chars): ");
  scanf("%5s", c.model);

  printf("Engine volume (L): ");
  scanf("%f", &c.engine);

  printf("Price: ");
  scanf("%f", &c.price);

  printf("Registration (Y/N): ");
  scanf(" %c", &c.registration);

  fwrite(&c, sizeof(Car), 1, fb);
  write_text(ft, &c);

  fclose(fb);
  fclose(ft);
  printf("Record added.\n");
}

/* --- Read both files and print side by side for comparison --- */
void compare_files() {
  FILE *fb = fopen("cars.bin", "rb");
  FILE *ft = fopen("cars.txt", "r");
  if (fb == NULL || ft == NULL) {
    printf("Error: cannot open files. Run option 1 first.\n");
    return;
  }

  printf("=== Binary file (cars.bin) ===\n");
  printf("%-20s | %-5s | %6s | %14s | %s\n", "Brand", "Model", "Engine",
         "Price", "Reg");
  printf("--------------------------------------------------------------\n");

  Car c;
  while (fread(&c, sizeof(Car), 1, fb) == 1) {
    printf("%-20s | %-5s | %4.1fL | %10.2f lv | %c\n", c.brand, c.model,
           c.engine, c.price, c.registration);
  }
  fclose(fb);

  printf("\n=== Text file (cars.txt) ===\n");
  char line[200];
  while (fgets(line, sizeof(line), ft)) {
    printf("%s", line);
  }
  fclose(ft);
}

/* --- Main menu --- */
int main() {
  int choice;
  printf("1. Create database (write to binary + text)\n");
  printf("2. Add new car record\n");
  printf("3. Compare binary and text file\n");
  printf("Choice: ");
  scanf("%d", &choice);

  switch (choice) {
  case 1:
    create_database();
    break;
  case 2:
    add_car();
    break;
  case 3:
    compare_files();
    break;
  default:
    printf("Invalid choice.\n");
  }

  return 0;
}
