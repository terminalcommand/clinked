#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
  struct node* next;
  struct node* prev;
  char *value;
};

struct node *makenode(struct node* prev, struct node* next, char* value) {
  struct node *newnode = NULL;
  newnode = malloc( sizeof(struct node) );
  newnode->prev=prev;
  newnode->next=next;
  newnode->value=value;
  return newnode;
}

int fatalerror(char* message) {
  fprintf(stderr, "%s\n", message);
  exit(EXIT_FAILURE);
}

struct node *processlist(size_t length, char **list) {
  struct node *head = makenode(NULL, NULL, list[1]);
  struct node *cursor= head;
  
  for (int i = 2; i < length; i++) {
    struct node *new = makenode(cursor, NULL, list[i]);
    cursor->next = new;
    if (i == 2) { head=cursor; };
    cursor = new;
  }
  return head;
}

void maplist( void (*func)(struct node *), struct node *cursor) {
  for ( ;; ) {
    cursor->value != NULL ? (*func)(cursor): fatalerror("Empty node!");
    if (cursor->next==NULL) break;
    else cursor = cursor->next;
  }
}

void maplistarg(void (*func)(void *arg, struct node *), void *arg, struct node *cursor) {
  for ( ;; ) {
    cursor->value != NULL ? (*func)(arg, cursor): fatalerror("Empty node!");
    if (cursor->next==NULL) break;
    else cursor = cursor->next;
  }
}

void displayitem(struct node *item) {
  printf("%s\n", item->value);
}

void freeitem(struct node *item) {
  free(item);
}

void displaylist(struct node *cursor) {
  maplist(&displayitem, cursor);
}

void searchitem(void* searchstr, struct node *item) {
  if(strstr(item->value, (char*)searchstr)!=NULL) printf("Found a match: %s\n", item->value);
}

int main(int argc, char *argv[]) {
  argc < 2 ? fatalerror("You must enter at least 1 item as argument")
    : printf("Processing the list\n");
  printf("Displaying list items\n");
  struct node *list = processlist(argc, argv);
  maplist(&displayitem, list);
  printf("Searching the string 'test' in the list\n");
  maplistarg(&searchitem, "test", list);
  maplist(&freeitem, list);
  return 0;
}
