#ifndef _Stack_h
#define ElementType int

struct Node;
typedef struct Node PtrToNode;
typedef PtrToNode Stack;


int IsEmpty(Stack S);
Stack CreatStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X,Stack S);
ElementType Top(Stack S);
viod Pop(Stack S);

#endif
