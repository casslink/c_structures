struct Data {
  int value;
};

struct Node {
  struct Node *left;  
  struct Node *right;
  struct Node *parent;
  struct Data data;
};

struct Tree {
  struct Node *root;
};

struct Tree *createTree();
struct Node *createNode(struct Data value);
void insertNode(struct Node *node, struct Data value);
void insert(struct Tree *bst, struct Data value);
struct Node *search(struct Tree *bst, struct Data value);
void printNode(struct Node *node);
struct Node *search(struct Tree *bst, struct Data value);
struct Node *searchNode(struct Node *node, struct Data value);
void printTree(struct Tree *bst);
void printTreeNode1(struct Node *node);
void printTreeNode2(struct Node *node, int indent);
