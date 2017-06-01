#include "hw09.h"

void LargeInt::trim(){

	/** If no list */
	if(!first) 
		return;

	entry* iter;
	iter = first; 
	node = first;
	node = node->next;
	
	for(node = first->next; node; node = node->next){
		if(iter->val == 0)
		{
			iter->next = NULL;
			iter->prev = NULL;
			node->prev = NULL;
			delete iter;
			iter = node;
			first = iter;
		}
		else 
			return;
	}	

}
