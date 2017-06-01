#include "hw09.h"

void LargeInt::setVal(string input){
	
	/** Delete it */
	this->~LargeInt();
	
	/** Create temp */
	LargeInt translate(input);
	
	/** Copy construct it */
	*this = translate;
}
