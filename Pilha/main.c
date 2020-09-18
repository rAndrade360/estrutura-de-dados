#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct element
  {
    struct element* next;
    int value;
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

Element* createElement(int value) {
  Element* element = (Element*) malloc(sizeof(Element));
  element->value = value;
  return element;
}



int main () {
  
}