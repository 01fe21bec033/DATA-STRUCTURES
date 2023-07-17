#include <stdio.h>
#include <stdlib.h>
int main()
{
  int i, num;
  FILE *fp;
  fp = fopen("output.txt", "w");
  if (fp == NULL)
  {
    printf("Error opening output file");
    exit(1);
  }
  for (i = 0; i < 12; i++)
  {
    printf("%d ", i);
    fprintf(fp, "%d\n");
  }
  fclose(fp);
  fp = fopen("output.txt", "r");
  if (fp == NULL)
  {
    printf("Error opening output file");
    exit(1);
  }
  for (i = 0; i <= 12; i++)
  {
    fscanf(fp, "%d", &num);
    printf("%d\n", num);
  }
  fclose(fp);
  return 0;
}