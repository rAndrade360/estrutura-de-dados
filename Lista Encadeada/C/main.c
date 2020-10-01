#include <stdio.h>
#include <stdlib.h>

struct node {
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

void showMenu(void) {
    printf("\n--------Menu---------");
    printf("\n1. Insert at the beginning of list");
    printf("\n2. Insert at the middle of list");
    printf("\n3. Insert at the end of list");
    printf("\n4. Remove from the beginning of list");
    printf("\n5. Remove from the middle of list");
    printf("\n6. Remove from the end of list");
    printf("\n7. Print list");
    printf("\n8. Search node by position");
    printf("\n9. Search node by value");
    printf("\n0. exit");
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
    if(list->size == 0) {
      printf("\nEmpty list!\n");
    }
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

int verifyIfExistsValue(List* list, int value) {
    Node* current = list->start;
    int exists = 0;
      for (int i = 1; i < list->size; i++) {
          if(current->value == value) {
              exists = 1;
              break;
          }
        current = current->next;
      }
    return exists;
}

Node* getCurrentNode(List* list, int limitValue) {
    Node* current = list->start;
      for (int i = 1; i < limitValue; i++) {
        current = current->next;
      }
    return current;
}

int main() {
  int option;
  int value, position;
  List* list = initializeList();

  do
  {
    showMenu();
    
    printf("\n Choose an option: ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
      printf("Enter a value to insert at the beginning of the list: ");
      scanf("%d", &value);
      insertAtTheBeginning(list, value);
        break;

    case 2:
      printf("\nEnter a value to insert at the middle of the list: ");
      scanf("%d", &value);
      printf("\nEnter an position to insert the value: ");
      scanf("%d", &position);
      insertInTheMiddle(list, value, position);
        break;

    case 3:
      printf("\nEnter a value to insert at the end of the list: ");
      scanf("%d", &value);
      insertAtTheEnd(list, value);
        break;

    case 4:
      printf("\nRemoving from the beginning...\n");
      removeFromTheBeginning(list);
        break;

    case 5:
      printf("\nEnter a position to remove from the middle of the list: ");
      scanf("%d", &position);
      removeFromTheMiddle(list, position);
        break;

    case 6:
      printf("\nRemoving from the end...\n");
      removeFromTheEnd(list);
        break;

    case 7:
      printf("\nList:\n");
      printList(list);
      printf("\n");
        break;

    case 8:
      printf("\nEnter a position to search node: ");
      scanf("%d", &position);
      Node* node = searchNodeByPosition(list, position);
      printf("\nNode value: %d", node->value);
        break;

    case 9:
      printf("\nEnter a value to search node: ");
      scanf("%d", &value);
      int exists = verifyIfExistsValue(list, value);
      if(exists == 1) {
          printf("\nYeah! The value exists!\n");
      }else{
          printf("\nOh no! The value not exists!\n");
      }
        break;

    case 0:
      printf("\nExiting graciously...\n");
    
    default:
      printf("\nInvalid option! :(\n");
        break;
    }
  } while (option != 0);
  
}