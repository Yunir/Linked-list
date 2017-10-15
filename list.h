#ifndef LIST_H
    #define LIST_H

    struct node {
        int value;
        struct node* next;
    };

    void pushNode(int, struct node**);
    void printList(struct node*);
    struct node readNumbers(struct node**);
    int sumOfList(struct node*);
    void findNode(struct node*);
    void freeMemory(struct node*);
#endif
