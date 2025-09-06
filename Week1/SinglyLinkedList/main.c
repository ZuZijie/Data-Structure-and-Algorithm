#include <stdio.h>
#include <stdlib.h>
#include "SinglyLinkedList.c"

#define DataType int
int main(){
    int J;
    int input;
    scanf("%d",&J);
    Node* head = NULL; 
    
    for(int j=0;j<J;j++){  
        scanf("%d",&input);
        if(input==1)CreateEmptyList(&head);
        if(input==2){
            CreateList(NULL,10,&head);
        }
        if(input==3){
            DataType InsertData;
            int InsertPosi;
            scanf("%d %d",&InsertPosi,&InsertData);
            ListInsert(head,InsertPosi,InsertData);
        }
        if(input==4){
            int DeletePosi;
            scanf("%d",&DeletePosi);
            DataType DeleteData;
            ListDelete(head,DeletePosi,&DeleteData);
                printf("%d",DeleteData);
        }
        if(input==5){
            DestroyList(head);
            head = NULL;
        } 
        if(input==6){
            PrintList(head);
        }
    }

    if (head != NULL) {
        DestroyList(head);
    }
}