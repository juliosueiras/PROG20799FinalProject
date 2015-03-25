#include"stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void mainStack(void){
	stackInstructions();
	char choice[3];
	printf("? ");
	fgets(choice,5,stdin);
	
	while (choice[0] !='5'){
		if(strlen(choice)>2){
			printf("Invalid choice.\n\n");
			stackInstructions();
		} 
		else if(choice[0] =='1'){
			if(stackTop==NULL){
				printf("The stack is empty\n");
			}else{
				printf("\nThe most recent issue\n");
				printIssue(stackTop->issue);
				printf("\n");
			}
		}
		else if(choice[0] =='2'){
			//push
			Issue* issue = getIssueDetails();
			if(issueExists(issue->issueId)){
				printf("This issue has already been added to the stack\n");
			}
			else{
				push(issue);
			}
		}
		else if(choice[0] =='3'){

			Issue* issue =pop();
			
			if(issue==NULL){
				printf("The stack is empty\n");
			}
			else{
				printIssue(issue);
			}
			free(issue);			
		}
		else if(choice[0] =='4'){
			printAll();
		}
		else{
			printf("Choice: %s\n", choice);
			printf("Invalid choice.\n\n");
			stackInstructions();
		}
		
		stackInstructions();
		printf("? ");
		fgets(choice,3,stdin);
	}
	printf("Returning to main menu...\n");
}

void push(Issue* issue){
	StackNode* node = malloc(sizeof(StackNode));	
	node->issue=issue;
	node->next= stackTop;
	stackTop=node;
	
	printf("\nIssue has been successfully added\n ");
	printIssue(issue);
	printf("\n");

}

Issue* pop(){
	if(stackTop==NULL){
		return NULL;
	}
	StackNode* node= stackTop;		
	stackTop=node->next;
	node->next=NULL;
	Issue* issue= node->issue;
	free(node);	
	return issue;
}

void printAll(){
	StackNode* node = stackTop;
	while(node!=NULL){
		printIssue(node->issue);
		node=node->next;
	}
}

void stackInstructions(){
	printf("[Stack]Select one of the following options:\n"
			"	1: Display the latest issue\n"
			"	2: Add a new issue\n"
			"	3: Remove the latest issue\n"
			"	4: Print all issues\n"
			"	5: Return to main menu\n");
}

int issueExists(int issueId){
	StackNode *node = stackTop;
	while(node!=NULL){
		if(node->issue->issueId == issueId){
			return 1;
		}
		node=node->next;
	}
	return 0;
}

