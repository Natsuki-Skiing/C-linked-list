#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct _node{
    char data [15];
    struct _node* next;
}node;
typedef struct list{
    char listName[10];
    node * head;
    node * end;
}list;


void addNode(list * list,char * data){
    node * n = malloc(sizeof(node));
    strcpy(n->data,data);
    n->next =NULL;
   
    
    if(list->head == NULL){
        list->head = n;
        list-> end = n;
    }else{
        list->end->next = n;
        list->end = n ;

    }

}

void printList(list * list){
    node * head = list->head;
    char name[10];
    strcpy(name,list->listName);
    printf("%s: ",name);
    if(list ->head == NULL){
        printf("List is empty\n");
    }else{
        node *current = head;
        do{
            printf("%s ,",current->data);
            current = current ->next;
        }while(current !=NULL);
        printf("\n");
    }
    
}

int removeFstElement(list * list){
    if(list->head != NULL){

    
        if(list->head->next == NULL){
            free(list->head);
        }else{
            node * temp = list->head->next;

            free(list->head);

            list->head = temp;
        }
    }
    


}

void removeLstElement(list * list ){
    node * head = list->head;
    node * end = list->end;
    node * temp = head;
   
}
list *newList(char* name){
   list * pList = malloc(sizeof(list));
   pList->head= NULL;
   pList ->end = NULL;
   strcpy(pList ->listName,name); 
   return(pList);

}

int listLen(list * list){
    int count = 0;

    if(list->head != NULL){
        count ++;
        node * currentNode = list->head;
        while(currentNode->next != NULL){
            count++;
            currentNode = currentNode->next;

        }
    }
    return(count);
}
int main(){
    list *testList = newList("Test List");
    printf("%d\n",listLen(testList));
    addNode(testList,"Hallo");
    addNode(testList,"Hallo");
    addNode(testList,"Hallo");
    printf("%d\n",listLen(testList));
    return(0);
}