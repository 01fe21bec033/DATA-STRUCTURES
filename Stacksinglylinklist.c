#include <stdio.h>
#include <stdlib.h>

// Node structure for the singly linked list
struct Node
{
  int data;
  struct Node *next;
};

// Stack structure
struct Stack
{
  struct Node *top;
};

// Function to create a new node
struct Node *createNode(int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (newNode == NULL)
  {
    printf("Memory allocation failed!\n");
    exit(1);
  }
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
  return stack->top == NULL;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int data)
{
  struct Node *newNode = createNode(data);
  newNode->next = stack->top;
  stack->top = newNode;
  printf("%d pushed to the stack.\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Stack is empty!\n");
    exit(1);
  }
  struct Node *temp = stack->top;
  int data = temp->data;
  stack->top = stack->top->next;
  free(temp);
  return data;
}

// Function to get the top element of the stack
int peek(struct Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Stack is empty!\n");
    exit(1);
  }
  return stack->top->data;
}

// Function to display the elements of the stack
void display(struct Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Stack is empty!\n");
    return;
  }
  struct Node *current = stack->top;
  printf("Stack elements: ");
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

// Main function
int main()
{
  struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
  stack->top = NULL;

  push(stack, 10);
  push(stack, 20);
  push(stack, 30);
  display(stack);

  printf("Top element: %d\n", peek(stack));

  printf("Popped element: %d\n", pop(stack));
  printf("Popped element: %d\n", pop(stack));
  display(stack);

  printf("Top element: %d\n", peek(stack));

  return 0;
}