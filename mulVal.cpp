#include "hw09.h"

LargeInt LargeInt::operator*(LargeInt &input){

	int i;
	int j;
	
	LargeInt fac(input); // Copy construct to factor 

	/*
	* Going to continously add partial to prod.
	* In all actuality, prod is a sum of partial prods.
	*/

	LargeInt prod;	

	int count = 0;

		/** format is 
		 j
		*i
		---
		partial
		*/

		/* i */
		for(fac.node = fac.last; fac.node; fac.node = fac.node->prev)
		{
			count++;	
			// construct and destruct part each iteration of
			// outer for loop

			LargeInt part;

			// give i a value for arithmetic
			i = fac.node->val;
			
			// There is no carry to begin 
			int carry = 0;

			/* j */
			for(node = last; node; node = node->prev)
			{
				
				// give j a value for arithmetic
				j = node->val;
				
				// If the value is 10, it cant be stored into 
				// an individual node, thus we will carry.
				if(((i * j) + carry) > 9)
				{
					// if value is 43, 3 is read into part val	
					part.node->val = (i * j + carry/* * 10)*/) % 10; 
					carry = ((i * j) + carry) / 10;		
				}

				else // If its not greater > 9, which means
				{    // do NOT create a carry.
					
					// read in val to partial
					part.node->val = ((i * j) + carry);
					
					// if no carry was created, it must be 0
					carry = 0;
				}

					if(node->prev)
					{	// If there is more multiplication to be done.
						part.addToFront(0);
						continue;
					}

					else 
					{ // If there is no more multiplication
						if(carry != 0)
						{
							// If carry contains a value read it into
							// the final node. Break.
							part.addToFront(carry);
						}

					    else
						{
						// No multiplication, no carry. 
							break;
						}
					}
				}	
			
				if(count > 1)
				{

					// For all partial products
					for(int i = 1; i < count; i++)
					{ // This will append count-1 0s.
						part.addZeros();
					}

					// Keep the sum of prod going
					prod = prod + part;
				}

				else
				{
					prod = part;
				}
				part.~LargeInt();
			}	

	if((input.sign == '-') ^ (this->sign == '-')){
		prod.sign = '-';
		return prod;
	}

	return prod;
}
