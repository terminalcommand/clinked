# clinked
A modern linked list library for C

## Aims
Clinked aims to provide a modern and easy-to-use interface for linked-lists. At it's current state clinked has functions for quickly initialising a list from an array and mapping a function through the list. 

# Example 
~~~~
struct node *list = processlist(argc, argv);
printf("Displaying list items\n");
maplist(&displayitem, list);
printf("Searching the string 'test' in the list\n");
maplistarg(&searchitem, "test", list);
maplist(&freeitem, list);
~~~~

There is still a lot to do, this is the first initial commit.
Feel free to submit patches :).
