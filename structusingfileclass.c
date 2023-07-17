#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct roll
{
  int num;
  char name[25];
};

int main()
{
  FILE *fp;
  int i, j = 0;

  struct roll b1[45];
  struct roll *ptr;
  ptr = b1;

  fp = fopen("file.txt", "w+");
  if (fp == NULL)
  {
    printf("Error opening file\n");
    exit(1);
  }

  printf("Roll and Name\n");
  for (i = 0; i <= 3; i++)
  {
    scanf("%d%s", &(ptr->num), ptr->name);
    fprintf(fp, "%d %s\n", ptr->num, ptr->name);
  }
  fclose(fp);

  fp = fopen("file.txt", "r");
  if (fp == NULL)
  {
    printf("Error opening the file\n");
    exit(1);
  }

  ptr = b1;

  while (fscanf(fp, "%d%s", &(ptr->num), ptr->name) != EOF)
  {
    ptr++;
  }
  fclose(fp);

  fp = fopen("file.txt", "r");
  if (fp == NULL)
  {
    printf("Error opening the file\n");
    exit(1);
  }

  ptr = b1;

  while (fscanf(fp, "%d%s", &(ptr->num), ptr->name) != EOF)
  {
    if (strcmp(ptr->name, "kit") == 0)
      j++;
    ptr++;
  }
  printf("\nkit appears %d times\n", j);
  fclose(fp);

  return 0;
}
