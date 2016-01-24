#ifndef _Hashsep_H
#define ElementType int

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key,HashTable H);
void Insert(ElementType Key,HashTable H);
ElementType Retrieve(Position P);

typedef unsigned int Index;

Index Hash(const char *Key,int TableSize);

#endif
