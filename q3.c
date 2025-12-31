#include<stdio.h>
#include<stdlib.h>

struct linkedlist{
    int data;
    struct linkedlist *next;
};

//adds the elment to the last of the list
void add(struct linkedlist *s,int val){
    
    struct linkedlist *a = (struct linkedlist *)malloc(sizeof(struct linkedlist));


    while(s->next!= NULL ){
        s =s->next;
    }
    
    a->data=val;
    s->next = a;
    a->next = NULL;

}
//adds element in front to intialize it when the list is empty(works only when list is empty)
void insert_front_empty(struct linkedlist *s,int val){
    s->data = val;
    s->next =NULL;
} 

//displays all the data in the list from last to first in reverse order.
void display_reverse(struct linkedlist *s){
    
    if(s==NULL){
        return;
    }
    display_reverse(s->next);
    printf("%d \n", s->data);
    
}

int main(){
    //allocate memory dynamically for the starting of the list 
    struct linkedlist *head = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    
    //intialize the list
    insert_front_empty(head,10);

    //add data to the list
    add(head,5);
    add(head,8);

    //display data in reverse order , uses recursion
    display_reverse(head);

    return 0;
}