

int main() {
  // --- Types of data ---
  int x = 52;              // Whole numbers (integer)
  double y = 6.4715156132; // Real numbers (64bit)
  float z = 4.922;         // Real numbers (32bit)
  char a = 'B';            // Characters

  // --- If Else statements ---
  if (x > y) {
    // code;
  } else {
    // code;
  }

  // --- Switch-Case statements ---
  switch (x) {
  case 1:
    // code;
    break;
  case 2:
    // code;
    break;
  default:
    break;
  }

  // --- For loop ---
  for (int i = 0; i < 10; i++) {
    // code;
  }

  // --- While loop ---
  while (x > 2) {
    x++;
    // code;
    if (x == 10) {
      break;
    }
  }

  // --- Do-While loop ---
  do {
    // code;
    x++;
  } while (x < 10);

  // --- Arrays ---
  int array1[10];
  for (int i = 0; i < 10; i++) {
    array1[i] = i * 2;
  }

  // Finding the smallest number in an array
  int min = array1[0];
  for (int i = 0; i < 10; i++) {
    if (array1[i] < min) {
      min = array1[i];
    }
  }

  // Finding the largest number in an array
  int max = array1[0];
  for (int i = 0; i < 10; i++) {
    if (array1[i] > max) {
      max = array1[i];
    }
  }

  // Finding average
  int sum = 0;
  double avarage = 0;
  for (int i = 0; i < 10; i++) {
    sum += array1[i];
    // Забележка: i започва от 0, за коректна средна стойност обикновено се дели
    // на броя елементи (10)
    avarage = (double)sum / (i + 1);
  }

  return 0;
}
