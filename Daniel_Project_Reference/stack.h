#include"issue.h"
#include<stdlib.h>

typedef struct stack_node_def{
	Issue* issue;
	struct stack_node_def* next;
}StackNode;

typedef StackNode* StackNodePtr;

StackNodePtr stackTop=NULL;

void mainStack(void);
Issue* getIssueDetails();
void push(Issue*);
Issue* pop();
void printAll();
void stackInstructions();
int issueExists(int);
