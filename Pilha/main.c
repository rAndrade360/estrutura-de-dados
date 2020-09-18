#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct element
  {
    struct element* next;
    char value[];
  };

typedef struct element Element;

struct stack
{
  struct element* start;
  int size;
};

typedef struct stack Stack;

Stack* initializeStack() {
  Stack* stack = (Stack*) malloc(sizeof(Stack));
  stack->start = NULL;
  stack->size = 0;
  return stack;
}

Element* createElement(char* value) {
  Element* element = (Element*) malloc(sizeof(Element));
  strcpy(element->value, value);
  return element;
}

void insertAtTheBeginning(Stack* stack, char* value) {
  Element* element = createElement(value);
  element->next = stack->start;
  stack->start = element;
  stack->size++;
}

void removeFromBeginning(Stack* stack) {
  if(stack->size < 1){
    printf("\nThe list is empty!\n");
  }else {
    Element* element = stack->start;
    stack->start = element->next;
    free(element);
   stack->size--;
  }
}

void printStack(Stack* stack) {
  for (Element* element = stack->start; element != NULL; element = element->next)
  {
    printf("[     %s     ]\n", element->value);
  }
}

void menu() {
  printf("\n<-------MENU------->");
  printf("\n1. Insert element");
  printf("\n2. Remove element");
  printf("\n3. Print stack");
  printf("\n0. Exit\n");
}

int main () {
  int option;
  Stack* stack = initializeStack();
  unsigned int sizeOfValue = 20;
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
      insertAtTheBeginning(stack, value);
      printf("\nSuccess!\n");
      break;

    case 2:
      printf("\nRemoving...\n");
      removeFromBeginning(stack);
      break;

    case 3:
      printf("\nMy Stack\n");
      printStack(stack);
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