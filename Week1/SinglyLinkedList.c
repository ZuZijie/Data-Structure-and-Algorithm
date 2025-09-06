#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define true 1
#define false 0


/*
Args:
* head:pointer of the head node.
Return:
* True or false.
Description:
* Create an empty linked list with a head node.
* The "next" field of the head node should point to NULL.
*/

typedef struct DataType
{
    int data;
}DataType;
//Define DataType

typedef struct Node
{
    struct Node* next;
    DataType data;
}Node;
//Define Node

void PrintList(Node* head)
{
        Node *p = head->next;
        if (p == NULL) {
                printf("Empty List");
        }
        while (p != NULL) {
                printf("%d ", p->data);
                p = p->next;
        }
        printf("\n");
}
_Bool CreateEmptyList(Node** head)
{
    *head = (Node*)malloc(sizeof(Node));
    (*head)->next = NULL;
    return true;
}


/*
Args:
* addr: pointer of an array.
* n: length of the array.
* head:pointer of the head node.
Return:
* True or false.
Description:
* Initialize a linked list with an arr@ay.
*/
_Bool CreateList(DataType *addr, unsigned int n, Node** head)
{
    Node* CurrentNode = *head;
    for(unsigned int i=0; i<n; i++){
        Node* newNode = malloc(sizeof(Node));

        
        newNode->next = NULL;
        if (addr != NULL) {
            newNode->data = addr[i];
        } else {
            newNode->data.data=i; 
        }
        
        CurrentNode->next=newNode;
        CurrentNode=newNode;
    }
	return true;
}


/*
Args:
* head: pointer of the head node.
Returns:
* True or false.
Description:
* Destroy the linked list.
* Release all allocated memory.
*/
_Bool DestroyList(Node *head)
{
    if (head == NULL) return true;
    
    Node* CurrentNode = head;
    Node* NextNode;
    
    while (CurrentNode != NULL)
    {
        NextNode = CurrentNode->next;
        free(CurrentNode);
        CurrentNode = NextNode;
    }
	return true;
}


/*
Args:
* head: pointer of the head node.
* index: index of the inserted data.
* data: the inserted data.
*/
_Bool ListInsert(Node *head, unsigned int index, DataType e)
{   
    if (head == NULL || index < 1) return false;
    
    Node* InsertPoint = head;
    
    for(unsigned int i = 0; i < index; i++){

        InsertPoint = InsertPoint->next;
    }
    
    Node* NewPoint = malloc(sizeof(Node));
    if (NewPoint == NULL) return false;
    
    NewPoint->next = InsertPoint->next;
    InsertPoint->next = NewPoint;
    NewPoint->data = e;
	return true;
}


/*
Args:
* head: pointer of the head node.
* index: index of the deleted data.
* e:The deleted data.
Returns:
Description:
*   If the linked list is "head->3->5->2",
* when you call (head, 2), the linked
* list will be "head->3->5".
*/
_Bool ListDelete(Node *head, unsigned int index, DataType* e)
{
    if (head == NULL) return false;
    
    Node* NodeBeforeDeletePoint = head;
    
    for(unsigned int i = 0; i < index; i++){
        NodeBeforeDeletePoint = NodeBeforeDeletePoint->next;
    }
    
    
    Node* NodeToDelete = NodeBeforeDeletePoint->next;
    *e = NodeToDelete->data;
    NodeBeforeDeletePoint->next = NodeToDelete->next;
    free(NodeToDelete);
    
	return true;
}
// int main(){
//     int J;
//     int input;
//     scanf("%d",&J);
//     Node* head = NULL; 
    
//     for(int j=0;j<J;j++){  
//         scanf("%d",&input);
//         if(input==1)CreateEmptyList(&head);
//         if(input==2){
//             CreateList(NULL,10,&head);
//         }
//         if(input==3){
//             DataType InsertData;
//             int InsertPosi;
//             scanf("%d %d",&InsertPosi,&InsertData.data);
//             ListInsert(head,InsertPosi,InsertData);
//         }
//         if(input==4){
//             int DeletePosi;
//             scanf("%d",&DeletePosi);
//             DataType DeleteData;
//             ListDelete(head,DeletePosi,&DeleteData);
//                 printf("%d",DeleteData.data);
//         }
//         if(input==5){
//             DestroyList(head);
//             head = NULL;
//         } 
//         if(input==6){
//             PrintList(head);
//         }
//     }

//     if (head != NULL) {
//         DestroyList(head);
//     }
// }