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
		fprintf(stderr, "BST에는 중복된 값이 삽입될 수 없습니다.");
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
	//root가 루트로서 속한 트리에서 data를 가진 노드를 지우고 root 다시 리턴

	BstNode* temp;
	// 찾는 값이 없을 시 return NULL
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
	// 삭제할 노드 찾음
	else {
		//1. 찾은 삭제할 노드가 leaf 노드인 경우
		if (root->leftChild == NULL && root->rightChild == NULL) {
			{
				free(root);
				return NULL;
			}
		}

		// 2. 찾은 삭제할 노드의 자식노드가 1개 일때
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

		// 3. 찾은 삭제할 노드의 자식노드가 2개일때
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

