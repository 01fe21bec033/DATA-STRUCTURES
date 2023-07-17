#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
  char items[MAX_SIZE][MAX_SIZE];
  int top;
} Stack;

void push(Stack *stack, const char *item)
{
  strcpy(stack->items[++(stack->top)], item);
}

char *pop(Stack *stack)
{
  return stack->items[(stack->top)--];
}

char *postfixtoinfix(const char postfix[])
{
  Stack stack;
  stack.top = -1;
  int i;

  for (i = 0; postfix[i] != '\0'; i++)
  {
    if (postfix[i] >= 'a' && postfix[i] <= 'z')
    {
      char operand[MAX_SIZE];
      operand[0] = postfix[i];
      operand[1] = '\0';

      push(&stack, operand);
    }
    else
    {
      char operand2[MAX_SIZE], operand1[MAX_SIZE];
      strcpy(operand2, pop(&stack));
      strcpy(operand1, pop(&stack));

      char infix[MAX_SIZE];
      sprintf(infix, "(%s%c%s)", operand1, postfix[i], operand2);
      push(&stack, infix);
    }
  }
  return pop(&stack);
}

int main()
{
  char postfix[MAX_SIZE];
  printf("Enter postfix expression: ");
  fgets(postfix, sizeof(postfix), stdin);
  postfix[strcspn(postfix, "\n")] = '\0';

  char *infix = postfixtoinfix(postfix);
  printf("Infix expression: %s\n", infix);

  return 0;
}
