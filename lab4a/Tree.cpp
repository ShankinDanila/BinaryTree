#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tree.h"
#include "Dialog.h"
#include "Work.h"


void IncorderTreeWalk(Node* ptr) {
	if (ptr != NULL) {
		IncorderTreeWalk(ptr->left);
		printf("%d", ptr->key);
		Data_Print(ptr->info, ptr->len);
		IncorderTreeWalk(ptr->right);
	}
}

Node* TreeSearch(Node* MyNode, int KeyToSearch) {
	while ((MyNode != NULL) && (KeyToSearch != MyNode->key)) {
		if (KeyToSearch < MyNode->key) {
			MyNode = MyNode->left;
		}
		else {
			MyNode = MyNode->right;
		}
	}
	return MyNode;
}

Node* TreeMinimum(Node* MyNode) {
	while (MyNode->left != NULL) {
		MyNode = MyNode->left;
	}
	return MyNode;
}

Node* TreeMaximum(Node* MyNode) {
	while (MyNode->right != NULL) {
		MyNode = MyNode->right;
	}
	return MyNode;
}

Node* TreeSuccessor(Node* MyNode) {
	if (MyNode->right != NULL) {
		return TreeMinimum(MyNode->right);
	}
	Node* tmp = MyNode->parent;
	while ((tmp != NULL) && (MyNode == tmp->right)) {
		MyNode = tmp;
		tmp = tmp->parent;
	}
	return tmp;
}

Node* TreePredecessor(Node* MyNode) {
	if (MyNode->left != NULL) {
		return TreeMaximum(MyNode->left);
	}
	Node* tmp = MyNode->parent;
	while ((tmp != NULL) && (MyNode == tmp->left)) {
		MyNode = tmp;
		tmp = tmp->parent;
	}
	return tmp;
}

void TreeInsert(Tree* MyTree, Node* NodeToAdd) {
	Node* tmp1 = NULL;
	Node* tmp2 = MyTree->root;
	int hight = 0;

	while (tmp2 != NULL) {
		tmp1 = tmp2;
		if (NodeToAdd->key < tmp2->key) {
			tmp1 = tmp1->left;
		}
		else {
			tmp1 = tmp1->right;
		}
		hight++;
	}
	NodeToAdd->parent = tmp1;
	if (tmp1 == NULL) {
		MyTree->root = NodeToAdd;
	}
	else if (NodeToAdd->key < tmp1->key) {
		tmp1->left = NodeToAdd;
		}
	else {
		tmp1->right = NodeToAdd;
		}

	if (hight > MyTree->size) {
		MyTree->size = hight;
		// Пересчет размера дерева
	}
}

void TreeTrans(Tree* tree, Node* x, Node* y) {
	if (x->parent == NULL) {
		tree->root = y;
	}
	else if (x == x->parent->left) {
		x->parent->left = y;
	}
	else {
		x->parent->right = y;
	}
	if (y != NULL) {
		y->parent = x->parent;
	}
}

void TreeDelete(Tree* MyTree, Node* NodeToDelete) {
	if (NodeToDelete->left == NULL) {
		TreeTrans(MyTree, NodeToDelete, NodeToDelete->right);
	}
	else if (NodeToDelete->right == NULL) {
		TreeTrans(MyTree, NodeToDelete, NodeToDelete->left);
	}
	else {
		Node* tmp = TreeMinimum(NodeToDelete->right);
		if (tmp->parent != NodeToDelete) {
			TreeTrans(MyTree, tmp, tmp->right);
			tmp->right = NodeToDelete->right;
			tmp->right->parent = tmp;
		}
		TreeTrans(MyTree, NodeToDelete, tmp);
		tmp->left = NodeToDelete->left;
		tmp->left->parent = tmp;
	}
}