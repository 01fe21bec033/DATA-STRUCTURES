#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
  char name[50];
  int rollNo;
  int marks;
};

void writeStudentDetails(struct Student students[], int count)
{
  FILE *file = fopen("students.txt", "w");
  if (file == NULL)
  {
    printf("Unable to open the file.\n");
    return;
  }

  for (int i = 0; i < count; i++)
  {
    fprintf(file, "%s %d %d\n", students[i].name, students[i].rollNo, students[i].marks);
  }

  fclose(file);
  printf("Student details saved successfully.\n");
}

void readStudentDetails(struct Student students[], int count)
{
  FILE *file = fopen("students.txt", "r");
  if (file == NULL)
  {
    printf("Unable to open the file.\n");
    return;
  }

  for (int i = 0; i < count; i++)
  {
    fscanf(file, "%s %d %d\n", students[i].name, &students[i].rollNo, &students[i].marks);
  }

  fclose(file);
  printf("Student details read successfully.\n");
}

void sortStudentDetails(struct Student students[], int count)
{
  struct Student temp;
  int i, j;

  for (i = 0; i < count - 1; i++)
  {
    for (j = 0; j < count - i - 1; j++)
    {
      if (students[j].rollNo > students[j + 1].rollNo)
      {
        temp = students[j];
        students[j] = students[j + 1];
        students[j + 1] = temp;
      }
    }
  }

  printf("Student details sorted by roll number.\n");
}

int main()
{
  struct Student students[5];

  // Get student details from the user
  for (int i = 0; i < 5; i++)
  {
    printf("Enter details for Student %d:\n", i + 1);

    printf("Name: ");
    fgets(students[i].name, sizeof(students[i].name), stdin);

    printf("Roll No: ");
    scanf("%d", &students[i].rollNo);

    printf("Marks: ");
    scanf("%d", &students[i].marks);

    // Clear the input buffer
    while (getchar() != '\n')
      ;

    printf("\n");
  }

  // Write student details to file
  writeStudentDetails(students, 5);

  // Read student details from file
  readStudentDetails(students, 5);

  // Sort student details by roll number
  sortStudentDetails(students, 5);

  // Display sorted student details
  printf("\n\tSorted Student Details\n\n");
  for (int i = 0; i < 5; i++)
  {
    printf("Name: %s Roll No: %d Marks: %d\n", students[i].name, students[i].rollNo, students[i].marks);
  }

  return 0;
}
