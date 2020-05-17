#include "../clinked.c" //clinked.c should be in the same folder as your code

int main(int argc, char *argv[]) {
  argc < 2 ? fatalerror("You must enter at least 1 item as argument")
    : printf("Processing the list\n");
  printf("Displaying list items\n");
  struct node *list = processsublist(1, argc, argv); // ignore first arg
  maplist(&displayitem, list);
  printf("Searching the string 'test' in the list\n");
  maplistarg(&searchitem, "test", list);
  maplist(&freeitem, list);
  return 0;
}