#include <stdio.h>
#include <stdlib.h>
#include "Dialog.h"
#include "Tree.h"
#include "Work.h"

const char* MSGS[] = { "0. Quit", "1. Add new node", "2. Delete node with key", "3. Search with key",
                      "4. Print table", "5. Find successor"};

const int MSGS_SIZE = sizeof(MSGS) / sizeof(MSGS[0]);

int main() {
    int c = 0;
    char* string;
    int len, pos;
    int key;
    double number;
    Tree* tree = (Tree*)calloc(1, sizeof(Tree));
    do {
        c = dialog(MSGS, MSGS_SIZE);
        switch (c) {
        case 0:
            break;

        case 1:
            puts("Please, enter a key: ");
            scanf("%d", &key);
            puts("Please, enter a string: ");
            string = get_str();
            puts("Please, enter a number: ");
            scanf("%lf", &number);
            InfoType* information = (InfoType*)calloc(1, sizeof(InfoType));
            information->num = number;
            information->string = string;
            Insert(tree, key, information);
            break;

        case 2:
            puts("Please, enter a key: ");
            scanf("%d", &key);
            Delete(tree, key);
            break;

        case 3:
            puts("Please, enter a key:");
            scanf("%d", &key);
            Search(tree, key);
            break;

        case 4:
            puts("Please, enter a root key:");
            scanf("%d", &key);
            InorderWalk(tree, key);
            break;

        case 5:
            puts("Please, enter a key:");
            scanf("%d", &key);
            Successor(tree, key);
            break;  
        }
    } while (c != 0);
    FreeTree(tree);
    free(tree);

    return 0;
}