#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_SIZE 10000

struct Stack {
    int items[STACK_SIZE];
    int top;
};

void push(struct Stack* stack, int item, FILE* push_log_file)
 {
    if (stack->top == STACK_SIZE - 1) {
        printf("Stack overflow! Skipping push of %d.\n", item);
        return;
    }
    stack->top++;
    stack->items[stack->top] = item;
    fprintf(push_log_file, "Pushed %d onto the stack.\n", item);
}

int pop(struct Stack* stack, FILE* pop_log_file) {
    if (stack->top == -1) {
        printf("Stack underflow!\n");
        return -1;
    }
    int item = stack->items[stack->top];
    stack->top--;
    fprintf(pop_log_file, "Popped %d from the stack.\n", item);
    return item;
}

int main() {
    struct Stack stack;
    stack.top = -1;

    FILE* random_file = fopen("random.txt", "r");
    FILE* push_log_file = fopen("push.txt", "w");
    FILE* pop_log_file = fopen("pop.txt", "w");
    FILE* operation_log_file = fopen("operation.txt", "w");

    if (random_file == NULL || push_log_file == NULL || pop_log_file == NULL || operation_log_file == NULL) {
        printf("Error opening files!\n");
        exit(1);
    }

    int number;
    while (fscanf(random_file, "%d", &number) == 1) {
        push(&stack, number, push_log_file);
        fprintf(operation_log_file, "Pushed %d onto the stack.\n", number);
    }

    while (stack.top != -1) {
        int item = pop(&stack, pop_log_file);
        fprintf(operation_log_file, "Popped %d from the stack.\n", item);
    }

    fclose(random_file);
    fclose(push_log_file);
    fclose(pop_log_file);
    fclose(operation_log_file);

    return 0;
}
