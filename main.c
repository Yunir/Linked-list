#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main() {
    struct node *head = NULL;
    int sum;
    printf("Write number of integers\nTo confirm sequence - write 0 at the end:\n");
    readNumbers(&head);
    printList(head);
}
