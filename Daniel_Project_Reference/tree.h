#include"issue.h"
#include<stdlib.h>

typedef struct tree_node_def
{
Issue* issue;
struct tree_node_def* left;
   struct tree_node_def* right;
}TreeNode;

typedef TreeNode* TreeNodePtr;

TreeNodePtr root = NULL;

void mainTree(void);
void insertNode(TreeNodePtr*, Issue*);
void preOrder(TreeNodePtr);
void postOrder(TreeNodePtr);
void inOrder(TreeNodePtr);
int searchIssue(int, TreeNodePtr*, TreeNodePtr*);
int deleteIssue(int);
void treeInstructions();
