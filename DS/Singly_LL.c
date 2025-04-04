#include <stdio.h>
#include <stdlib.h>

//Step 1: Define a Node structure.
typedef struct node{
    int data;
    struct node* next;
}Node;


//Step 2: Create a Function to Add Nodes at the End.
void insert_last(Node **head_ref,int new_data){
    // Allocate memory for the new node
    Node *new_node =(Node*)malloc(sizeof(Node));
    Node *last_node = *head_ref;
    
    // Assign data to the new node and set its next pointer to NULL
    new_node->data=new_data;
    new_node->next=NULL;

    // If the linked list is empty, make the new node the head
    if(*head_ref == NULL){
        printf("IF : inserted %d\n",new_data);
        *head_ref=new_node;
        return;
    }else{
    // Otherwise, traverse to the last node
    while (last_node->next != NULL)
    {
        last_node = (Node*)last_node->next;
    }
    printf("ELSE : inserted %d\n",new_data);
    last_node->next=new_node;
    return;
    }
}

//Insert at the first of LL.
void insert_first(Node **head_ref, int new_data){
    Node *new_node = (Node *)malloc(sizeof(Node));
    Node *head_node = *head_ref;

    new_node->data=new_data;
    new_node->next=NULL;

    if(*head_ref == NULL){
        *head_ref=new_node;
    }else{
        // Any one would be correct, both pointing to the same mem location.
        new_node->next=head_node;
        // (*head_ref)->next=head_node;
        *head_ref=new_node;
    }
}

//Count the nodes in LL.
int node_count(Node* head_ref){
    int len=0;
    while(head_ref){
        len++;
        head_ref=head_ref->next;
    }
    printf("%s : Node count is : %d\n",__func__,len);
    return len;
}

//Insert data at the provided position.
void insert_at_pos(Node **head_ref,int new_data,int pos){
    Node *new_node=(Node*)malloc(sizeof(Node));
    Node *pos_node=*head_ref;
    int len = node_count(*head_ref);
    printf("Length of the list : %d\n",len);

    new_node->data=new_data;
    new_node->next=NULL;

    if(*head_ref==NULL){
        printf("List is empty and desired position is not available\n");
        return;
    }else if(pos == 1)
    {
        insert_first(head_ref,new_data);

    }else if (pos == len+1)
    {
        insert_last(head_ref,new_data);

    }else
    {
        printf("about to enter a new node at %d\n",pos);
        int count=1;
        while(count<pos){
            count++;
            pos_node=pos_node->next;
        }
        printf("found desired position %d\n",count);

        new_node->next=pos_node->next;
        pos_node->next=new_node;
    }
}

//Delete First node in the LL.
void delete_first_node(Node **head_ref){
    Node *del_node=*head_ref;

    if(*head_ref == NULL){
        printf("list is empty!\n");
    }else if((*head_ref)->next == NULL){
        free(*head_ref);
        *head_ref=NULL;
    }else{
        *head_ref=del_node->next;
        free(del_node);
    }
}

//delete last node in the LL.
void delete_last_node(Node **head_ref){
    Node *del_node=*head_ref;

    if(*head_ref == NULL){
        printf("List is empty\n");
    }else if((*head_ref)->next==NULL){
        free(*head_ref);
        *head_ref=NULL;
    }else{
        while(del_node->next->next != NULL){
            del_node=del_node->next;
        }

        free(del_node->next);
        del_node->next=NULL;
    }
}

// Function to print the linked list
void printlist(Node *node){
    while(node != NULL){
        printf("In while\n");
        printf("%d\n",node->data);
        node=node->next;
    }
    printf("\n");
}

int main(){

    Node *head=NULL;

    // insert_last(&head,1);
    // insert_last(&head,2);
    // insert_last(&head,3);
    // insert_last(&head,4);
    // insert_last(&head,5);

    insert_first(&head,1);
    insert_first(&head,2);
    insert_first(&head,3);
    insert_first(&head,4);
    insert_first(&head,5);

    printlist(head);
    node_count(head);
    insert_at_pos(&head,6,1);
    printlist(head);
    delete_first_node(&head);
    printlist(head);
    delete_last_node(&head);
    printlist(head);
    return 0;
}