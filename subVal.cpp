#include "hw09.h"

LargeInt LargeInt::operator-(LargeInt &input){

	/** Handles subtraction of -999 - 2 */	
	if(sign == '-' and input.sign == '+')
	{
		input.sign == '+';
		sign = '+';
		LargeInt sum = (*this) + input;
		sum.sign = '-';
		return sum;
	}
	
	/** Handles 4 - 10 */
	if(sign == '+' and input.sign == '+')
	{
		if(this->compareTo(input) == -1)
		{
			LargeInt dif = input - (*this);
			dif.sign = '-';
			return dif;
		}
	}

	/** 3 - - 5 */	
	if(sign == '+' and input.sign == '-'){
		input.sign = '+';
		LargeInt sum = (*this) + input;
		return sum;
	}

	if(sign == '-' and input.sign == '-')
	{
		if(compareTo(input) == 1 or compareTo(input) == 0)
		{
			input.sign = '+';
			sign = '+';
			LargeInt dif = input - (*this);
			return dif;
		}
	}
	
	if(sign == '-' and input.sign == '-')
	{
		if(compareTo(input) == -1)
		{
			input.sign = '+';
			sign = '+';
			LargeInt dif = (*this) - input;
			dif.sign = '-';
			return dif;
		}
	}

	int i;
	int j;
	const int ONE = 1;
	const int TEN = 10;
	LargeInt sub(input); 
	LargeInt dif;

	/** Make sure lists are of equal length */
	int result = this->compareTo(sub);

	// the and has been added
	if(getLength() > sub.getLength()/*or result == 0*/){
		/** If result == 1, give sub 0s */
		sub.node = sub.last;
		sub.tail = sub.node;
		sub.tail->next = NULL;
		node = last;
		
		do
		{
			if(sub.node->prev){
				sub.node = sub.node->prev;
				sub.tail = sub.node;
				node = node->prev;
				continue;
			}

			else 
			{
			/*
			 * Create a new node with a value of 0
			 * Redirect pointers
			 */
				sub.addToFront(0);
				node = node->prev;
			}
		} while(node->prev);
	}	
	
	if(result == 1 or result == 0) // sub is subtracted by this
	{

		for(node = last, sub.node = sub.last;
			node;
			node = node->prev, sub.node = sub.node->prev)
		{
			i = node->val;
			j = sub.node->val;
			
			if(i < j)// If sub has to borrow as in 3-9.
			{ 
				i += TEN; // Borrow
				entry* search = node->prev;

				/* Begin ghetto recursion */
				if (search->val == 0){ 
					do // search for a non 0 value.
					{
						search = search->prev;
					} while(search->val == 0);
					// borrow once a value has been found
					search->val -= ONE;  						
					
					if (search == first) 
					{ // This loop occurs for cases such as 1000000 - 2
						while(search->next != node)
						{
							search = search->next;
							search->val = 9;
						}
					}
				}
				else
				{ // If i can borrow as in 133-8 the second 3 gets borrowed
					search->val -= 1;
				}
				dif.node->val = i-j;
			} // if i < j
			else
			{ // if i > j, just subtract.
				dif.node->val = i-j;
			}
			
			/** Basic list linkage */
			if(node->prev != NULL)
			{ 
				dif.addToFront(0);	
			}
		} // for
	}

	// Get rid of leading 0s
	dif.trim();

	return dif;
}
