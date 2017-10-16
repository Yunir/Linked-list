#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include "file.h"

bool write(struct node *head, char *name) {
    FILE *file = fopen(name, "w");
    if(!file) return false;
    while(head != NULL) {
        if(fwrite(&(head->value), sizeof(int), 1, file) != 1) {
            fclose(file);
            return false;
        }
        head = head->next;
    }
    if(fclose(file) == EOF)
        return false;
    return true;
}

bool read(struct node **head, char *name) {
    FILE* file = fopen(name, "r");
    if(!file) return false;
    int value;
    if(fread(&value, sizeof(int), 1, file)!=1){
        fclose(file);
        return false;
    }
    struct node* new_head = NULL;
    pushNode(value, &new_head);
    while(fread(&value, sizeof(int), 1, file) == 1) {
        pushNode(value, &new_head);
    }
    freeMemory(*head);
    *head = new_head;
    if(fclose(file) == EOF)
        return false;
    return true;
}

bool serialize(struct node *head, char *name) {
    FILE *file = fopen(name, "wb");
    if(!file) return false;
    while(head != NULL) {
        if(fwrite(&(head->value), sizeof(int), 1, file) != 1) {
            fclose(file);
            return false;
        }
        head = head->next;
    }
    if(fclose(file) == EOF)
        return false;
    return true;
}

bool deserialize(struct node **head, char *name) {
    FILE* file = fopen(name, "rb");
    if(!file) return false;
    int value;
    if(fread(&value, sizeof(int), 1, file)!=1){
        fclose(file);
        return false;
    }
    struct node* new_head = NULL;
    pushNode(value, &new_head);
    while(fread(&value, sizeof(int), 1, file) == 1) {
        pushNode(value, &new_head);
    }
    freeMemory(*head);
    *head = new_head;
    if(fclose(file) == EOF)
        return false;
    return true;
}
