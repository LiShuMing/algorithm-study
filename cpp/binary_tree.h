/*
* author	: lism2013@hotmail.com
* file		: binary_tree.h
* cdatetime : 2017-02-04 15:50
*/

//#include <cmath>
#include <math.h>
#include "util.h"

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

// struct
typedef struct BinaryTreeNode{
    int             val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
}BinaryTreeNode;

// count binary_tree node nums
int countBinaryTreeNodeNums(BinaryTreeNode* root){
    int count = 1;

    if (root->left != NULL){
        count += countBinaryTreeNodeNums(root->left);
    }     
    if (root->right != NULL){
        count += countBinaryTreeNodeNums(root->right);
    }

    return count;
}

// is total binary_tree
bool isTotalBinaryTree(BinaryTreeNode* root){
    int count = countBinaryTreeNodeNums(root);
    printf("count=%d\n", count);
    //TODO
    float cc = log2(count + 1);
    if ((long)cc == cc){
        return true;
    }
    return false;
}

// the depth of a total binary tree
int depthOfBinaryTree(BinaryTreeNode* root){
    int count = countBinaryTreeNodeNums(root);
    return log2(count) + 1;
}

// create binary_tree
BinaryTreeNode* createBinaryTreeNode(int rootVal){
    BinaryTreeNode* root = new BinaryTreeNode();
    root->val = rootVal;
    root->left = NULL;
    root->right = NULL;
    return root;
}

// find need to insert node
BinaryTreeNode* findNeedToInsertBinaryNode(BinaryTreeNode* root){
    BinaryTreeNode* result = NULL;
    
    if (root->left == NULL && root->right == NULL){
        return root;
    }
    if (root->left != NULL && root->right == NULL){
        return root;
    }
   
    if (root->left != NULL && root->right != NULL){
        if (isTotalBinaryTree(root->left)){
            if (root->left->left == NULL){
                return root->left;
            }
            // TODO: optimal
            if (isTotalBinaryTree(root->right)){
                if (depthOfBinaryTree(root->left) > depthOfBinaryTree(root->right)){
                    result = findNeedToInsertBinaryNode(root->right);
                } else {
                    result = findNeedToInsertBinaryNode(root->left);
                }
            } else {
                result = findNeedToInsertBinaryNode(root->right);
            }
        } else {
            result = findNeedToInsertBinaryNode(root->left);
        }
    }

    return result;
}

// binary_tree add node
void addBinaryTreeNode(BinaryTreeNode* root, BinaryTreeNode* node){
    BinaryTreeNode* pos = findNeedToInsertBinaryNode(root);
    if (pos->left == NULL){
        pos->left = node;
    } else {
        pos->right= node;
    }
}

// binary_tree add node val
void addBinaryTreeNode(BinaryTreeNode* root, int val){
    BinaryTreeNode* node = createBinaryTreeNode(val);
    printf("create node=%d\n", val);
    addBinaryTreeNode(root, node);
}

// delete binary_tree
void deleteBinaryTreeNode(BinaryTreeNode* root){
    if (root->left != NULL){
        deleteBinaryTreeNode(root->left);
    }
    if (root->right != NULL){
        deleteBinaryTreeNode(root->right);
    }
    delete root;
}

// inorder traverse
void inorderTraverse(BinaryTreeNode* root){
    if (root->left != NULL){
        inorderTraverse(root->left);
    }
    printf("%d\t", root->val);
    if (root->right != NULL){
        inorderTraverse(root->right);
    }
}

// postorder traverse
void postorderTraverse(BinaryTreeNode* root){
    if (root->left != NULL){
        postorderTraverse(root->left);
    }
    if (root->right != NULL){
        postorderTraverse(root->right);
    }
    printf("%d\t", root->val);
}

// preorder traverse
void preorderTraverse(BinaryTreeNode* root){
    printf("%d\t", root->val);
    if (root->left != NULL){
        preorderTraverse(root->left);
    }
    if (root->right != NULL){
        preorderTraverse(root->right);
    }
}

// print binary_tree by level
void printBinaryTreeLevel(BinaryTreeNode* root, int level){
    if (level == 1){
        printf("%d\t", root->val);
        return;
    }

    int newLevel = level - 1;
    if (root->left != NULL){
        printBinaryTreeLevel(root->left, newLevel);
    }
    if (root->right != NULL){
        printBinaryTreeLevel(root->right, newLevel);
    }
}

// print binary_tree levely
void printBinaryTreeByLevel(BinaryTreeNode* root){
    int depth = depthOfBinaryTree(root);
    print(depth);
    for (int i = 0; i < depth; i++){
        printBinaryTreeLevel(root, i+1);
        printN();
    }
}

// search binary_tree 
BinaryTreeNode* searchBinaryTree(BinaryTreeNode* root, int key){
    if (root == NULL){
        return NULL;
    }

    if (root->val == key){
        return root;
    }
    if (root->left != NULL){
        return searchBinaryTree(root->left, key);
    }

    if (root->right != NULL){
        return searchBinaryTree(root->right, key);
    }

    return NULL;
}

// test BinaryTreeNode
void testBinaryTree(){
    BinaryTreeNode* root = createBinaryTreeNode(0);
    for (int i = 1; i < 10; i++){
        addBinaryTreeNode(root, i);
    }

    preorderTraverse(root);
    printf("\n");

    inorderTraverse(root);
    printf("\n");

    postorderTraverse(root);
    printf("\n");

    printBinaryTreeByLevel(root);

    deleteBinaryTreeNode(root);
}

#endif /* !BINARY_TREE_H */
