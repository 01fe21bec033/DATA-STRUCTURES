#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
  
#define SIZE 20

struct DataItem
{
  int data;
  int key;
};

struct DataItem *hashArray[SIZE];
struct DataItem *dummyItem;
struct DataItem *item;

int hashCode(int key)
{
  return key % SIZE;
}

struct DataItem *search(int key)
{
  int hashIndex = hashCode(key);


  while (hashArray[hashIndex] != NULL)
  {
    if (hashArray[hashIndex]->key == key)
    {
      return hashArray[hashIndex];
    }
    ++hashIndex;
    hashIndex %= SIZE;
  }

  return NULL;
}

void insert(int key, int data)
{
  struct DataItem *item = (struct DataItem *)malloc(sizeof(struct DataItem));
  item->data = data;
  item->key = key;

  int hashIndex = hashCode(key);


  while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1)
  {
    ++hashIndex;
    hashIndex %= SIZE;
  }

  hashArray[hashIndex] = item;
}

struct DataItem *delete(struct DataItem *item)
{
  int key = item->key;

  int hashIndex = hashCode(key);


  while (hashArray[hashIndex] != NULL)
  {
    if (hashArray[hashIndex]->key == key)
    {
      struct DataItem *temp = hashArray[hashIndex];
      hashArray[hashIndex] = dummyItem;
      return temp;
    }
    ++hashIndex;
    hashIndex %= SIZE;
  }

  return NULL;
}

void display()
{
  int i;

  for (i = 0; i < SIZE; i++)
  {
    if (hashArray[i] != NULL && hashArray[i]->key != -1)
    {
      printf("(%d, %d) ", hashArray[i]->key, hashArray[i]->data);
    }
  }

  printf("\n");
}

int main()
{
  dummyItem = (struct DataItem *)malloc(sizeof(struct DataItem));
  dummyItem->data = -1;
  dummyItem->key = -1;

  insert(1, 10);
  insert(2, 20);
  insert(42, 30);
  insert(4, 40);
  insert(12, 50);

  display();

  item = search(42);

  if (item != NULL)
  {
    printf("Element found: %d\n", item->data);
  }
  else
  {
    printf("Element not found\n");
  }

  delete (item);

  item = search(42);

  if (item != NULL)
  {
    printf("Element found: %d\n", item->data);
  }
  else
  {
    printf("Element not found\n");
  }

  return 0;
}
