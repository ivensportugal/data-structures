/*
 *  Implementation of a Queue using a cicular doubly-linked list
 *  Insertion: O(1)
 *  Removal  : O(1)
 */

#include <iostream>
using namespace std;

#define TEST 10

struct Data {
	int value;
	Data *prev;
	Data *next;
};

void  insert(Data **, Data *);
Data* remove(Data **);
void  traverse(Data **);

int main () {

	// Creating data for testing
	Data d[TEST];
	for(int i = 0; i < TEST; i++) {
		d[i].value = i*i*i;
		d[i].prev = NULL;
		d[i].next = NULL;
	}

	Data *queue = NULL;

	//insertion
	for(int i = 0; i < TEST; i++)
		insert(&queue, &d[i]);

	traverse(&queue);

	//removing
	for(int i = 0; i < TEST>>1; i++)
		remove(&queue);

	traverse(&queue);
	
	return 0;
}

void insert(Data **queue, Data *data) {
	if(*queue != NULL) {
		data->prev    = (*queue)->prev;
		data->next    = *queue;
		(*queue)->prev->next = data;
		(*queue)->prev = data;
	}
	else {
		data->prev = data;
		data->next = data;
	}
	*queue = data;
}

Data* remove(Data **queue) {
	if((*queue)->next == *queue) {
		Data *del = *queue;
		*queue = NULL;
		return del;
	}
	else if(*queue != NULL) {
		Data *del = (*queue)->prev;
		(*queue)->prev->prev->next = *queue;
		(*queue)->prev = (*queue)->prev->prev;
		del->prev = NULL;
		del->next = NULL;
		return del;
	}

}

void traverse(Data **queue) {
	if(*queue != NULL) {
		Data *start = *queue;
		Data *itr   = *queue;
		do {
			cout << "Element: " << itr->value << endl;
			itr = itr->next;
		} while(itr != start);
	}
}