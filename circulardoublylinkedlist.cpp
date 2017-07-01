/*
 *  Implementation of a circular doubly linked list
 *  Insertion: O(1)
 *  Removal:   O(n)
 */

#include <iostream>
using namespace std;

#define SIZE 10

struct Node {
	int value;
	Node *prev;
	Node *next;
};

void insert(Node**, Node*);
void insert(Node**, Node*, int);
void remove(Node**, int);
void update(Node**, Node*, int);
void traverse(Node**);

int main() {

	Node *csll = NULL;

	// insertion
	Node n[2*SIZE];
	for(int i = 0; i < SIZE; i++) {
		n[i].value = i;
		n[i].prev = NULL;
		n[i].next = NULL;
		insert(&csll, &n[i]);
	}
	for(int i = SIZE; i < 2*SIZE; i++) {
		n[i].value = i;
		n[i].prev = NULL;
		n[i].next = NULL;
		insert(&csll, &n[i], i-SIZE);
	}

	traverse(&csll);

	return 0;

}

void insert(Node **h, Node *n){
	
	if(*h != NULL){
		n->next = *h;
		n->prev = (*h)->prev;
		(*h)->prev->next = n;
		(*h)->prev = n;
		*h = n;
	}
	else{
		n->prev = n;
		n->next = n;
		*h = n;
	}
}

void insert(Node **h, Node *n, int pos){
	
	if(*h != NULL){
		Node *i = *h;
		if(pos == 0) *h = n;
		while(pos > 0) {
			i = i->next;
			pos--;
		}
		n->next = i;
		n->prev = i->prev;
		i->prev->next = n;
		i->prev = n;
	}
}

void remove(Node **h, int pos){
	
}

void traverse(Node **h){
	if(h != NULL){
		Node *i = *h;
		while(true){
			cout << "Node: " << i->value << endl;
			i = i->next;
			if(i == *h) break;
		}
	}
}
