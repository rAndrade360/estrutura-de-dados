#include <stdio.h>

struct  node {
  int value;
  struct node* next;   
};

typedef struct node Node;

struct list {
  struct node* start;
  struct node* end;
  int length; 
};

typedef struct list List;

List* initializeList(void);
Node* createNode(int);

int main() {
  printf("\nHello!\n");
}

List* initializeList(void) {
  List* list = (List*) malloc(sizeof(List));
  list->start = list->end = NULL;
  list->length = 0;
  return list;
}

Node* createNode(int value) {
  Node* node = (Node*) malloc(sizeof(Node));
  node->value = value;
  return node;
}

void insertAtTheBeginning(List* list, int value) {
    Node* node = createNode(value);
    node->next = list->start;
    if(list->start != NULL){
      list->end = node;
    }
    list->start = node;
    list->length++;
}

void insertAtTheEnd(List* list, int value) {
    if(list->length = 0) {
      return insertAtTheBeginning(list, value);
    }
    Node* node = createNode(value);
    node->next = NULL;
    list->end->next = node;
    list->end = node;
    list->length++;
}

void insertInTheMiddle(List* list, int value, int position) {
  if(list->length = 0 || position <= 1) {
    return insertAtTheBeginning(list, value);
  }else if(position >= list->length){
    return insertAtTheEnd(list, value);
  }
  Node* node = createNode(value);
  Node* current = list->start;
  for (int i = 1; i < position; i++)
  {
      current = current->next;
  }
  node->next = current->next;
  current->next = node;
  list->length++;
}