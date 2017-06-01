#include "hw09.h"

void LargeInt::findSign(){

	if(first->val != -3 or first->val != -5){
		entry* iter = first->next;
		sign = first->val + 48;
		first->prev = NULL;
		first->next = NULL;
		iter->prev = NULL;
		length--;
		delete first;
		first = tail = node = iter;
	}
}
