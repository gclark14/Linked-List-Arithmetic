#include "hw09.h"

void LargeInt::addZeros(){
	if(!first) 
		return;
	
	// go to the end 
	node = last;
	tail = last;	
	// append 0

	node = new entry;
	node->val = 0;
	node->prev = tail;
	tail->next = node;
	node->next = NULL;
	tail = node;
	last = node;
}
