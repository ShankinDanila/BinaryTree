Node* NewNode(int key, InfoType* information);
void FreeNode(Node* NodeToFree);
void Insert(Tree* tree, int key, InfoType* information);
void Delete(Tree* tree, int key);
void Search(Tree* tree, int key);
void Successor(Tree* tree, int key);
void Print(Node* ptr, long n);
void InorderWalk(Tree* tree, int key);
void FreeTree(Tree* tree);