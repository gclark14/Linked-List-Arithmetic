#include "hw09.h"

/** Creates a new node at the front of the list 
* with a specified value.
*/

void LargeInt::addToFront(int a){
	node = new entry;
	node->val = a;
	length++;
	node->prev = NULL;
	node->next = tail;
	tail->prev = node;
	first = tail = node;	
}

