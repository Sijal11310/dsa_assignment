#include <stdio.h>
#include <stdlib.h>

struct stack {
    int top;
    char e[50];
};

//pushes operator in stack 
void push(struct stack *s, char a) {
    if (s->top == 49) {
        printf("Stack overflow \n");
        return;
    }
    s->top++;
    s->e[s->top] = a;
}

//pop the operator from the stack and returning the character
char pop(struct stack *s) {
    if (s->top == -1) {
        return '\0';
    }
    return s->e[s->top--];
}

//checks the precedence of the operator
int precedence(char e) {
    if (e == '^')
        return 3;
    else if (e == '*' || e == '/')
        return 2;
    else if (e == '+' || e== '-')
        return 1;
    else
        return 0;
}

//checks if the character is a operator or not 
bool isOperator(char c) {
    if(c == '^' || c == '/' || c == '*' || c == '+' || c == '-'){
        return true;
    }
    else{
        return false;
    }
}



int main() {
    struct stack *q = (struct stack *)malloc(sizeof(struct stack));
    q->top = -1;

    char infix[50];
    char postfix[50];
    int i = 0, k = 0;

    //taking infix as input
    printf("Enter the expression: \n");
    scanf("%49s", infix);

    
    while (infix[i] != '\0') {
        //if the expression doesn't contain a operator or parantheses add it to the postfix
        if (!isOperator(infix[i]) && infix[i] != '(' && infix[i] != ')') {
            postfix[k++] = infix[i];
        }
        //handels parantheses specially, if opening parantheses then push
        else if (infix[i] == '(') {
            push(q, infix[i]);
        }
        //if closing parantheses then pop elements till opening paranthesis appears and pop that too
        else if (infix[i] == ')') {
            while (q->top != -1 && q->e[q->top] != '(') {
                postfix[k++] = pop(q);
            }
            pop(q); 
        }
        //push operator having less precedence then the previous one and pop if not 
        else {
            while (q->top != -1 &&
                   precedence(q->e[q->top]) >= precedence(infix[i])) {
                postfix[k++] = pop(q);
            }
            push(q, infix[i]);
        }
        i++;
    }

    //removes the remaining elements from the stack
    while (q->top != -1) {
        postfix[k++] = pop(q);
    }

    //closing thag for a string
    postfix[k] = '\0';

    printf("Postfix expression %s \n", postfix);

    q->top = -1;
    i = 0;

    int ans = 0;

    while (postfix[i] != '\0') {
        
        if (!isOperator(postfix[i])) {
            push(q, postfix[i]);
        } 
        else {
            int op2 = pop(q) - '0';
            int op1 = pop(q) - '0';

            if (postfix[i] == '+'){
                ans = op1 + op2;
            }
            else if (postfix[i] == '-'){
                ans = op1 - op2;
            }
            else if (postfix[i] == '*'){
                ans = op1 * op2;
            }
            else if (postfix[i] == '/'){
                ans = op1 / op2;
            }
            else if (postfix[i] == '^') {
                ans = 1;
                for (int j = 0; j < op2; j++){
                    ans *= op1;
                }
            }

            push(q, ans + '0');
        }
        i++;
    }

    ans = pop(q) - '0';


    printf("the answer of the expression is %d \n",ans);
    
    free(q);
    return 0;
}
