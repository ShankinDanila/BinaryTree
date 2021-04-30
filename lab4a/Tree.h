typedef struct InfoType {
	double num;
	char* string;
} InfoType;

typedef struct Node {
	int key;
	int len;
	struct InfoType* info;
	struct Node* parent;
	struct Node* right;
	struct Node* left;
} Node;

typedef struct Tree {
	Node* root;
	int size;
} Tree;


void IncorderTreeWalk(Node* ptr);
Node* TreeSearch(Node* MyNode, int KeyToSearch);
Node* TreeMinimum(Node* MyNode);
Node* TreeMaximum(Node* MyNode);
Node* TreeSuccessor(Node* MyNode);
Node* TreePredecessor(Node* MyNode);
void TreeInsert(Tree* MyTree, Node* NodeToAdd);
void TreeTrans(Tree* tree, Node* x, Node* y);
void TreeDelete(Tree* MyTree, Node* NodeToDelete);
