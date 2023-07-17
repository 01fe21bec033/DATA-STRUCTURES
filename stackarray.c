#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
int top = -1;

int stackarray[SIZE];

void push(int x);
void pop();
void display();
int main()
{
  push(7);
  push(8);
  push(6);
  push(98);
  push(22);
  printf("\n The pushed elements are:");
  display();

  pop();
  printf("\n After popping elements are:");
  display();
}

void push(int x)
{
  if (top == SIZE)
  {
    printf("STACK IS FULL\n");
  }
  else
  {
    top = top + 1;
    stackarray[top] = x;
  }
}

void pop()
{
  if (top == -1)
  {
    printf("EMPTY STACK\n");
  }
  else
  {
    printf("\n %d ", stackarray[top]);
    top = top - 1;
  }
}

void display()
{
  int i;
  if (top == -1)
  {
    printf("EMPTY STACK!!\n");
  }
  else
  {
    // printf("The Stack ELements are:\n");
    for (i = top; i >= 0; i--)
    {
      printf("%d ", stackarray[i]);
    }
  }
}
