#include "tree.h"
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

void mainTree(void)
{
   treeInstructions();
   char choice[3];
   printf("? ");
   fgets(choice,5,stdin);
   
   while(choice[0]!='6')
   {
       if(strlen( choice) > 2)
       {
           printf("Invalid choice.\n\n");
           treeInstructions();
       }
       else if(choice[0] == '1')
       {
           //insert
           insertNode(&root, getIssueDetails());
       }
       else if(choice[0] == '2')
       {
           printf("Enter the issue id you want to remove:");
           //int id;
           //scanf("%d", &id);
           char id[10];
           fgets(id,10,stdin);
           deleteIssue(atoi(id));
           //deleteIssue(id);
           //remove
       }
       else if(choice[0] == '3')
       {
           //pre-order
           if(root==NULL){
           		printf("\nThe tree is empty\n");
           }
           else{
           		preOrder(root);
           }
       }
       else if(choice[0] == '4')
       {
           //post-order
           if(root==NULL){
           		printf("\nThe tree is empty\n");
           }
           else{
           		postOrder(root);
           }
       }
       else if(choice[0] == '5')
       {
           //in-order
           if(root==NULL){
           		printf("\nThe tree is empty\n");
           }
           else{
           		inOrder(root);
           }
       }
       
       treeInstructions();
       printf("? ");
       fgets(choice,5,stdin);
   }
}

void treeInstructions()
{
   printf("[Tree]Select one of the following options:\n"
          "\t1: Insert an issue\n"
          "\t2: Delete an issue\n"
          "\t3: View the tree using preorder\n"
          "\t4: View the tree using postorder\n"
          "\t5: View the tree sorted by id (in order)\n"
          "\t6: Exit\n");
}

void insertNode( TreeNodePtr* treeNode, Issue* newIssue)
{
   if(*treeNode == NULL)
   {
       *treeNode = malloc(sizeof(TreeNode));
       
       if(*treeNode != NULL)
       {
           (*treeNode)->issue = newIssue;
           (*treeNode)->left = NULL;
           (*treeNode)->right = NULL;
       }
       else
       {
           printf("something failed");
       }
   }
   else
   {
       if(newIssue->issueId < (*treeNode)->issue->issueId)
       {
           insertNode(&((*treeNode)->left), newIssue);
       }
       else if(newIssue->issueId > (*treeNode)->issue->issueId)
       {
           insertNode(&((*treeNode)->right), newIssue);
       }
       else{
           printf("\nThis issue already exists\n");
       }
   }
}

void preOrder(TreeNodePtr treeNode)
{
    if(treeNode != NULL){
        printIssue(treeNode->issue);
        preOrder(treeNode->left);
        preOrder(treeNode->right);
    }
}

void postOrder(TreeNodePtr treeNode)
{
    if(treeNode != NULL){
        postOrder(treeNode->left);
        postOrder(treeNode->right);
        printIssue(treeNode->issue);
    }
}

void inOrder(TreeNodePtr treeNode)
{
    if(treeNode != NULL){
        inOrder(treeNode->left);
        printIssue(treeNode->issue);
        inOrder(treeNode->right);
    }
}
int searchIssue(int value, TreeNodePtr* parentNode, TreeNodePtr* temp)
{
   //look for the issue in the tree using the issue id
   TreeNodePtr tempPtr;
   tempPtr = root;
   *parentNode = NULL;

   while( tempPtr != NULL )
   {
       if( (tempPtr)->issue->issueId == value)
       {
           *temp = tempPtr;
           return 1;
       }

        *parentNode=tempPtr;

       if( tempPtr->issue->issueId > value)
           tempPtr = tempPtr->left;
       else
           tempPtr = tempPtr->right;
   }

   return 0;
}

int deleteIssue(int id)
{
   //search if the issue is in the tree
   if(root == NULL)
   {
       printf("The tree is empty\n");
       return 0;
   }

   TreeNodePtr parentPtr = NULL;
   TreeNodePtr tempNodePtr = NULL;
   TreeNodePtr replacementNodePtr;

   if(searchIssue(id, &parentPtr, &tempNodePtr))
   {

       // if the node being deleted has two children
       if(tempNodePtr->left != NULL && tempNodePtr->right != NULL)
       {
           parentPtr = tempNodePtr;
           replacementNodePtr = tempNodePtr->right;

           while( replacementNodePtr->left != NULL)
           {
               parentPtr = replacementNodePtr;
               replacementNodePtr = replacementNodePtr->left;
           }

           tempNodePtr->issue = replacementNodePtr->issue;
           tempNodePtr = replacementNodePtr;
       }

       //when the node being deleted has no children
       if(tempNodePtr->left == NULL && tempNodePtr->right == NULL)
       {

           if( root == tempNodePtr)root=NULL ;
           else if(parentPtr->right == tempNodePtr)
               parentPtr->right = NULL;
           else
               parentPtr->left = NULL;

           free(tempNodePtr);
           printf("\nIssue [%d] has successfully been deleted\n", id);
           return 1;
       }

       //when the node only has a right child
       if(tempNodePtr->left == NULL && tempNodePtr->right != NULL)
       {
           if( root == tempNodePtr) root = tempNodePtr->right;

           else if(parentPtr->left == tempNodePtr)
               parentPtr->left = tempNodePtr->right;
           else
               parentPtr->right = tempNodePtr->right;

           free(tempNodePtr);
           printf("\nIssue [%d] has successfully been deleted\n", id);
           return 1;
       }

       //when the node only has a left child
       if(tempNodePtr->left != NULL && tempNodePtr->right == NULL)
       {
           if( root == tempNodePtr) root = tempNodePtr->left;
           else if(parentPtr->left == tempNodePtr)
               parentPtr->left = tempNodePtr->left;
           else
               parentPtr->right = tempNodePtr->left;

           free(tempNodePtr);
           printf("\nIssue [%d] has successfully been deleted\n", id);
           return 1;
       }
   }
   printf("\nIssue [%d] does not exist\n", id);
}
