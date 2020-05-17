# clinked
A modern linked list library for C

## Aims
Clinked aims to provide a modern and easy-to-use interface for linked-lists. At it's current state clinked has functions for quickly initialising a list from an array and mapping a function through the list. 

# Example 
~~~~
#include "../clinked.c" //clinked.c should be in the same folder as your code

int main(int argc, char *argv[]) {
  argc < 2 ? fatalerror("You must enter at least 1 item as argument")
    : printf("Processing the list\n");
  printf("Displaying list items\n");
  struct node *list = processsublist(1, argc, argv); // ignoring first argument
  maplist(&displayitem, list);
  printf("Searching the string 'test' in the list\n");
  maplistarg(&searchitem, "test", list);
  maplist(&freeitem, list);
  return 0;
}
~~~~

There is still a lot to do, feel free to submit patches :).
