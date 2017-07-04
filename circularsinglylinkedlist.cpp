/*
 *  Implementation of a circular singly linked list
 *  Insertion: O(n)
 *  Removal:   O(n)
 */

#include <iostream>
using namespace std;

#define SIZE 10

struct Node {
	int value;
	Node *next;
};

void insert(Node* &, Node &);
void insert(Node* &, Node &, int);
void remove(Node* &, int);
void update(Node* &, Node &, int);
void traverse(Node* &);

int main() {

	Node *csll = NULL;

	// insertion
	Node n[3*SIZE];
	for(int i = 0; i < SIZE; i++) {
		n[i].value = i;
		n[i].next = NULL;
		insert(csll, n[i]);
	}
	for(int i = SIZE; i < 2*SIZE; i++) {
		n[i].value = i;
		n[i].next = NULL;
		insert(csll, n[i], i-SIZE);
	}
	for(int i = 0; i < SIZE/2; i++)
		remove(csll, i);
	for(int i = 2*SIZE; i < 2.5*SIZE; i++) {
		n[i].value = i;
		n[i].next = NULL;
		update(csll, n[i], i-2*SIZE);
	}

	traverse(csll);

	return 0;

}

void insert(Node* &h, Node &n){
	
	if(h != NULL){
		Node *i = h;
		while(i->next != h)
			i = i->next;
		i->next = &n;
		n.next = h;
	}
	else{
		n.next = &n;
		h = &n;
	}
}

void insert(Node* &h, Node &n, int pos){
	
	if(h != NULL){
		Node *i = h;
		if(pos == 0){
			while(i->next != h) i = i->next;
			h = &n;
		}
		else {
			while(pos > 1) {
				i = i->next;
				pos--;
			}
		}
		n.next = i->next;
		i->next = &n;
	}
}

void remove(Node* &h, int pos){
	
	if(h != NULL){
		if(h->next == h) h = NULL;
		else {
			Node *i = h;
			if(pos == 0){
				while(i->next != h) i = i->next;
				h = h->next;
			}
			else {
				while(pos > 1) {
					i = i->next;
					pos--;
				}
			}
			i->next = i->next->next;
		}
	}
}

void update(Node* &h, Node &n, int pos){

	if(h != NULL) {
		Node *i = h;
		if (pos == 0) h = &n;
		while(pos > 1) {
			i = i->next;
			pos--;
		}
		n.next = i->next->next;
		i->next = &n;
	}
}

void traverse(Node* &h){

	if(h != NULL){
		Node *i = h;
		while(true){
			cout << "Node: " << i->value << endl;
			i = i->next;
			if(i == h) break;
		}
	}
}
