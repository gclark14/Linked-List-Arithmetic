
#include "hw09.h"

int LargeInt::compareTo(LargeInt& two){
    /*
     * Runnin like a doozy
     * > return 1
     * < return -1
     * = return 0
     */
   
	// Recall, these compare lengths and signs.
    // 10 > -2 and 10 > 2
    if(getLength() > two.getLength() and sign == '+'){
        return 1;
    }
	
	// -10 > -2
    else if(getLength() > two.getLength() and sign == '-' and two.sign == '-'){
        return -1;
    }
	
	// 2 < 10 
    else if(getLength() < two.getLength() and sign == '+' and two.sign == '+'){
        return -1;
    } 

	// 2 < -10
	else if(getLength() < two.getLength() and sign == '+' and two.sign == '-'){
		return 1;
	}

	// -2 < -10
    else if(getLength() < two.getLength() and sign == '-' and two.sign == '-'){
		return 1;
	}

	// -2 < 10
	else if(getLength() < two.getLength() and sign == '-' and two.sign == '+'){
		return -1;
	}
    
    else 
    {
    
		for(node = first, two.node = two.first;
			node;
			node = node->next, two.node = two.node->next)
		{
			// 5 > 2 and 5 > -2
			if(node->val > two.node->val and sign == '+'){
				return 1;
			}
			
			// 3 < 4
			if(node->val < two.node->val and sign == '+' and two.sign == '+'){
				return -1;
			}

			// 3 > -4
			if(node->val < two.node->val and sign == '+' and two.sign == '-'){
				return 1;
			}
	
			// -4 > 2
			else if(node->val > two.node->val and sign == '-' and two.sign == '+'){
				return -1;
			}

			// -5 > -2 
			else if(node->val > two.node->val and sign == '-' and two.sign == '-'){
				return -1;
			}

			// -2 < -5
			else if(node->val < two.node->val and sign == '-' and two.sign == '-'){
				return 1;
			}

			// -2 < 5
			else if(node->val < two.node->val and sign == '-' and two.sign == '+'){
				return -1;
			}

			else 
				continue;
		}
		return 0;
	}
}
