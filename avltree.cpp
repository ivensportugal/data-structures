/*  Implementation of an AVL tree
 *  Insertion: O(log n)
 *  Removal  : O(log n)
 *  Search   : O(log n)
 */

#include <iostream>
#include <algorithm>
using namespace std;

#define SIZE 10

struct Node {
	int value;
	int height_left;
	int height_right;
	Node* left;
	Node* right;
};

int  insert(Node* &, Node &);
void remove(Node*, int);
void traverse(Node*);

void left_rotation(Node* &);
void right_rotation(Node* &);
void left_right_rotation(Node* &);
void right_left_rotation(Node* &);

int main (void) {

	Node *avltree = NULL;
	int iNodes[SIZE] = {30,10,20,40,50,60,70,80,90,100};
	Node nNodes[SIZE];

	for(int i = 0; i < SIZE; i++){
		nNodes[i].value = iNodes[i];
		nNodes[i].height_left  = 0;
		nNodes[i].height_right = 0;
		nNodes[i].left  = NULL;
		nNodes[i].right = NULL;
		insert(avltree, nNodes[i]);
	}

	cout << "Final Configuration:" << endl;
	traverse(avltree);

	return 0;
}

int insert(Node* &avltree, Node &n){
	if(avltree != NULL) {
		Node* i = avltree;
		if(n.value < i->value){
			i->height_left = insert(i->left, n) + 1;
			if((i->height_left - i->height_right) > 1){
				// rotate
				if(n.value < i->left->value)
					right_rotation(i);
				else
					left_right_rotation(i);
				avltree = i;
			}
		}
		else{
			i->height_right = insert(i->right, n) + 1;
			if((i->height_right - i->height_left) > 1){
				//rotate
				if(n.value < i->right->value)
					right_left_rotation(i);
				else
					left_rotation(i);
				avltree = i;
			}
		}
		return max(i->height_left, i->height_right);
	} else {
		avltree = &n;
		return 0;
	}
}

void left_rotation(Node* &root){
	root->height_right = root->right->height_left;
	root->right->height_left = max(root->height_left, root->height_right)+1;

	Node* tmp = root->right;
	root->right = root->right->left;
	tmp->left = root;
	root = tmp;
}
void right_rotation(Node* &root){
	root->height_left = root->left->height_right;
	root->left->height_right = max(root->height_right, root->height_left)+1;

	Node* tmp = root->left;
	root->left = root->left->right;
	tmp->right = root;
	root = tmp;
}
void left_right_rotation(Node* &root){
	left_rotation(root->left);
	right_rotation(root);
}
void right_left_rotation(Node* &root){
	right_rotation(root->right);
	left_rotation(root);
}

void traverse(Node *n) {
	if(n != NULL) {
		cout << "Node: " << n->value << endl;
		traverse(n->left);
		traverse(n->right);
	}
}