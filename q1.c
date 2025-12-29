#include <stdio.h>
#include <stdlib.h>

struct stack {
    int top;
    char e[50];
};

//pushes parenthesis in the stack
void push(struct stack *s, char ch) {
    if (s->top == 49) {
        printf("Stack overflow \n");
        return;
    }
    s->top++;
    s->e[s->top] = ch;  
}

//removes parenthesis from the stack 
void pop(struct stack *s, char ch) {
    if (s->top == -1) {
        printf("the parenthesis is not balanced in this expression \n");

        //if the stack is empty and pop is called the expression is not balanced, exit the program
        exit(0);
    }

    char last = s->e[s->top];
    s->top--;

    // check if the last opening matches the current closing
    if ((last == '(' && ch != ')') ||
        (last == '{' && ch != '}') ||
        (last == '[' && ch != ']')) {
        printf("the parenthesis is not balanced in this expression \n");
        exit(0);
    }
}

int main() {

    //Dynamic memory allocation of stack structure q
    struct stack *q = (struct stack *)malloc(sizeof(struct stack));
    q->top = -1;

    //expression input, max length is 50
    char f[50];
    printf("Enter the expression:\n");
    scanf("%49s", f);

    int i = 0;

    //checking for parenthesis and performing operations based on that
    while (f[i] != '\0') {
        if(f[i] == '(' || f[i] == '{' || f[i] == '[') {
            push(q, f[i]);
        } 
        else if(f[i] == ')' || f[i] == '}' || f[i] == ']') {
            pop(q, f[i]);
        }
        i++;
    }

    //if stack is empty expression is balanced, checking that
    if (q->top != -1) {
        printf("The parenthesis is not balanced in this expression\n");
    } 
    else {
        printf("Parenthesis is balanced in this expression\n");
    }

    //freeing the used space
    free(q);
    
    return 0;
}
