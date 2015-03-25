#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include "stack.h"
void instructions();

int main(void){
	instructions();
	char choice[5];
	printf("? ");
	fgets(choice,5,stdin);
	
	while (choice[0] !='4'){
		if(strlen(choice)>2){
			printf("Invalid choice.\n\n");
			instructions();
		} 
		else if(choice[0] =='1'){
			mainStack();
		}
		else if(choice[0] =='2'){
			mainQueue();
		}
		else if(choice[0] =='3'){
			mainTree();		
		}
		else{
			printf("Choice: %s\n", choice);
			printf("Invalid choice.\n\n");
			instructions();
		}
		
		instructions();
		printf("? ");
		fgets(choice,5,stdin);
	}
	printf("Program ended.\n");
	return 0;
}

void instructions(){
	printf("[Main Menu]Select one of the following options:\n"
			"	1: Stack operations\n"
			"	2: Queue operations\n"
			"	3: Tree Operations\n"
			"	4: Exit\n");
}
