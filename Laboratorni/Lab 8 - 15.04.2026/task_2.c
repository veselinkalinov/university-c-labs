#include <stdio.h>

#define MAX_STUDENTS 30
#define MAX_CLASSES 5

struct Student {
  char name[50];
  int number;
  float averageGrade;
};

struct SchoolClass {
  char className[10];
  int studentCount;
  struct Student students[MAX_STUDENTS];
};

struct GraduationYear {
  int classCount;
  struct SchoolClass classes[MAX_CLASSES];
};

float calculateClassAverage(struct SchoolClass schoolClass) {
  float sum = 0;
  int i;

  for (i = 0; i < schoolClass.studentCount; i++) {
    sum += schoolClass.students[i].averageGrade;
  }

  if (schoolClass.studentCount == 0) {
    return 0;
  }

  return sum / schoolClass.studentCount;
}

float calculateGraduationAverage(struct GraduationYear graduationYear) {
  float sum = 0;
  int totalStudents = 0;
  int i;
  int j;

  for (i = 0; i < graduationYear.classCount; i++) {
    for (j = 0; j < graduationYear.classes[i].studentCount; j++) {
      sum += graduationYear.classes[i].students[j].averageGrade;
      totalStudents++;
    }
  }

  if (totalStudents == 0) {
    return 0;
  }

  return sum / totalStudents;
}

int main(void) {
  struct GraduationYear graduationYear;

  printf("Vuvedete broi klasove (do %d): ", MAX_CLASSES);
  scanf("%d", &graduationYear.classCount);

  if (graduationYear.classCount < 1 ||
      graduationYear.classCount > MAX_CLASSES) {
    printf("Nevaliden broi klasove.\n");
    return 1;
  }

  for (int i = 0; i < graduationYear.classCount; i++) {
    printf("\nVuvedete ime na klas %d: ", i + 1);
    scanf("%9s", graduationYear.classes[i].className);

    printf("Vuvedete broi uchenici v %s (do %d): ",
           graduationYear.classes[i].className, MAX_STUDENTS);
    scanf("%d", &graduationYear.classes[i].studentCount);

    if (graduationYear.classes[i].studentCount < 1 ||
        graduationYear.classes[i].studentCount > MAX_STUDENTS) {
      printf("Nevaliden broi uchenici.\n");
      return 1;
    }

    for (int j = 0; j < graduationYear.classes[i].studentCount; j++) {
      printf("\nUchenik %d\n", j + 1);
      printf("Ime: ");
      scanf("%49s", graduationYear.classes[i].students[j].name);

      printf("Nomer v klasa: ");
      scanf("%d", &graduationYear.classes[i].students[j].number);

      printf("Sreden uspeh: ");
      scanf("%f", &graduationYear.classes[i].students[j].averageGrade);
    }
  }

  printf("\nSreden uspeh po klasove:\n");
  for (int i = 0; i < graduationYear.classCount; i++) {
    printf("%s -> %.2f\n", graduationYear.classes[i].className,
           calculateClassAverage(graduationYear.classes[i]));
  }

  printf("\nSreden uspeh na vipuska: %.2f\n",
         calculateGraduationAverage(graduationYear));

  return 0;
}
