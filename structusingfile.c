#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int age;
    float GPA;
};

void saveStudentDetails(struct Student student[], int count) {
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    fprintf(file, "Name\t\tAge\tGPA\n");
    fprintf(file, "--------------------------------\n");

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\t\t%d\t%.2f\n", student[i].name, student[i].age, student[i].GPA);
    }

    fclose(file);
    printf("Student details saved successfully.\n");
}

int main() {
    struct Student students[5];

    // Get student details from the user
    for (int i = 0; i < 5; i++) {
        printf("Enter details for Student %d:\n", i + 1);
        printf("Name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);

        printf("Age: ");
        scanf("%d", &students[i].age);

        printf("GPA: ");
        scanf("%f", &students[i].GPA);

        // Clear the input buffer
        while (getchar() != '\n');

        printf("\n");
    }

    saveStudentDetails(students, 5);

    return 0;
}
