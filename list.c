#include "list.h"

struct node readNumbers(struct node **head_ref) {
	int nextNumber;
    while(scanf("%d", &nextNumber) == 1) {
		if(nextNumber == 0) break;
		pushNode(nextNumber, head_ref);
    }
}

void pushNode(int new_data, struct node **head_ref) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->value = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// via foldl - Complete
/*int sumOfList(struct node *head) {
	int result = 0;
	while (head != NULL) {
		result += head->value;
		head = head->next;
	}
	return result;
}*/
int sumOfList(struct node *head) {
	int result = 0;
	return foldl(head, *sumOfTwo, result);
}

// returns void? - Complete
// UNPURE - Complete
bool findNode(struct node *head) {
	int counter;
	if(scanf("%d", &counter) == 1) {
		while (head != NULL) {
			if(counter == 0) {
				return true;
			}
			head = head->next;
			--counter;
		}
		if(counter < 0 || head == NULL) {
			return false;
		}
	} else {
		return false;
	}
}

void freeMemory(struct node *head) {
	while (head != NULL) {
		free(head);
		head = head->next;
	}
}

void foreach(struct node *head, void (*f)(int)){
	while (head != NULL) {
		f(head->value);
		head = head->next;
	}
}

void printNodeWithSpace(int value){
    printf("%d ",value);
}

void printNodeWithNewLine(int value){
    printf("%d\n",value);
}

struct node* map(struct node *head, int (*f)(int)){
    struct node *new_head = NULL;
	while (head!=NULL){
        pushNode(f(head->value), &new_head);
        head = head->next;
    }
    return new_head;
}

int squareIt(int element){
    return element*element;
}

int cubeIt(int element){
    return element*element*element;
}

int foldl(struct node *head, int (*f)(int, int), int buf) {
    while (head != NULL) {
        buf = f(buf, head->value);
        head = head->next;
    }
    return buf;
}

int max(int first,int second){
    if(first>second)
        return first;
    else
        return second;
}

int min(int first,int second){
    if(first<second)
        return first;
    else
        return second;
}

void map_mut(struct node *head,int (*f)(int)){
    while (head != NULL){
        head->value = f(head->value);
        head = head->next;
    }
}

struct node* iterate(int s, int size, int (*f)(int)){
    struct node* head = NULL;
    for(int i = 0; i < size; ++i){
        pushNode(s, &head);
		s = f(s);
    }
    return head;
}

int mulTo2(int element){
    return element*2;
}

int sumOfTwo (int a, int b) {
	return a+b;
}
