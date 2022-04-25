#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct node{
    int value;
    struct node *next;
} NODE, *pNODE;

typedef struct stack{
    pNODE top;
    int len;
} STACK, *pSTACK;

pSTACK CreateStack();
int isEmpty(pSTACK pS);
void randfill(STACK *original);
void show(pSTACK pS);
int push(STACK *original, int c);
int isEmpty(STACK *original);
int pop(STACK *original);
void separation(STACK *original, STACK *undernull, STACK *abovenull);
void EvenDelete(STACK *original, STACK *temp);
void SwapNumbers(STACK *original, STACK *temp);
void DeleteES(STACK *original, STACK *temp);

int main()
{
    STACK *original = CreateStack();
    STACK *undernull = CreateStack();
    STACK *abovenull = CreateStack();
    STACK *temp = CreateStack();
    randfill(original);
    printf("Before changes: ");
    show(original);
    printf("\nAfter changes: ");
    /* Task 1
    printf("\nAfter changes: ");
    separation(original, undernull, abovenull);
    printf("\nUnder null stack: ");
    show(undernull);
    printf("\nAbove null stack: ");
    show(abovenull);
    */
    /* Task 2
    EvenDelete(original, temp);
    show(temp);
    */
    //Task 3
//    SwapNumbers(original, temp);
//    show(original);

    /* Task 4 */
    DeleteES(original, temp);
    show(temp);
}

pSTACK CreateStack()
{
    pSTACK pS;
    pS = (pSTACK)malloc(sizeof(STACK));
    pS->top = NULL;
    pS->len = 0;
    return pS;
}

void DeleteES(STACK *original, STACK *temp)
{
    while(!isEmpty(original))
    {
        for (int i = 1; i <= N; i++)
        {
            if (i%2 != 0)
            {
                push(temp, original->top->value);
            }
            pop(original);
        }
    }
}

void EvenDelete(STACK *original, STACK *temp)
{
    while(!isEmpty(original))
    {
        if (!(original->top->value %2 == 0))
            push(temp, original->top->value);
        pop(original);
    }
}

/*
void SwapNumbers(STACK *original)
{
    NODE *p = original->top;
    int t;
    while(p->next != 0)
    {
        p = p->next;
    }
    t = p->value;
    p->value = original->top->value;
    original->top->value = t;
}
*/

void SwapNumbers(STACK *original, STACK *temp)
{
    int t = original->top->value;
    while(!isEmpty(original))
    {
        push(temp, original->top->value);
        pop(original);
    }
    push(original, t);
    t = temp->top->value;
    pop(temp);
    while(!isEmpty(temp))
    {
        if(temp->top->value)
        push(original, temp->top->value);
        pop(temp);
    }
    pop(original);
    push(original, t);
}

void separation(STACK *original, STACK *undernull, STACK *abovenull)
{
    while(!isEmpty(original))
    {
        if (original->top->value < 0)
            push(undernull, original->top->value);
        else
            push(abovenull, original->top->value);
        pop(original);
    }
}

void randfill(STACK *original)
{
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        push(original, rand()%71 - 50);
}

void show(STACK *original)
{
    pNODE p=original->top;
    if(isEmpty(original))
        puts("Stack is empty");
    else
    {
        while(p)
        {
            printf("%d ", p->value);
            p=p->next;
        }
    }
}

int push(STACK *original, int c)
{
    pNODE p = (pNODE) malloc(sizeof(NODE));
    if (p)
    {
        p->value = c;
        p->next=original->top;
        original->top=p;
        original->len++;
        return 1;
    }
    return 0;
}

int isEmpty(STACK *original)
{
    if(original->top&&original->len)
        return 0;
    return 1;
}

int pop(STACK *original)
{
    pNODE p = original ->top;
    int c = p->value;
    original->top=p->next;
    free(p);
    original->len--;
    return c;
}
