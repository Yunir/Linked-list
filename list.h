#ifndef LIST_H
    #define LIST_H

    struct node {
        int value;
        struct node* next;
    };

    void pushNode(int, struct node**);
    struct node readNumbers(struct node**);
    int sumOfList(struct node*);
    void findNode(struct node*);
    void freeMemory(struct node*);
    void foreach(struct node*, void (*f)(int));
    void printNodeWithSpace(int value);
    void printNodeWithNewLine(int value);
    struct node* map(struct node*, int (*f)(int));
    int squareIt(int);
    int cubeIt(int);
#endif
