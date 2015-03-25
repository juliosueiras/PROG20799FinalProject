#include"queue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void mainQueue(void){
	queueInstructions();
	char choice[3];
	printf("? ");
	fgets(choice,5,stdin);
	
	while (choice[0] !='6'){
		if(strlen(choice)>2){
			printf("Invalid choice.\n\n");
			queueInstructions();
		} 
		else if(choice[0] =='1'){
			if(queueHead==NULL){
				printf("The queue is empty\n");
			}else{
				printf("The issue at the front of the queue\n");
				printIssue(queueHead->issue);
				printf("\n");
			}
		}
		else if(choice[0] =='2'){
			if(queueHead==NULL){
				printf("The queue is empty\n");
			}else{
				printf("The issue at the end of the queue\n");
				printIssue(queueTail->issue);
				printf("\n");
			}
		}
		else if(choice[0] =='3'){
			//push
			Issue* issue = getIssueDetails();
			if(queueIssueExists(issue->issueId)){
				printf("This issue has already been added to the queue");
			}
			else{
				enqueue(issue);
			}
		}
		else if(choice[0] =='4'){

			Issue* issue =dequeue();
			
			if(issue==NULL){
				printf("The queue is empty\n");
			}
			else{
				printIssue(issue);
			}
			free(issue);			
		}
		else if(choice[0] =='5'){
			printQueue();
		}
		else{
			printf("Choice: %s\n", choice);
			printf("Invalid choice.\n\n");
			queueInstructions();
		}
		
		queueInstructions();
		printf("? ");
		fgets(choice,3,stdin);
	}
	printf("Returning to main menu...\n");
}

void queueInstructions(){
	printf("[Stack]Select one of the following options:\n"
			"	1: Front of Queue\n"
			"	2: Back of Queue\n"
			"	3: Enqueue\n"
			"	4: Dequeue\n"
			"	5: Print all the queue items\n"
			"	6: Return to main menu\n");
}

void enqueue(Issue* issue){
	QueueNode* node = malloc(sizeof(QueueNode));
	node->issue=issue;
	if(queueTail!=NULL){
		queueTail->next= node;
	}
	queueTail=node;
	if(queueHead == NULL){
		queueHead=node;
	}
	
	printf("\nIssue has been successfully added\n ");
	printIssue(issue);
	printf("\n");

}

Issue* dequeue(){
	if(queueHead==NULL){
		return NULL;
	}
	QueueNode* node = queueHead;
	Issue* issue = queueHead->issue;
	queueHead=node->next;
	if(node == queueTail){
		queueTail = NULL;
	}
	free(node);
	return issue;
}

void printQueue(){
	if(queueHead== NULL){
		printf("\nThe queue is empty\n");
	}
	QueueNode* node = queueHead;
	while(node!=NULL){
		printIssue(node->issue);
		node=node->next;
	}
}

int queueIssueExists(int id){
	return 0;
}

