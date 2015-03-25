
#include"issue.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void printIssue(Issue* issue){
	printf("[%d][%s] %s : Reported by %s\n", issue->issueId, issue->severity, issue->summary, issue->reporter);
}

Issue* getIssueDetails(){
	printf("Enter the id of the issue: ");
	char input[50];
	fgets(input,50,stdin);
	int issueId;
	issueId=atoi(input);
	
	printf("Enter the summary of the issue: ");
	char summary[100];
	fgets(summary,100,stdin);
	//remove newline character at the end
	if(summary[strlen(summary)-1] == '\n'){
		summary[strlen(summary)-1] ='\0';
	}
	
	printf("How severe is the issue? [1=Trivial, 2=Normal, 3=Critical]:");
	fgets(input,50,stdin);
	while((input[0]!='1' && input[0]!='2' && input[0]!='3') || strlen(input)>2 ){
		printf("Invalid selection\n");
		printf("How severe is the issue? [1=Trivial, 2=Normal, 3=Critical]:");
		fgets(input,50,stdin);
	}
	Severity severity;
	if(input[0] =='3'){
		severity=Critical;
	} 
	else if(input[0] =='2'){
		severity=Normal;
	} 
	else{
		severity=Trivial;
	}
			
	printf("Who reported the issue?: ");
	char reporter[30];
	fgets(reporter,30,stdin);
	//remove newline character at the end
	if(reporter[strlen(reporter)-1] == '\n'){
		reporter[strlen(reporter)-1] ='\0';
	}

	Issue* issue = malloc(sizeof(Issue));
	issue->issueId = issueId;
	issue->summary=copyString(summary);
	issue->severity = severity;
	issue->reporter= copyString(reporter);
	return issue;
}


char* copyString(char* string){
	char* temp = malloc(strlen(string)+1);
	if(temp){
		strcpy(temp, string);
	}
	return temp;
}