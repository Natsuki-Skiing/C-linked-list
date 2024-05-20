// Adds doubly linked list functionality 

// This is a node of a list 
// As a pointer to next and previous node 
// Holds a integer value 
typedef struct node;

/*
List 
Has a sorted proporty, a boolean value
Has a node pointer to the hade and tail of the list 
If a list IS sorted some operations are performed quicker 
*/
typedef struct list;

// Sorts provided list
void listSort(list *);

/*
If the list is sorted it passes the data into the correct position in that list
If the list Is not sorted then nothing happens*/
void insertNodeSort(list*,int);

/*
Adds the last two elemnts in a list and adds the sum as a new element at the end of the list 
*/
void listGrow(list* );

/*
prints out a list
*/
void listPrint(list * );

/*
Delete all nodes in a list thats data matches the value given
Boolean condition to delete all elements or just the first instance 
false = first ONLY 
true = ALL
*/
void listDelData(list *  ,int,bool);

/*
removes the head(first element in the list)
*/
int listRemoveFst(list*);

/*
Remove the tail/ end of the passed list
*/
void listRemoveLst(list*);

/*sets up a new list
this must be used to proporly set up and use a list 
lists WILL NOT WORK if not called 
example:
    list exampleList = listNew();
*/
list* listNew();

/*Returns the lenght of a list 
Number of elements*/
int listLen(list*);


