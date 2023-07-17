#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 6
int queue[MAX];
int rear = -1;
int front = 0;
int QueueItemCount = 0;

struct Vertex
{
  char label;
  bool visited;
};

struct Vertex *lstVertices[MAX];
int adjMatrix[MAX][MAX];
int VertexCount = 0;

void insert(int data)
{
  queue[++rear] = data;
  QueueItemCount++;
}

int removeData()
{
  QueueItemCount--;
  return queue[front++];
}

bool isQueueEmpty()
{
  return QueueItemCount == 0;
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

void breadthFirstSearch()
{
  int i;
  lstVertices[0]->visited = true;
  displayVertex(0);
  insert(0);
  int unvisitedVertex;
  int tempVertex;
  while (!isQueueEmpty())
  {
    tempVertex = removeData();
    while ((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1)
    {
      lstVertices[unvisitedVertex]->visited = true;
      displayVertex(unvisitedVertex);
      insert(unvisitedVertex);
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

  printf("\n\nBreadth First Search For 6 MAX\n\n");
  breadthFirstSearch();

  return 0;
}