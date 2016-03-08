#ifndef SEQQUEUE_H
#define SEQQUEUE_H

#define MAXSIZE 128

typedef struct _SeqQueue{
	void* data[MAXSIZE];
	int length;
}SeqQueue;

SeqQueue* Init_SeqQueue()
{


void Push_SeqQueue(SeqQueue* Queue,void* data);
void Pop_SeqQueue(SeqQueue* Queue);

