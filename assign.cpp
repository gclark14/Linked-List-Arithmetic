#include "hw09.h"

const LargeInt& LargeInt::operator=(const LargeInt& input){
	if(this != &input)
	{
		/*
		* For an explanation of this method consult copy constructor 
		* source code.
		*/

		(*this).~LargeInt();	
		sign = input.sign;
		node = new entry;
		first = node;
		last = node;
		tail = node;
		node->prev = NULL;
		entry* iter;
		for(iter = input.first; iter; iter = iter->next){
			
			node->val = iter->val;
			
			if(iter->next != NULL){
				node = new entry;
				tail->next = node;
				node->prev = tail;
				tail = node;
				last = node;
			}
		}
		node->next = NULL;	
	}
	return *this;
}
