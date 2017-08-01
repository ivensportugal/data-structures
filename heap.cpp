/*
 *  Implementation of a Heap
 *  Insertion: O(log n)
 *  Removal  : O(log n)
 *  Search   : O(n)
 *  Max/Min  : O(1)
 */

#include <iostream>
using namespace std;

#define SIZE 10

void insert(int*, int &, int);
void remove(int*, int &);
int search(int*, int, int);
int peak(int*);

int main (void) {

	int max_heap[SIZE];
	int heap_size = 0;

	for(int i = 0; i < SIZE; i++)
		insert(max_heap, heap_size, i);

	for(int i = 0; i < SIZE; i++)
		cout << max_heap[i] << "-";	
	cout << endl;

	cout << "location of element 8: " << search(max_heap, heap_size, 8) << endl;
	cout << "max element: " << peak(max_heap) << endl;

	return 0;
}

void insert(int* heap, int &size, int n) {
	int pos = size;
	heap[size++] = n;
	int parent = (size >> 1) -1;
	while(pos > 0 && heap[pos] > heap[parent]) {
		heap[pos]    ^= heap[parent];
		heap[parent] ^= heap[pos]   ;
		heap[pos]    ^= heap[parent];

		pos = parent;
		parent = ((pos+1) >> 1) -1;
	}
}

void remove(int* heap, int &size) {
	heap[0] = heap[--size];
}

int search(int* heap, int heap_size, int n) {
	int stack[SIZE/2];
	int top = 0;
	int i, left, right;

	stack[top++] = 0;
	while(top > 0) {
		i = stack[--top];
		if(heap[i] == n) return i;
		left  = ((i+1)<<1)-1;
		right = ((i+1)<<1)-0;
		if(left  < heap_size) stack[top++] = left ;
		if(right < heap_size) stack[top++] = right;
	}
}

int peak(int* heap) {
	return heap[0];
}