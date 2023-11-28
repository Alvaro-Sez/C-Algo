#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *link;
} Node;


Node* removeAt(Node *head, int index){
    Node *curr = head;
    Node *prev = NULL;
    int count = 0;
    for (int i = 0; i < index; i++)
    {
        prev = curr;
        curr = curr->link;
    }
    if(prev == NULL){
        head = curr->link;
    }else{
        prev->link = curr->link;
    }
    free(curr);
    curr = NULL;

    return head;
}

void add(Node *head, int value){
    Node *current = NULL;
    current = head;

    while(current->link){
        current = current->link;
    }
    current->value = value;
    current->link = (Node*)malloc(sizeof(Node));
    (current->link)->link = NULL;
}

Node* createLinkedList(){
    Node *head = (Node*)malloc(sizeof(Node));
    (*head).link = NULL;
    return head;
}

void printLinkedList(Node *head){
    while (head->link) {
        printf("%d ", head->value);
        head = head->link;
    }
    printf("\n");
}

void freeList(Node* head)
{
   Node* tmp;
   while (head != NULL)
    {
       tmp = head;
       head = head->link;
       free(tmp);
    }

}

int main(){
    Node *list = createLinkedList();
    add(list, 4);
    add(list, 1);
    add(list, 7);
    add(list, 12);
    add(list, 2);
    add(list, 81);
    add(list, 44);
    add(list, 72);
    list = removeAt(list, 0);
    printLinkedList(list);
    freeList(list);
}