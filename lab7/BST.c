#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

#define DATA_FILE "data.txt"
#define DEBUG 0

int main(void) {
  struct Tree *tree = createTree();
  struct Data data;
  struct Node *node;
  int r, value;
  FILE *fp;

  // insert values from data.txt file
  fp = fopen(DATA_FILE, "r");
  r = fscanf(fp, "%d", &value);
  while(r != EOF) {
    data.value = value;
    insert(tree, data);
    r = fscanf(fp, "%d", &value);
  }
  fclose(fp);

  //print tree
  printf("Display entire tree\n");
  printTree(tree);

  // get user search input
  printf("Enter values to search in tree, (type 0 to exit):\n");
  r = scanf("%d", &value);
  while(value != 0) {
    data.value = value;
    node = search(tree, data);
    if (node != NULL) {
      printf("Display subtree V1\n");
      printTreeNode1(node);
      printf("\nDisplay subtree V2\n");
      printTreeNode2(node, 0);
    }
    r = scanf("%d", &value);
  }
  return 0;
}

// Tree
// allocated a tree and initialized the root to NULL
struct Tree *createTree() {
  struct Tree *tree = (struct Tree *)malloc(sizeof(struct Tree));
  tree->root = NULL;
  return tree;
}
// Node
// takes data struct and allocates a node and initializes 
// the left, right, parent fields to NULL
struct Node *createNode(struct Data value) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
  node->data = value;
  return node;
}

// Insert
void insert(struct Tree *bst, struct Data value) {
  if (DEBUG) {
    printf("insert(%p, %d)\n", bst, value.value);
  }
  // first node?
  if(bst->root == NULL) {
    bst->root = createNode(value);
    if(DEBUG) { 
      printNode(bst->root);
    }
    return;
  }
  // duplicate value?
  if (bst->root->data.value == value.value) {
    printf("This value is already in the tree, exiting the program\n");
    exit(1);
  }
  insertNode(bst->root, value);
}

// Insert Node
void insertNode(struct Node *node, struct Data value) {
  if (DEBUG) {
    printf("   insertNode(%p, %d)\n", node, value.value);
  }
  struct Node *new_node; 

  // less than?
  if(value.value < node->data.value) {
    if(node->left == NULL) {
      new_node = createNode(value);
      new_node->parent = node;
      node->left = new_node;
      if(DEBUG) {
	printNode(new_node);
      }
      return;
    }
    else {
      insertNode(node->left, value);
    }
  }
  // greater than
  else {
    if(node->right == NULL) {
      new_node = createNode(value);
      new_node->parent = node;
      node->right = new_node;
      if(DEBUG) {
	printNode(new_node);
      }
      return;
    }
    else {
      insertNode(node->right, value);
    }
  }
}

// search
struct Node *search(struct Tree *bst, struct Data value) {
  if (DEBUG) {
    printf("search(%p, %d)\n", bst, value.value);
  }
  // first node?
  if(bst->root == NULL) {
    printf("%d not found\n", value.value);
    return (struct Node *)NULL;
  }
  return searchNode(bst->root, value);
}

// searchNode
struct Node *searchNode(struct Node *node, struct Data value) {
  if (DEBUG) {
    printf("   searchNode(%p, %d)\n", node, value.value);
  }
  if(value.value == node->data.value) {
    printf("%d found\n", value.value);
    return node;
  }
  
  // less than?
  if(value.value < node->data.value) {
    if(node->left == NULL) {
      printf("%d not found\n", value.value);
      return (struct Node *)NULL;
    }
    return searchNode(node->left, value);
  }
  // greater than
  else {
    if(node->right == NULL) {
      printf("%d not found\n", value.value);
      return (struct Node *)NULL;
    }
    return searchNode(node->right, value);
  }
}

// printNode 
void printNode(struct Node *node) {
  int parent = node->parent ? node->parent->data.value : 0;
  int left = node->left ? node->left->data.value : 0;
  int right = node->right ? node->right->data.value : 0;
  int value = node->data.value;
  printf("(Parent %d: %d <- %d -> %d)\n", parent, left, value, right);
}

//printTree
void printTree(struct Tree *bst) {
  if (bst == NULL) {
    printf("empty tree\n");
    return;
  }
  printf("Display Tree V1\n");
  printTreeNode1(bst->root);
  printf("\n");
  printf("Display Tree V2\n");
  printTreeNode2(bst->root, 0);
  printf("\n");
}
void printTreeNode1(struct Node *node) {
  if (node->left) {
    printTreeNode1(node->left);
  }
 
  printf("%d ", node->data.value);
  printNode(node);
  
  if (node->right) {
    printTreeNode1(node->right);
  }
}

void printTreeNode2(struct Node *node, int indent) {
  if (node->left) {
    printTreeNode2(node->left, indent+1);
  }
  printf("%*s--%d\n", indent*4, " ", node->data.value);
  if (node->right) {
    printTreeNode2(node->right, indent+1);
  }
}

