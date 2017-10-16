#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main() {
    struct node *head = NULL;
    printf("Write number of integers\nTo confirm sequence - write 0 at the end:\n");
    readNumbers(&head);
    foreach(head, *printNodeWithSpace);
    printf("\n");
    printf("The summary of linked list elements: %d\n", sumOfList(head));
    printf("What value of index in linked list you want to see?\nWrite the index of linked list: ");
    findNode(head);
    freeMemory(head);
}
