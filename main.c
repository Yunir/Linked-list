#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include "file.h"

int main() {
    int minimalEl = 99999;
    int maximalEl = -1;
    struct node *head = NULL;
    printf("Write number of integers\nTo confirm sequence - write 0 at the end:\n");
    readNumbers(&head);
    char *nameOfFile = "linkedList";
    if(serialize(head, nameOfFile)) {
        printf("Linked List is perfectly saved to file!\n");
    }
    foreach(head, *printNodeWithSpace);
    printf("\n");
    printf("The summary of linked list elements: %d\n\n", sumOfList(head));
    printf("What value of index in linked list you want to see?\nWrite the index of linked list: ");
    findNode(head);
    foreach(map(head, squareIt), *printNodeWithSpace);
    printf("\n");
    minimalEl = foldl(head, *min, minimalEl);
    maximalEl = foldl(head, *max, maximalEl);
    printf("The sum of the minimal and maximal element: %d + %d = %d\n", minimalEl, maximalEl, minimalEl+maximalEl);
    map_mut(head, squareIt);
    foreach(head, *printNodeWithSpace);
    printf("\n");
    foreach((iterate(1, 5, mulTo2)), *printNodeWithSpace);
    printf("\n");
    printf("Reading from file...\n");
    deserialize(&head, nameOfFile);
    printf("Linked list: ");
    foreach(head, *printNodeWithSpace);
    printf("\n");
    freeMemory(head);
}
