#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tree.h"
#include "Dialog.h"
#include "Work.h"

Node* NewNode(int key, InfoType* information) {
	Node* Node_new = (Node*)calloc(1, sizeof(Node));
	Node_new->len = 1;
	Node_new->info = (InfoType*)realloc(Node_new->info, 1 * sizeof(InfoType));
	Node_new->info = information;
    Node_new->key = key;
	return Node_new;
}

void FreeNode(Node* NodeToFree) {
	for (int i = 0; i < NodeToFree->len; i++) {
		free(NodeToFree->info[i].string);
	}
	free(NodeToFree->info);
	free(NodeToFree);
}

void Insert(Tree* tree, int key, InfoType* information) {
    Node* ptr = NewNode(key, information);
    Node* x = TreeSearch(tree->root, ptr->key);
    if (x == NULL) {
        TreeInsert(tree, ptr);
    }
    else {
        x->len++;
        x->info = (InfoType*)realloc(x->info, (x->len + 1) * sizeof(InfoType));
        x->info[x->len - 1].string = (char*)calloc(strlen(information->string) + 1, sizeof(char));
        x->info[x->len - 1].num = information->num;
        strcpy(x->info[x->len - 1].string, information->string);
        FreeNode(ptr);
    }
}

void Delete(Tree* tree, int key) {
    Node* ptr = TreeSearch(tree->root, key);
    if (ptr->len == 1) {
        TreeDelete(tree, ptr);
        FreeNode(ptr);
    }
    else {
        free(ptr->info[0].string);
        ptr->len--;
    }
}

void Search(Tree* tree, int key) {
    Node* ptr = TreeSearch(tree->root, key);
    Data_Print(ptr->info, ptr->len);
}

void Successor(Tree* tree, int key) {
    Node* ptr = TreeSearch(tree->root, key);
    Node* suc = TreeSuccessor(ptr);
    printf("%d: ", suc->key);
    Data_Print(suc->info, suc->len);
}

void Print(Node* ptr, long n) {
    long i;
    if (ptr) {
        Print(ptr->right, n + 2);
        for (i = 0; i < n; i++)
            printf(" ");
        printf("%s\n", ptr->key);
        Print(ptr->left, n + 2);
    }
}

void InorderWalk(Tree* tree, int key) {
    Node* ptr = TreeSearch(tree->root, key);
    Print(ptr, 0);
}

void FreeTree(Tree* tree) {
    while (tree->root) {
        Delete(tree, tree->root->key);
    }
}
