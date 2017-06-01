#include "hw09.h"

LargeInt LargeInt::operator+(LargeInt &input){
	/** Address handling a negative plus a positive */

	/** Handles addition in the form of -4 + 2 */
	if(sign == '-' and input.sign == '+'){
		this->sign = '+';
		if(this->compareTo(input) == -1){
			LargeInt dif = input - (*this);
			dif.sign = '+';
			return dif;
		}
		else 
		{
			LargeInt dif = (*this) - input;
			dif.sign = '-';
			return dif;
		}
	}

	if(sign == '+' and input.sign == '-'){
		if(compareTo(input) == 1){
			input.sign = '+';
			LargeInt dif = input - (*this);
			dif.sign = '-';
			return dif;
		}
	}



	/** Handles addition in the form of 2 + -4 */
	if(this->compareTo(input) == 0 and input.sign == '-' and sign == '+'){
		LargeInt dif("+0");
		return dif;
	}

	/** runs properly, will override the calling number */
    LargeInt addend(input);

    LargeInt sum; // Create a class to hold the results.

	/*
	 * If this > addend, fill addend with 0s to make addend of equal
	 * length to this.
	 */

	if(getLength() > addend.getLength()){ 
		/** start at the end */
		addend.node = addend.last;
		addend.tail = addend.node;
		addend.tail->next = NULL;
		node = last;
		do{

			/** if a node exists, continue */
			if(addend.node->prev){
				/** move this and addend(that) */
				addend.node = addend.node->prev;
				addend.tail = addend.node;
				node = node->prev;
				continue;
			} 

			else 
			{ /*
			   * create a new node with a value of 0 
			   * redirect pointers 
			   */
				addend.addToFront(0);
				node = node->prev;// careful with this
			}
		} while(this->node->prev);
	}

	else if (getLength() < addend.getLength()){
		/** Start at the end */
		node = last;
		tail = node;
		tail->next = NULL;
		addend.node = addend.last;
		do{
		
			/** If a node exists, continue */
			if(node->prev){
				/** Move this and addend(that) */
				node = node->prev;
				tail = node;
				addend.node = addend.node->prev;
				continue;
			} 

			else 
			{ /*
			   * Create a new node with a value of 0 
			   * Redirect pointers 
			   */
				this->addToFront(0);
				addend.node = addend.node->prev;// Careful with this
			}
		} while(addend.node->prev);
	}

    /** Assuming addend.length() == */
    for (addend.node = addend.last, this->node = this->last;
        addend.node; 
        addend.node = addend.node->prev, this->node = this->node->prev){
	
		/** Create temp variables to hold the values of nodes */	
		int a = this->node->val; // current 
		int b = addend.node->val; // argument 
				
		/** If statement to address carrying over */
		if((a + b) >= 10){
			if(addend.node->prev){
				const int CARRY = 1;
				entry* temp;	
				temp = addend.node->prev;
				temp->val += CARRY;	
				sum.node->val = (a + b) - 10;
			} 
			else 
			{ // addresses the case of 9 + 1 and no prev*
				/** else we've reached the end, make new, read into current, return*/
				sum.node->val = (a+b)-10;
				sum.addToFront(1);
				if(this->sign == '-' and addend.sign == '-'){
					sum.sign = '-';
					return sum;
				}
			}

		} 
		else 
		{
			sum.node->val = a + b;
		}

		/** Perform ordinary linkage */
		if(addend.node->prev != NULL){
			sum.addToFront(0);
		}  
	} // for 

	if(this->sign == '-' and addend.sign == '-'){
		sum.sign = '-';
		return sum;
	}

	return sum;
}
