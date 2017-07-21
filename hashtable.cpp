/*
 *  Implementation of a Hash Table
 *  Insertion (worst case): O(n)
 *  Removel   (worst case): O(n)
 *  Search    (worst case): O(n)
 */

#include <iostream>
using namespace std;

#define HASH_SIZE 20

struct Node {
	int key;
	int value;
};

void insert(Node* , Node &);
void remove(Node* , int);
Node search(Node* , int);
int calculate_hash(int);
void print(Node* );

int main () {

	Node hashtable[HASH_SIZE];
	Node n[HASH_SIZE]; //for tests

	// initiation
	for(int i = 0; i < HASH_SIZE; i++)
		hashtable[i].key = -1;

	// insertion
	for(int i = 0; i < HASH_SIZE; i++) {
		n[i].key   = i*i;
		n[i].value = i*i;
		insert(hashtable, n[i]);
	}

	// removal
	for(int i = 0; i < HASH_SIZE/2; i++)
		remove(hashtable, i*i);

	print(hashtable);

	return 0;
}

void insert(Node* hashtable, Node &n){
	Node s = search(hashtable, n.key);
	if(s.key == -1){
		int hash = calculate_hash(n.key);
		if(hashtable[hash].key == -1) hashtable[hash] = n;
		else {
			for(int i = hash+1; i != hash; i= ++i % HASH_SIZE)
				if(hashtable[i].key == -1){
					hashtable[i] = n;
					break;
				}
		}
	}
}

void remove(Node* hashtable, int key) {
	int hash = calculate_hash(key);
	if(key == hashtable[hash].key) hashtable[hash].key = -1;
	else {
		for(int i = hash+1; i != hash; i = ++i % HASH_SIZE)
			if(key == hashtable[i].key){
				hashtable[i].key = -1;
				break;
			}
	}
}

Node search(Node* hashtable, int key) {
	int hash = calculate_hash(key);
	if(key == hashtable[hash].key) return hashtable[hash];
	else{
		for(int i = hash+1; i != hash; i = ++i % HASH_SIZE)
			if(key == hashtable[i].key) return hashtable[i];
		Node a;
		a.key = -1;
		return a;
	}
}

int calculate_hash(int key) {
	return key % HASH_SIZE;
}

void print(Node* hashtable) {
	for(int i = 0; i < HASH_SIZE; i++)
		cout << "hashtable[" << i << "]: " << hashtable[i].key << " - " << hashtable[i].value << endl;
}