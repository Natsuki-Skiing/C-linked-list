#include <stdbool.h>

// Adds doubly linked list functionality 

// This is a node of a list 
// As a pointer to next and previous node 
// Holds a integer value 

typedef struct _node{

    bool data;
    struct _node* next;
    struct _node* prv;
}node;


/*
List 
Has a sorted property, a boolean value
Has a node pointer to the hade and tail of the list 
If a list IS sorted some operations are performed quicker 
*/
typedef struct list{
    int sorted;
    
    node * head;
    node * end;
}list;

// Sorts provided list
void listSort(list *);

/*
If the list is sorted it passes the data into the correct position in that list
If the list Is not sorted then nothing happens*/
void insertNodeSort(list*,int);

/*
Adds the last two elemets in a list and adds the sum as a new element at the end of the list 
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
this must be used to properly set up and use a list 
lists WILL NOT WORK if not called 
example:
    list exampleList = listNew();
*/
list* listNew();

/*Returns the length of a list 
Number of elements*/
int listLen(list*);

/*returns the position of the first element that's data matches
the search term*/
int listDataSrsh(list*,int);

/*Compares two lists as a whole
returns 1 if all elements are the same
0 if not*/
int listCmp(list*,list*);

/*sum of all list elements*/
int listSum(list*);

/*Mean average of all list elements*/
float listMean(list*);

/* adds second list to end of first list and retuns a pointer to the new list*/
list* listJoin(list*,list*);

/*deletes a list
frees all memory used*/
void listDelete(list *);

/* Sorts list elements in ascending order*/
void listSort(list*);

/*Returns the element thats at the given index*/
node* listNodeIndex(list*,int);

/*calculates the most frequent data item in a list*/
int listMostFrequent(list*);

/*Both add data to end of a list 
listAdd just calls listAddEnd */
void listAdd(list*,int);
void listAddEnd(list*,int);