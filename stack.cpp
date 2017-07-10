/*
 * Implementation of a Stack with pointers.
 * Not fixed in size.
 * Using struct.
*/

#include <iostream>
using namespace std;

#define TEST 10

struct Data {
	int value;
	Data *below;
};

Data* push(Data*, Data*);
Data* pop (Data*);
void traverse(Data*);

int main () {

	Data d[TEST];
	Data *stack;

	// Creating data
	for(int i=0; i<TEST; i++) {
		d[i].value = i*i;
		d[i].below = NULL;
		stack = push(stack, &d[i]);
	}

	traverse(stack);

	return 0;
}

Data* push (Data *stack, Data *d) {
	if(stack != NULL)
		d->below = stack;
	return d;
}

Data* pop (Data *stack) {
	if(stack != NULL)
		stack = stack->below;
	return stack;
}

void traverse(Data *stack) {
	while(stack != NULL) {
		cout << "Element: " << stack->value << endl;
		stack = stack->below;
	}
}