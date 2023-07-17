#include <stdio.h>

int main()
{
  int i, j;
  FILE *fp;
  char buf[50];
  int cnt = 0;

  fp = fopen("tables.txt", "w");
  if (fp == NULL)
  {
    printf("Error opening file");
    exit(1);
  }

  for (i = 2; i <= 5; i++)
  {
    fprintf(fp, "Multiplication Table for %d:\n", i);
    for (j = 1; j <= 12; j++)
    {
      printf("%d x %d = %d\n", i, j, j * i);
      fprintf(fp, "%d x %d = %d\n", i, j, j * i);
    }
    fprintf(fp, "\n\n");
  }

  fclose(fp);
  printf("Tables have been written to the file 'tables.txt'\n");

  fp = fopen("tables.txt", "r");
  if (fp == NULL)
  {
    printf("Error opening file");
    exit(1);
  }

  printf("\nContents of 'tables.txt':\n\n");
  while (EOF != fscanf(fp, "%[^\n]\n", buf))
  {
    printf("%s", buf);
    printf("\n");
    cnt++;
  }
  if (cnt == 12 || cnt == 24)
  {
    printf("\n\n");
  }
  fclose(fp);

  return 0;
}
