#include <stdio.h>
#include <stdlib.h>

typedef struct _CircleLinkNode{
	struct _CircleLinkNode* next;
}CircleLinkNode;

typedef struct _CircleLinkList{
	CircleLinkNode header;
	int length;
}CircleLinkList;

typedef void(*PRINTLINKNODE)(CircleLinkNode*);

CircleLinkList* Insert_CircleLinkList();

