/*
 *  Implementation of a singly linked list with pointers
 *  Insertion = O(1)
 *  Removal   = O(n)
 */

#include <iostream>
using namespace std;

#define MAX 10

struct Node {
	int value;
	Node *next;
};

Node* insert  (Node*, Node*     ); 
Node* insert  (Node*, Node*, int);
Node* remove  (Node*,        int);
Node* update  (Node*, Node*, int);
void traverse (Node*            );

int main () {

	// creating nodes for test;
	Node arrayN[MAX];
	for(int i = 0; i < MAX; i++) {
		Node n;
		n.value = i;
		n.next = NULL;
		arrayN[i] = n;
 	}


 	Node *sll = NULL;
 	for(int i = 0; i < MAX; i++)
		sll = insert(sll, &arrayN[i]);
	traverse(sll);

	Node n;
	n.value = 100;
	n.next  = NULL;
 	sll = update(sll, &n, 0);
 	traverse(sll);
	
	for(int i = 0; i < MAX; i++)
		sll = remove(sll, 0);
	traverse(sll);

	return 0;
}

Node* insert (Node *h, Node *n) {
	// checks whether the singly linked list is empty
	if(h != NULL)
		n->next = h;
	return n;
}

Node* insert (Node *h, Node *n, int pos) {
	// checks whether the singly linked list is empty
	if(h != NULL) {
		Node *start;
		if(pos != 0) start = h;
		else         start = n;
		while(pos > 0) {
			if(pos == 1) {
				Node *tmp;
				tmp = h->next;
				h->next = n;
				h = tmp;
			}
			else h = h->next;
			pos--;
		}
		n->next = h;
		return start;
	}
	else
		return n;
}

Node* remove(Node *h, int pos) {
	Node *start = h;
	// checks whether the singly linked list is empty
	if(h != NULL) {
		if(h->next == NULL) return NULL;
		else if(pos == 0) start = h->next;
		else {
			while(pos > 1) {
				h = h->next;
				pos--;
			}
			h->next = h->next->next;
		}
	}
	return start;
}

Node* update(Node *h, Node *n, int pos) {
	Node *start = h;
	// checks whether the singly linked list is empty
	if(h != NULL) {
		if(h->next == NULL) return n;
		else if(pos == 0){
			n->next = h->next;
			start = n;
		}
		else {
			while(pos > 1) {
				h = h->next;
				pos--;
			}
			n->next = h->next->next;
			h->next = n;
		}
	}
	return start;
}

void traverse(Node *n) {
	// checks whether the singly linked list is empty
	if(n != NULL)
		while(true) {
			cout << "Node: " << n->value << endl;
			if(n->next == NULL) break;
			n = n->next;
		}
}