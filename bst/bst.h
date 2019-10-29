#ifndef _BST_H_
#define _BST_H_

typedef int Data;

typedef struct _bstnode {
	Data data;
	struct _bstnode* leftChild;
	struct _bstnode* rightChild;
}BstNode;

extern BstNode* BST_root;
BstNode* createNode(Data data);
BstNode* insertBST(BstNode* root, Data data);
BstNode* findMin(BstNode* root);
BstNode* findMax(BstNode* root);
BstNode* deleteBST(BstNode* root, Data data);
void inorderPrint(BstNode* root);
#endif