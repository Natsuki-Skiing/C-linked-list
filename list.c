#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct _node{
    int data;
    struct _node* next;
    struct _node* prv;
}node;
typedef struct list{
    bool sorted;
    
    node * head;
    node * end;
}list;


void addNode(list * list,int data){
    node * n = malloc(sizeof(node));
     //strcpy(n->data,data);
    n->data = data;
    n->next =NULL;
   
    
    if(list->head == NULL){
        list->head = n;
        list-> end = n;
        list-> sorted = true;
    }else{
        // Checking to see if the list is sorted and if the data to be added is larger than the tail data and keeping the sorted quality if so
        if(!(list->sorted && list->end->data < data)){
            list->sorted = false;
        }
        list->end->next = n;
        n->prv = list->end;
        list->end = n ;

        

    }

}


void insertNodePos(list * list, int data,int desPos){
    // Inserts data in list at desired position 
    // if list len < desired position it dumps it on the end 
    
    if(desPos > -1){
        int pos = 0;
        bool inserted = false;
        node * newNode = malloc(sizeof(node));
        newNode->data = data;
        if(list->head == NULL){
            addNode(list,data);
        }else{
             // Looping through the list till get to the desired position
            node * currentNode = list ->  head;
            while(currentNode != NULL ||pos <= desPos){

                if(pos == desPos){
                    //Inserting the node
                    inserted = true;
                    newNode ->next = currentNode;
                    newNode ->prv = currentNode ->prv;

                    currentNode->prv->next = newNode;
                    currentNode->prv = newNode;
                    break;

                }else{
                    if(currentNode ->next == NULL){
                        break;
                    }
                    currentNode = currentNode->next;
                    pos ++;
                }
    }
        // pushing the value to the end of the list as index> list length 
        if(! inserted){
            addNode(list,data);
        }
    }

        }
       
   
}

void insertNodeSort(list * list,int data){
    node * n = malloc(sizeof(node));
    //strcpy(n->data,data);
    n->data = data;
    n->next =NULL;
   
    
    if(list->head == NULL){
        list->head = n;
        list-> end = n;
        list->sorted = true;
    }else if(list->sorted){
        // I wanna check to see if the node is either bigger or smaller than the head and tail, if so this allows for T(1) for insertion
        if(data < list->head->data){
            node * temp = list->head;
            temp->prv = n;
            n->next = temp;
            list->head = n;
        // Bigger than end 
        }else if (data > list->end->data){
            node * temp = list->end;
            temp->next = n;
            n ->prv = list->end;
            list->end = n;
            
        }else{
            // Searching through the list to find correct position
            node * currentNode = list -> head;
            while(currentNode->next != NULL){
                if(currentNode -> data < data && currentNode -> next->data > data){
                    // Inserting the data into the correct position 
                    n->next = currentNode->next;
                    currentNode ->next ->prv = n;
                    currentNode-> next = n;

                    break;
                }else{
                    currentNode= currentNode->next;
                }
            }
        }
        
        // list->end->next = n;
        // n->prv = list->end;
        // list->end = n ;

    }

}

void printList(list * list){
    node * head = list->head;

    

    if(list ->head == NULL){
        printf("List is empty\n");
    }else{
        node *current = head;
        while(current !=NULL){
            printf("%d,",current->data);
            current = current ->next;
        }
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
    node * temp = list->end->prv;
    free(list->end);
    temp->next = NULL;
    list-> end = temp;
    
   
}
list *newList(char* name){
   list * pList = malloc(sizeof(list));
   pList->head= NULL;
   pList ->end = NULL;
   pList -> sorted = false;

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

int listDataSrch(list* list , int data){
    int index = 0;
    bool found = false;
    if(list->head == NULL){
        index = -1;
    }else{
        if(list->sorted){
            if(list->head->data > data || data > list->end->data){
                return(-1);
            }else{
                node * currentNode = list-> head;
                while(currentNode != NULL){
                    if(currentNode->data == data){
                        found = true;
                        break;
                    }else if(currentNode-> data > data){
                        break;
                    }
                    else{
                        index++;
                        currentNode = currentNode->next;
                    }
                }
            }

        }else{
            node * currentNode = list-> head;
                while(currentNode->next != NULL){
                    if(currentNode->data == data){
                        found = true;
                        break;
                    }
                    else{
                        index++;
                        currentNode = currentNode->next;
                    }
                }
        }
        if(!found){
            index = -1;
        }
        return(index);


    }
} 

int listCmp(list*list1 , list* list2){
    bool same = true;
    node* lst1Node = list1->head;
    node* lst2Node = list2->head;
    while(lst1Node !=NULL && lst2Node!= NULL){
        if(lst1Node->data != lst2Node->data){
            same = false;
            break;
        }else{
            lst1Node= lst1Node->next;
            lst2Node= lst2Node->next;
        }
    }
    return(same);
}

void listSort(list *list){
    if(!list->sorted){
        node* currentNode = list->head;
        node * next;
        node * cn2 = currentNode;
        int data;
        while(currentNode !=NULL){
            while(cn2!=NULL){
                if(currentNode->data< cn2->data){
                    data = currentNode->data;
                    currentNode->data = cn2->data;
                    cn2->data = data;


                }
                cn2 = cn2->next;

            }
            currentNode = currentNode->next;
            cn2=list->head;
        }
        list->sorted = true;
    
    }
}
int main(){
    list *testList = newList("Test List");
    

    addNode(testList,3);
    addNode(testList,4);
    addNode(testList,1);
    printList(testList);
    listSort(testList);

    printList(testList);
    printf("Sorted %d\n",testList->sorted);
    addNode(testList,6);

    printf("Index %d \n",listDataSrch(testList,5));

    return(0);
}