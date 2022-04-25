#include <stdio.h>
#include <stdlib.h>

//Creating stack

typedef struct node{
    char value; //значение эл-та стека
    struct node *next; //указатель на след. узел
} NODE, *pNODE;

typedef struct stack{ //создание структуры стек
    pNODE top;
    int len;
} STACK, *pSTACK;

pSTACK CreateStack();
int isEmpty(pSTACK pS);
char pop(pSTACK pS);
void show(pSTACK pS);
void ClearStack(pSTACK pS);
int push(pSTACK pS, char c);

int main()
{
    pSTACK ps = CreateStack();
    char c;
    for (c='a'; c <= 'z'; c++)
        push(ps, c);
    while(!isEmpty(ps))
    {
        show(ps);
        pop(ps);
        printf("\n");
    }
    show(ps);
    getch();
    return 0;
}

//Function of creating new stack

pSTACK CreateStack()
{
    pSTACK pS;
    pS = (pSTACK)malloc(sizeof(STACK));
    pS->top = NULL;
    pS->len = 0;
    return pS;
}

//Function of checking fullness stack

int isEmpty(pSTACK pS)
{
    if(pS->top&&pS->len)
        return 0;
    return 1;
}

//Function of extracting element from stack

char pop(pSTACK pS)
{
    pNODE p = pS->top;
    int c = p->value;
    pS->top=p->next;
    free(p);
    pS->len--;
    return c;
}

//Function of printing stack on screen

void show(pSTACK pS)
{
    pNODE p=pS->top;
    if(isEmpty(pS))
        puts("Stack is empty");
    else
    {
        while(p)
        {
            printf("%c ", p->value);
            p=p->next;
        }
    }
}


//Function of clearing stack

void ClearStack(pSTACK pS)
{
    pNODE p = pS->top;
    while(!isEmpty(pS))
    {
        pop(pS);
    }
}

int push(pSTACK pS, char c)
{
    pNODE p = (pNODE) malloc(sizeof(NODE));
    if (p)
    {
        p->value = c;
        p->next=pS->top;
        pS->top=p;
        pS->len++;
        return 1;
    }
    return 0;
}
