/* ***********************************************/
/* Luke McDougall                                             */
/* 11/10/2021                                                    */
/* CS-241 Section 1                                            */
/*************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

/* Alloc a new node with given data. */
struct TreeNode* createNode(char data)
{
  struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  if (newNode != NULL)
  {
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
  }
  return newNode;
}

/* Insert data at appropriate place in BST, return new tree root. */
struct TreeNode* insertBST(struct TreeNode* root, char data)
{
  struct TreeNode* newNode = createNode(data);
  /* empty tree, return new node */
  if (root == NULL)
  {
    return newNode;
  }
  /* recur down tree if tree is not empty */
  if (data < root->data)
  {
    root->left = insertBST(root->left, data);
  }
  else if (data > root->data)
  {
    root->right = insertBST(root->right, data);
  }
  return root;
}

/* Return node with minimum value in non-empty binary search tree. */
struct TreeNode* minValueNode(struct TreeNode* root)
{
  struct TreeNode* current = root;

  while (current && current->left != NULL)
  {
    current = current->left;
  }
  return current;
}

/* Helper function used in removeBST. Searches tree for specific data value, 
if found return 1, if not returns 0. */
int searchHelper(struct TreeNode* root, char data)
{
  int res1, res2;
  if (root == NULL) return 0;
  
  if (root->data == data) return 1;

  res1 = searchHelper(root->left, data);
  if (res1) return 1;

  res2 = searchHelper(root->right, data);
  if (res2) return 1; 
  return 0;
}

/* Helper function used in removeBST. Removes specified data from the BST recursively*/
struct TreeNode* removeHelper(struct TreeNode* root, char data)
{
  struct TreeNode* temp;
  if (root == NULL) return root;

  if (data < root->data)
  {
    root->left = removeHelper(root->left, data);
  }
  else if (data > root->data)
  {
    root->right = removeHelper(root->right, data);
  }
  else
  {
    if (root->left == NULL)
    {
      temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      temp = root->left;
      free(root);
      return temp;
    }
    temp = minValueNode(root->right);
    root->data = temp->data;
    root->right = removeHelper(root->right, temp->data);
  }
  return root;
}

/* Remove data from BST pointed to by rootRef, changing root if necessary.
 * For simplicity's sake, always choose node's in-order
 *   predecessor in the two-child case.
 * Memory for removed node should be freed.
 * Return 1 if data was present, 0 if not found. */
int removeBST(struct TreeNode** rootRef, char data)
{
  if (searchHelper((*rootRef),data))
  {
    removeHelper((*rootRef), data);
    return 1;
  }
  else
  {
    return 0;
  }
  
}

/* Return maximum value in non-empty binary search tree. */
char maxValueBST(struct TreeNode* root)
{
  struct TreeNode* current = root;
  while (current->right != NULL)
  {
    current = current->right;
  }
  return(current->data);
}

/* Return maximum depth of tree. Empty tree has depth 0. */
int maxDepth(struct TreeNode* root)
{
  int leftDepth;
  int rightDepth;

  if (root == NULL) return 0;
  else
  {
    leftDepth = maxDepth(root->left);
    rightDepth = maxDepth(root->right);

    if (leftDepth > rightDepth) return (leftDepth + 1);
    else return (rightDepth + 1);
  }
}

/* Helper function used in isBlanced that returns the height of a tree */
int height(struct TreeNode* root)
{
  if (root == NULL) return 0;

  /* if tree is nonempty, returns a height of 1 + the max height of left and right height */
  return 1 + ((height(root->left) >= height(root->right)) ? height(root->left) : height(root->right));
}

/* A tree is balanced if both subtrees are balanced and
 * the difference in height between the subtrees is no more than 1.
 * Return 1 if tree is balanced, 0 if not. */
int isBalanced(struct TreeNode* root)
{
  int leftHeight;
  int rightHeight;

  if (root == NULL) return 1;

  leftHeight = height(root->left);
  rightHeight = height(root->right);

  if(abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
  {
    return 1;
  }
  return 0;
}

/* returns maximum value is a given binary tree. used as a helper metthod for isBST */
char findMax(struct TreeNode* root)
{
  char result;
  char leftResult;
  char rightResult;

  if (root == NULL) return 0;

  result = root->data;
  leftResult = findMax(root->left);
  rightResult = findMax(root->right);

  if (leftResult > result) result = leftResult;
  if (rightResult > result) result = rightResult;
  return result;
}

/* return minimum value in a given binary tree. used as a helper method for isBST */
char findMin(struct TreeNode* root)
{
  char result;
  char leftResult;
  char rightResult;

  if (root == NULL) return 100; 

  result = root->data;
  leftResult = findMin(root->left);
  rightResult = findMin(root->right);

  if (leftResult < result) result = leftResult;
  if (rightResult < result) result = rightResult;
  return result;
}

/* Return 1 if tree is a binary search tree, 0 if not. */
int isBST(struct TreeNode* root)
{
  if (root == NULL) return 1;

  if (root->left != NULL && findMax(root->left) > root->data) return 0;
  if (root->right != NULL && findMin(root->right) < root->data) return 0;
  if (!isBST(root->left) || !isBST(root->right)) return 0;

  return 1;
}

/* helper function for printTree which recursively prints data for inorder tree traversal on a sinlge line*/
void printTreeHelper(struct TreeNode* root)
{
  if (root == NULL) return;

  printTreeHelper(root->left);
  printf("%c ", root->data);
  printTreeHelper(root->right);
}

/* Print data for inorder tree traversal on single line,
 * separated with spaces, ending with newline. */
void printTree(struct TreeNode* root)
{
  printTreeHelper(root);
  printf("\n");
}

/* helper function for printLeaves which recursively prints data for leaves on a single line */
void printLeavesHelper(struct TreeNode* root)
{
  if(root == NULL) return;

  if ((root->left == NULL) && (root->right == NULL))
  {
    printf("%c ",root->data);
  }
  if (root->left != NULL) printLeavesHelper(root->left);
  if (root->right != NULL) printLeavesHelper(root->right);
}
/* Print data for leaves on single line,
 * separated with spaces, ending with newline.*/
void printLeaves(struct TreeNode* root)
{
  printLeavesHelper(root);
  printf("\n");
}

/* helper function for printVerbose which recursively prints data in preorder with its depth*/
void printVerboseHelper(struct TreeNode* root, int depth)
{
  if (root == NULL) return;
  printf("(%c,%d) ", root->data, depth);
  printVerboseHelper(root->left, depth+1);
  printVerboseHelper(root->right, depth+1);
}

/* Print data for a preorder tree traversal on a single line
 * as a sequence of (data, depth) pairs
 * separated with spaces, ending with newline.
 * (The root node has a depth of 1)
 *
 *  So, the tree
 *
 *      A
 *     / \
 *    B   C
 *   / \
 *  D   E
 *
 * will produce the output
 * (A,1) (B,2) (D,3) (E,3) (C,2) 
 */
void printTreeVerbose(struct TreeNode* root)
{
  printVerboseHelper(root, 1);
  printf("\n");
}

/* Free memory used by the tree. */
void freeTree(struct TreeNode* root)
{
  if (root != NULL)
  {
    freeTree(root->right);
    freeTree(root->left);
    free(root);
  }
}