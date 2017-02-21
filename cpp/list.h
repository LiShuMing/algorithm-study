#include <assert.h>
#include "util.h"

typedef struct LinkNode {
    int                 val;
    struct LinkNode*    next;
} LinkNode;

// create list
LinkNode* createList(int val){
    //new ? malloc
    LinkNode* list = new LinkNode();
    list->next = NULL;
    list->val = val;
    //LinkNode* list = (LinkNode*)malloc(sizeof(LinkNode));
    return list;
}

// insert list
int addNode(LinkNode* list, LinkNode* node){
    assert(list != NULL);
    assert(node != NULL);

    // get the last node of list
    LinkNode* t = list;
    while (t->next != NULL){
        t = t->next;
    }

    t->next = node;

    return 0;
}

// delete node
void deleteNode(LinkNode* list, int index){
    assert(list != NULL);
    assert(index >= 0);

    int i = 0;
    LinkNode* t = list;
    while (i < index && t != NULL){
        t = t->next;
        i++;
    }

    if (t == NULL){
        return;
    }
    if (t->next == NULL){
        return;
    }

    LinkNode* d = t->next;
    t->next = t->next->next;
    delete d;
}

// merge two list
LinkNode* mergeTwoList(LinkNode* list1, LinkNode* list2){
    if (list1 == NULL || list2 == NULL){
        return NULL;
    }
    LinkNode* rNext = NULL;
    LinkNode* result = NULL;
    LinkNode* nL1 = list1;
    LinkNode* nL2 = list2;

    while ( nL1 != NULL && nL2 != NULL){
        LinkNode* tmp = new LinkNode();

        if (nL1->val < nL2->val){
            tmp->val = nL1->val;
            nL1 = nL1->next;
        } else {
            tmp->val = nL2->val;
            nL2 = nL2->next;
        }

        if (rNext == NULL){
            printf("result null\n");
            rNext = tmp;
            result = tmp;
        } else {
            rNext->next = tmp;
            rNext = tmp;
        }
    }

    if (nL1 == NULL){
        while (nL2 != NULL){
            LinkNode* tmp = new LinkNode();
            tmp->val = nL2->val;
            nL2 = nL2->next;

            rNext->next = tmp;
            rNext = tmp;
        }
    }
    if (nL2 == NULL){
        while (nL1 != NULL){
            LinkNode* tmp = new LinkNode();
            tmp->val = nL1->val;
            nL1 = nL1->next;

            rNext->next = tmp;
            rNext = tmp;
        }
    }

    return result;
}

// print list
void printList(LinkNode* list){
    assert(list != NULL);
    LinkNode* t = list;

    // head node
    printf("Node=%d\n", t->val);
    while (t->next != NULL){
        t = t->next;
        printf("Node=%d\n", t->val);
    }
}

// create node
LinkNode* createNode(int val){
    LinkNode* node = new LinkNode();
    node->val = val;
    node->next = NULL;
    return node;
}

// delete list
void deleteList(LinkNode* list){
    assert(list != NULL);
    LinkNode* t = list;

    while (t->next != NULL){
        delete t;
        t = t->next;
    }

    delete t;
}

// invert list 
// print pointer
void printPtr(LinkNode* ptr, const char* str){
    printf("%s ptr=%x\n", str, ptr);
}

// invert list
LinkNode* invertedLinkList(LinkNode* list){
    LinkNode* t = list;
    printPtr(list, "t");
    LinkNode* nextNode = t->next;
    t->next = NULL;

    while (nextNode->next != NULL){
        LinkNode* tmp = nextNode;
        printPtr(tmp, "tmp");
        nextNode = nextNode->next;
        tmp->next = t;

        // asign or pointer?
        t = tmp;
        printPtr(t, "t");
    }
    nextNode->next = t;

    // assign or pointer?(why?)
    t = nextNode;
    list = nextNode;
    return t;
}

// test
void testLinkList(){
    LinkNode* list = createList(0);
    LinkNode* node = NULL;

    for (int i = 1; i < 5; i++){
        node = createNode(i);
        addNode(list, node);
    }
    printList(list);

    printf("delete node 2\n");
    deleteNode(list, 2);
    printList(list);

    printf("inverted list\n");
    //LinkNode* t = invertedLinkList(list);
    //printList(t);

    printStr("list2");
    LinkNode* list2 = createList(3);
    for (int i = 4; i < 7; i++){
        node = createNode(i);
        addNode(list2, node);
    }
    printList(list2);

    printStr("merge list + list2");
    LinkNode* list3 = mergeTwoList(list, list2);
    printList(list3);

    deleteList(list);
    deleteList(list2);
    deleteList(list3);
}
