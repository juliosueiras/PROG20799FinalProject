#include"issue.h"
#include<stdlib.h>

typedef struct queue_node_def{
	Issue* issue;
	struct queue_node_def *next;
}QueueNode;

typedef QueueNode *QueueNodePtr;

QueueNodePtr queueHead=NULL;
QueueNodePtr queueTail=NULL;

void mainQueue(void);
void printQueue();
Issue* dequeue();
void enqueue (Issue*);
void queueInstructions(void);
int queueIssueExists(int);
