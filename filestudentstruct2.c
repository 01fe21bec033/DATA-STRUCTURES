#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
  char name[50];
  int roll;
  float marks;
} s;
int main()
{
  FILE *fptr;
  struct student s[5], temp;
  int i, j;
  fptr = fopen("file.txt", "wb");
  for (i = 0; i < 5; i++)
  {
    printf("Enter name: ");
    scanf("%s", s[i].name);
    printf("Enter roll number: ");
    scanf("%d", &s[i].roll);
    printf("Enter marks: ");
    scanf("%f", &s[i].marks);
    fwrite(&s[i], sizeof(s[i]), 1, fptr);
  }
  fclose(fptr);
  fptr = fopen("file.txt", "rb");
  fread(&s, sizeof(s), 1, fptr);
  for (i = 0; i < 5; i++)
  {
    for (j = i + 1; j < 5; j++)
    {
      if (s[i].roll > s[j].roll)
      {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
      }
    }
  }
  printf("\nSorted by roll number:\n");
  for (i = 0; i < 5; i++)
  {
    printf("\nName: %s\nRoll: %d\nMarks: %.2f\n", s[i].name, s[i].roll, s[i].marks);
  }
  fclose(fptr);
  return 0;
}