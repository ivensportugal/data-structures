/*
 * Implementation of a Binary Tree
 *
 * Insertion: O(log n)
 * Deletion: O(log n)
 * Search: O(log n) // Worst case: (n)
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX 10

struct Node{
	int value;
	Node* left;
	Node* right;
};

void insert(Node* &, Node&);
void remove(Node* &, int);
Node* search(Node*, int);
void print(Node *); // bfs

int main (void) {

	Node* btree = NULL;

	srand(time(NULL));
	Node nodes[MAX];
	for(int i = 0; i < MAX; i++) {
		nodes[i].value = rand() % (MAX*MAX);
		nodes[i].left  = NULL;
		nodes[i].right = NULL;
	}
	

	for(int i = 0; i < MAX; i++) {
		cout << "inserting " << nodes[i].value << endl;
		insert(btree, nodes[i]);
	}

	print(btree);

	for(int i = 0; i < MAX; i++) {
		cout << "removing " << i << endl;
		remove(btree, i);
	}

	print(btree);

	int i = rand() % (MAX*MAX);
	Node* n;
	n = search(btree, i);
	cout << "i       : " << i       << endl;
	if(n != NULL)
	cout << "n->value: " << n->value << endl;

	return 0;
}

void insert(Node* &btree, Node &n) {

	Node *i;
	i = btree;

	if(btree != NULL) {
		while(true) {
			if(n.value < i->value)
				if(i->left != NULL)
					i = i->left;
				else {
					i->left = &n;
					break;
				}
			else
				if(i->right != NULL)
					i = i->right;
				else {
					i->right = &n;
					break;
				}
		}
	} else {
		btree = &n;
	}
}

void remove(Node* &btree, int value) {

	Node *i;
	Node *p; //parent
	i = btree;

	if(btree != NULL) {
		while(true) {
			if(value < i->value)
				if(i->left != NULL) {
					p = i;
					i = i->left;
				}
				else
					break;
			else if(value > i->value)
				if(i->right != NULL) {
					p = i;
					i = i->right;
				}
				else
					break;
			else if(value == i->value)
				if(i->left == NULL && i->right != NULL){
					*i = *(i->right);
					break;
				}
				else if(i->left != NULL && i->right == NULL){
					*i = *(i->left);
					break;
				}
				else if(i->left != NULL || i->right != NULL){
					Node* j;
					j = i->left;
					while(j->right != NULL)
						j = j->right;
					i->value = j->value;
					remove(j, j->value);
					break;
				}
				else if(i->left == NULL && i->right == NULL){
					if(p->left->value == i->value) p->left = NULL;
					else if(p->right->value == i->value) p->right = NULL;
					break;
				}
		}
	}
}

Node* search(Node* btree, int value){
	if(btree != NULL){
		Node* i;
		i = btree;
		while(true)
			if(i->value < value)
				if(i->left != NULL)
					i = i->left;
				else
					return NULL;
			else if(i->value > value)
				if(i->right != NULL)
					i = i->right;
				else
					return NULL;
			else if(i->value == value)
				return i;
	}
	return NULL;
}

void print(Node * n) {
	cout << "Node: " << n->value << endl;

	if(n->left  != NULL) print(n->left);
	if(n->right != NULL) print(n->right);
}