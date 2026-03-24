#include <stdio.h>

typedef struct {
  char name[61];
  int fn;
  float grade;
  int group;
} Student;

void inputStudent(Student *s) {
  printf("Name: ");
  scanf("%60[^\n]", s->name);

  printf("FN: ");
  scanf("%d", &s->fn);

  printf("Grade: ");
  scanf("%f", &s->grade);

  printf("Group: ");
  scanf("%d", &s->group);
}

void printStudent(Student s) {
  printf("\nName:%s\nFN:%d\nGrade:%.2f\nGroup:%d", s.name, s.fn, s.grade,
         s.group);
}

int main() {
  Student s;
  inputStudent(&s);
  printStudent(s);

  return 0;
}
