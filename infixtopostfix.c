#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#define MAX 50

struct infix
{
  char target[MAX];
  char stack[MAX];
  char *s, *t;
  int top;
};

void setexpr(struct infix *, char *);
void push(struct infix *, char);
char pop(struct infix *);
void convert(struct infix *);
int priority(char);
void show(struct infix *);

int main()
{
  struct infix expr;
  expr.top = -1;
  strcpy(expr.target, "");
  strcpy(expr.stack, "");
  expr.t = expr.target;
  expr.s = "";

  printf("Enter the infix expression: ");
  char input[MAX];
  fgets(input, sizeof(input), stdin);
  input[strcspn(input, "\n")] = '\0';

  setexpr(&expr, input);
  convert(&expr);

  printf("Postfix expression: %s\n", expr.target);

  return 0;
}

void setexpr(struct infix *p, char *str)
{
  p->s = str;
}

void push(struct infix *p, char c)
{
  if (p->top == MAX - 1)
    printf("Stack is Full\n");
  else
  {
    p->top++;
    p->stack[p->top] = c;
  }
}

char pop(struct infix *p)
{
  if (p->top == -1)
  {
    printf("Stack is Empty\n");
    return -1;
  }
  else
  {
    char item = p->stack[p->top];
    p->top--;
    return item;
  }
}

void convert(struct infix *p)
{
  char opr;
  while (*(p->s))
  {
    if (*(p->s) == ' ' || *(p->s) == '\t')
    {
      p->s++;
      continue;
    }
    if (isdigit(*(p->s)) || isalpha(*(p->s)))
    {
      while (isdigit(*(p->s)) || isalpha(*(p->s)))
      {
        *(p->t) = *(p->s);
        p->s++;
        p->t++;
      }
      *(p->t) = ' ';
      p->t++;
    }
    if (*(p->s) == '(')
    {
      push(p, *(p->s));
      p->s++;
    }
    if (*(p->s) == ')')
    {
      opr = pop(p);
      while (opr != '(')
      {
        *(p->t) = opr;
        p->t++;
        *(p->t) = ' ';
        p->t++;
        opr = pop(p);
      }
      p->s++;
    }
    if (*(p->s) == '+' || *(p->s) == '-' || *(p->s) == '*' || *(p->s) == '/' || *(p->s) == '%')
    {
      if (p->top != -1 && priority(p->stack[p->top]) >= priority(*(p->s)))
      {
        while (p->top != -1 && priority(p->stack[p->top]) >= priority(*(p->s)))
        {
          opr = pop(p);
          *(p->t) = opr;
          p->t++;
          *(p->t) = ' ';
          p->t++;
        }
      }
      push(p, *(p->s));
      p->s++;
    }
  }
  while (p->top != -1)
  {
    opr = pop(p);
    *(p->t) = opr;
    p->t++;
    *(p->t) = ' ';
    p->t++;
  }
  *(p->t) = '\0';
}

int priority(char x)
{
  if (x == '(')
    return 0;
  if (x == '+' || x == '-')
    return 1;
  if (x == '*' || x == '/' || x == '%')
    return 2;

  return 0;
}
