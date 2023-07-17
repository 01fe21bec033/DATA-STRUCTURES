#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 6
int stack[MAX];
int top = -1;

struct Vertex
{
  char label;
  bool visited;
};

struct Vertex *lstVertices[MAX];
int adjMatrix[MAX][MAX];
int VertexCount = 0;

void push(int data)
{
  stack[++top] = data;
}

int pop()
{
  return stack[top--];
}

bool isStackEmpty()
{
  return top == -1;
}

void addVertex(char label)
{
  struct Vertex *vertex = (struct Vertex *)malloc(sizeof(struct Vertex));
  vertex->label = label;
  vertex->visited = false;
  lstVertices[VertexCount++] = vertex;
}

void addEdge(int start, int end)
{
  adjMatrix[start][end] = 1;
  adjMatrix[end][start] = 1;
}

void displayVertex(int vertexIndex)
{
  printf("%c\n", lstVertices[vertexIndex]->label);
}

int getAdjUnvisitedVertex(int vertexIndex)
{
  int i;
  for (i = 0; i < VertexCount; i++)
  {
    if (adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false)
      return i;
  }
  return -1;
}

void depthFirstSearch()
{
  int i;
  lstVertices[0]->visited = true;
  displayVertex(0);
  push(0);
  int unvisitedVertex;
  int tempVertex;
  while (!isStackEmpty())
  {
    tempVertex = pop();
    while ((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1)
    {
      lstVertices[unvisitedVertex]->visited = true;
      displayVertex(unvisitedVertex);
      push(unvisitedVertex);
    }
  }
  for (i = 0; i < VertexCount; i++)
  {
    lstVertices[i]->visited = false;
  }
}

int main()
{
  int i, j;
  for (i = 0; i < MAX; i++)
    for (j = 0; j < MAX; j++)
      adjMatrix[i][j] = 0;

  addVertex('s');
  addVertex('a');
  addVertex('b');
  addVertex('c');
  addVertex('d');
  addEdge(0, 1);
  addEdge(0, 2);
  addEdge(0, 3);
  addEdge(1, 4);
  addEdge(2, 4);
  addEdge(3, 4);

  printf("\n\nDepth First Search for 6 MAX\n\n");
  depthFirstSearch();

  return 0;
}
