#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main() {
    struct node *head = NULL;
    printf("Write number of integers\nTo confirm sequence - write 0 at the end:\n");
    readNumbers(&head);
    printList(head);
    printf("The summary of linked list elements: %d\n", sumOfList(head));
}
