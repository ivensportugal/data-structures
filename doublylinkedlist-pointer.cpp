/*
 *  Implementation of a doubly linked list with pointers
 *  Insertion = O(1)
 *  Removal   = O(n)
 */

#include <iostream>
using namespace std;

#define MAX 10

struct Node {
	int value;
	Node *prev;
	Node *next;
};

Node* insert  (Node*, Node &     ); 
Node* insert  (Node*, Node &, int);
Node* remove  (Node*,         int);
Node* update  (Node*, Node &, int);
void traverse (Node*             );

int main () {

	// creating nodes for test;
	Node arrayN[MAX];
	for(int i = 0; i < MAX; i++) {
		Node n;
		n.value = i;
		n.prev = NULL;
		n.next = NULL;
		arrayN[i] = n;
 	}


 	Node *sll = NULL;
 	for(int i = 0; i < MAX; i++)
		sll = insert(sll, arrayN[i]);
	traverse(sll);

	Node n;
	n.value = 100;
	n.next  = NULL;
 	sll = update(sll, n, 0);
 	traverse(sll);
	
	for(int i = 0; i < MAX; i++)
		sll = remove(sll, 0);
	traverse(sll);

	return 0;
}

Node* insert (Node *h, Node &n) {
	// checks whether the doubly linked list is empty
	if(h != NULL) {
		n.next = h;
		h->prev = &n;
	}
	return &n;
}

Node* insert (Node *h, Node &n, int pos) {
	// checks whether the doubly linked list is empty
	if(h != NULL) {
		Node *start;
		if(pos != 0) start =  h;
		else         start = &n;
		while(pos > 0) {
			h = h->next;
			pos--;
		}
		n.next = h;
		n.prev = h->prev;
		h->prev = &n;

		return start;
	}
	else
		return &n;
}

Node* remove(Node *h, int pos) {
	Node *start = h;
	// checks whether the doubly linked list is empty
	if(h != NULL) {
		if(h->next == NULL) return NULL;
		else {
			while(pos > 0) {
				h = h->next;
				pos--;
			}
			if(h->prev != NULL)
				h->prev = h->next;
			if(h->next != NULL)
				h->next = h->prev;
		}
	}
	return start;
}

Node* update(Node *h, Node &n, int pos) {
	Node *start = h;
	// checks whether the doubly linked list is empty
	if(h != NULL) {
		if(h->next == NULL) return &n;
		else {
			while(pos > 0) {
				h = h->next;
				pos--;
			}

			n.prev = h->prev;
			n.next = h->next;

			if(h->prev != NULL)
				h->prev = &n;
			if(h->next != NULL)
				h->next = &n;
		}
	}
	return start;
}

void traverse(Node *n) {
	// checks whether the singy linked list is empty
	if(n != NULL)
		while(true) {
			cout << "Node: " << n->value << endl;
			if(n->next == NULL) break;
			n = n->next;
		}
}