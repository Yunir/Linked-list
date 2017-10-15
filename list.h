#ifndef LIST_H
    #define LIST_H

    struct node {
        int value;
        struct node* next;
    };

    void pushNode(int new_data, struct node **head_ref);
    void printList(struct node *head);
    struct node readNumbers(struct node**);
    int sumOfList(struct node *head);
#endif
