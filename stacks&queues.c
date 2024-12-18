#include <stdio.h>
#include <stdlib.h>
 
///declaration of TypeElement
typedef int TypeElm;
//typedef char TypeElm;
 
///declaration of a Stack
typedef struct Estack* Stack;
typedef struct Estack { TypeElm Data; Stack Next;} SNode;
 
///declaration of a Queue
typedef struct Element* EQueue;
typedef struct Element { TypeElm Data; EQueue Next;} QNode;
typedef struct {EQueue Head,Tail;} Queue;
 
///Stacks operations
///procedure InitStack
void InitStack(Stack *P)
{*P=NULL;}
 
///procedure Push
void Push(Stack *S, TypeElm x)
{Stack V;
V=malloc(sizeof(SNode));
V->Data=x;
V->Next=*S;
*S=V;
}
 
///procedure Pop
void Pop(Stack *S, TypeElm *x)
{Stack V;
*x=(*S)->Data;
V=*S;
*S=(*S)->Next;
free(V);
}
 
///Function isSEmpty
int isSEmpty(Stack S)
{if (S==NULL) return 1;
else return 0;
}
 
///Function Top
int Top(Stack S)
{return S->Data;}
 
 
///Queues operations
///procedure InitQueue
void InitQueue(Queue *Q)
{(*Q).Head=NULL; (*Q).Tail=NULL;}
 
///procedure Enqueue
void Enqueue(Queue *Q, int x)
{EQueue V;
V=malloc(sizeof(QNode));
V->Data=x;
V->Next=NULL;
if ((*Q).Head==NULL) (*Q).Head=V; //the Queue is empty
else (*Q).Tail->Next=V;
(*Q).Tail=V;
}
 
///procedure Dequeue
void Dequeue(Queue *Q, TypeElm *x)
{EQueue V;
V=(*Q).Head;
*x=V->Data; //ou *x=(*Q).Head->Data;
 
if ((*Q).Head==(*Q).Tail) {(*Q).Head=NULL; (*Q).Tail=NULL;}
else (*Q).Head=(*Q).Head->Next; // ou (*Q).Head=V->Next;
free(V);
}
 
///Function isQEmpty
int isQEmpty(Queue Q)
{if (Q.Head==NULL) return 1;
else return 0;
}
 
///Function Head
TypeElm Head(Queue Q)
{return Q.Head->Data;}
 
 
///function Display
void Display (Queue q){
Queue r;
int x;
InitQueue(&r);
while(!isQEmpty(q)){
Dequeue(&q,&x);
printf("%d ",x);
Enqueue(&r,x);
}
q=r;
}
///function reverseLK
void reverseLK(Queue *q,int k){
Queue r;
Stack s,s1;
int x;
InitStack(&s); InitQueue(&r); InitStack(&s1);
while(!isQEmpty(*q)){
Dequeue(q,&x); Push(&s,x);
}
while(k>0 && !isSEmpty(s)){
Pop(&s,&x); Enqueue(&r,x); k--;
}
while(!isSEmpty(s)){
Pop(&s,&x); Push(&s1,x);
}
while(!isSEmpty(s1)){
Pop(&s1,&x); Enqueue(q,x);
}
while(!isQEmpty(r)){
Dequeue(&r,&x); Enqueue(q,x);
}
 
int main(){
int x,i,n;
Queue q;
 
printf("input the size of Q");
scanf("%d",&n);
 
InitQueue(&q);
printf("input the elements:\n");
for(i=1;i<=n;i++){
scanf("%d",&x);
Enqueue(&q,x);
}
printf("\nour queue before reversing:\n");
Display(q);
 
printf("\ninput the number of elements u want to reverse:");
scanf("%d",&x);
 
reverseLK(&q,x);
printf("\nour queue after reversing:\n");
Display(q);
return 0;
}
 