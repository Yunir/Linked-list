#include "list.h"
#include "file.h"
#define items_of_data 1
#define successful_query 1

bool write(struct node *head, char *name) {

    FILE *file = fopen(name, "w");
    if(!file) return false;
    while(head != NULL) {
        if(fwrite(&(head->value), sizeof(int), items_of_data, file) != successful_query) {
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
    if(fread(&value, sizeof(int), items_of_data, file)!=successful_query){
        fclose(file);
        return false;
    }
    struct node* new_head = NULL;
    pushNode(value, &new_head);
    while(fread(&value, sizeof(int), items_of_data, file) == successful_query) {
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
        if(fwrite(&(head->value), sizeof(int), items_of_data, file) != successful_query) {
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
    if(fread(&value, sizeof(int), items_of_data, file) != successful_query){
        fclose(file);
        return false;
    }
    struct node* new_head = NULL;
    pushNode(value, &new_head);
    while(fread(&value, sizeof(int), items_of_data, file) == successful_query) {
        pushNode(value, &new_head);
    }
    freeMemory(*head);
    *head = new_head;
    if(fclose(file) == EOF)
        return false;
    return true;
}
