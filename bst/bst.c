#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

BstNode* BST_root;
BstNode* createNode(Data data) {
	BstNode* newNode = (BstNode*)calloc(1, sizeof(BstNode));
	newNode->data = data;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;

	return newNode;
}

BstNode* insertBST(BstNode* root, Data data) {
	if (root == NULL) {
		return createNode(data);
	}

	if (root->data < data) {
		root->rightChild = insertBST(root->rightChild, data);
	}
	else if (root->data > data) {
		root->leftChild = insertBST(root->leftChild, data);
	}
	else {
		fprintf(stderr, "BST���� �ߺ��� ���� ���Ե� �� �����ϴ�.");
	}
	return root;
}
BstNode* findMin(BstNode* root) {
	if (root->leftChild == NULL) {
		return root;
	}
	findMin(root->leftChild);
}
BstNode* findMax(BstNode* root) {
	if (root->rightChild == NULL) {
		return root;
	}
	findMax(root->rightChild);
}

BstNode* deleteBST(BstNode* root, Data data) {
	//root�� ��Ʈ�μ� ���� Ʈ������ data�� ���� ��带 ����� root �ٽ� ����

	BstNode* temp;
	// ã�� ���� ���� �� return NULL
	if (root == NULL) {
		return NULL;
	}

	// Left subBST recursion
	else if (root->data < data) {
		root->rightChild = deleteBST(root->rightChild, data);
	}
	// Right subBST recursion
	else if (root->data > data) {
		root->leftChild = deleteBST(root->leftChild, data);
	}
	// ������ ��� ã��
	else {
		//1. ã�� ������ ��尡 leaf ����� ���
		if (root->leftChild == NULL && root->rightChild == NULL) {
			{
				free(root);
				return NULL;
			}
		}

		// 2. ã�� ������ ����� �ڽĳ�尡 1�� �϶�
		else if (root->leftChild == NULL || root->rightChild == NULL) {
			if (root->rightChild == NULL) {
				temp = root->leftChild;
			}
			else {
				temp = root->rightChild;
			}
			free(root);
			return temp;
		}

		// 3. ã�� ������ ����� �ڽĳ�尡 2���϶�
		else {
			temp = findMin(root->rightChild);
			root->data = temp->data;
			root->rightChild = deleteBST(root->rightChild, temp->data);
		}
	}
	return root;
}

void inorderPrint(BstNode* root) {
	if (root != NULL) {
		inorderPrint(root->leftChild);
		printf("%d ", root->data);
		inorderPrint(root->rightChild);
	}
}

