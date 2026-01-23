#include <stdio.h>
#include <stdlib.h>

struct linkedlist {
    int data;
    struct linkedlist *next;
    struct linkedlist *prev;
};

//insert element after a give target value in the list
void insert_after(struct linkedlist *s, int target, int val) {

    while (s != NULL && s->data != target) {
        s = s->next;
    }
    
    //if target node is not found in the list 
    if(s==NULL){
        printf("target node not found \n");
        return;
    }
    struct linkedlist *n =(struct linkedlist *)malloc(sizeof(struct linkedlist));

    n->data = val;
    n->next = s->next;
    n->prev = s;

    s->next = n;
}

//deletes the node by finding the target value in the list
void delete_node(struct linkedlist *s, int val) {

    while (s != NULL && s->data != val) {
        s = s->next;
    }

    //if target node is not found in the list
    if(s==NULL){
        printf("target node not found \n");
        return;
    }
    
    s->prev->next = s->next;
    s->next->prev = s->prev;

    free(s);
}

//display all elements in the list 
void display(struct linkedlist *s) {
    while (s != NULL) {
        printf("%d ", s->data);
        s = s->next;
    }
    printf("\n");
}

int main() {

    struct linkedlist *head =(struct linkedlist *)malloc(sizeof(struct linkedlist));

    //intializing head node with value 10 and next and prev null
    head->data = 10;
    head->next = NULL;
    head->prev = NULL;

    insert_after(head, 10, 20);
    insert_after(head, 20, 30);

    printf("After insertion:\n");
    display(head);

    delete_node(head, 20);

    printf("After deletion:\n");
    display(head);

    return 0;
}
