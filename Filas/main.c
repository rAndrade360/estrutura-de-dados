#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct element
  {
    struct element* next;
    char value[];
  };

typedef struct element Element;

struct queue
{
  struct element* start;
  struct element* end;
  int size;
};

typedef struct queue Queue;

Queue* initializeQueue() {
  Queue* queue = (Queue*) malloc(sizeof(Queue));
  queue->start = NULL;
  queue->end = NULL;
  queue->size = 0;
  return queue;
}

Element* createElement(char* value) {
  Element* element = (Element*) malloc(sizeof(Element));
  strcpy(element->value, value);
  return element;
}

void insertAtTheEnd(Queue* queue, char* value) {
  Element* element = createElement(value);
  element->next = NULL;
  if(queue->size < 1) {
    queue->start = element;
  } else {
      Element* last = queue->end;
      last->next = element;
  }
  queue->end = element;
  queue->size++;
}

void removeFromBeginning(Queue* queue) {
  if(queue->size < 1){
    printf("\nThe list is empty!\n");
  }else {
    Element* element = queue->start;
    queue->start = element->next;
    free(element);
   queue->size--;
  }
}

void printQueue(Queue* queue) {
  for (Element* element = queue->start; element != NULL; element = element->next)
  {
    printf("%s <-- ", element->value);
  }
  printf("NULL");
}

void menu() {
  printf("\n<-------MENU------->");
  printf("\n1. Insert element");
  printf("\n2. Remove element");
  printf("\n3. Print queue");
  printf("\n0. Exit\n");
}

int main () {
  int option;
  unsigned int sizeOfValue = 20;
  Queue* queue = initializeQueue();
  char* value = (char*) malloc(sizeof(char)*sizeOfValue);


  do
  {
    menu();
    printf("\n Choose an option: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      printf("\nEnter a value: ");
      scanf("%s", value);
      insertAtTheEnd(queue, value);
      printf("\nSuccess!\n");
      break;

    case 2:
      printf("\nRemoving...\n");
      removeFromBeginning(queue);
      break;

    case 3:
      printf("\nMy Queue\n");
      printQueue(queue);
      printf("\n");
      break;

    case 0:
      printf("\nExiting...\n");
      break;
    
    default:
      printf("\nInvalid option!\n");
      break;
    }

  } while (option !=0);
  
}