/*
 * * author : lism2013@hotmail.com
 * * file       : b_tree.h
 * * cdatetime : 2017-02-06 08:32
 * */

#ifndef B_TREE_H
#define B_TREE_H

#define BMaxNodeNum 10
typedef struct BTreeNode{
    bool                leaf;
    int                 keyNum;
    struct BTreeNode*   parent;
    int                 key[BMaxNodeNum];
    struct BTreeNode*   ptr[BMaxNodeNum + 1];
}BTreeNode;

class BTree{
    public:
        BTree(){};
        ~BTree(){};

        void search(int key, BTreeNode* result){
        }

        void split(BTreeNode* p){
        }

        void insert(int key){
        }
    private:
        BTreeNode* node;
};

#endif /* !B_TREE_H */
