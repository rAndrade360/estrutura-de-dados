#include <stdio.h>

struct  node {
  int value;
  struct node* next;   
};

typedef struct node Node;

struct list {
  struct node* start;
  struct node* end;
  int size; 
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
  list->size = 0;
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
    list->size++;
}

void insertAtTheEnd(List* list, int value) {
    if(list->size == 0) {
      insertAtTheBeginning(list, value);
    }else
    {
    Node* node = createNode(value);
    node->next = NULL;
    list->end->next = node;
    list->end = node;
    list->size++;
      }
}

void insertInTheMiddle(List* list, int value, int position) {
  if(list->size == 0 || position <= 1) {
     insertAtTheBeginning(list, value);
  }else if(position >= list->size){
     insertAtTheEnd(list, value);
  }else{  
  Node* node = createNode(value);
  Node* current = getCurrentNode(list, position);
  node->next = current->next;
  current->next = node;
  list->size++;
  }
}

void removeFromTheBeginning(List* list) {
    if(list->size < 1) {
      printf("Cannot remove from an empty list");
    }else{
    Node* start = list->start;
    list->start = start->next;
    free(start);
    list->size--;
    }
}

void removeFromTheEnd(List* list) {
    if(list->size < 1) {
        printf("Cannot remove from an empty list");
    }else if(list->size == 1) {
        removeFromTheBeginning(list);
    }else{
    Node* current = getCurrentNode(list, list->size);
  free(current->next);
  current->next = NULL;
  list->end = current;
  list->size--;
  }
}

void removeFromTheMiddle(List* list, int position) {
    if(list->size < 1) {
        printf("Cannot remove from an empty list");
    }else if(list->size == 1) {
        removeFromTheBeginning(list);
    }else if(list->size <= position){
        removeFromTheEnd(list);
    }else {
      Node* current = getCurrentNode(list, list->size);
      Node* toRemove = current->next;
      current->next = toRemove->next;
      toRemove->next = NULL;
      free(toRemove);
      list->size--;
    }
}

void printList(List* list) {
    Node* current = list->start;
    for (int i = 1; i <= list->size; i++) {
        printf("%d --> ", current->value);
        current = current->next;
    }
}

Node* searchNodeByPosition(List* list, int position) {
    int currentPosition = position + 1;
    Node* result = getCurrentNode(list, currentPosition);
    return result;
}

Node* searchNodeByValue(List* list, int value) {
    Node* current = list->start;
      for (int i = 1; i < list->size; i++) {
          if(current->value == value) {
              break;
          }
        current = current->next;
      }
    return current;
}

Node* getCurrentNode(List* list, int limitValue) {
    Node* current = list->start;
      for (int i = 1; i < limitValue; i++) {
        current = current->next;
      }
    return current;
}