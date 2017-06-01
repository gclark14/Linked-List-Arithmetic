#include "hw09.h"

string LargeInt::getVal(){
    
    if(!first){
        return "No list exists";
    }
    
    string val = "";
    node = first;
	string sign;	
    sign += this->sign;
    /* 
     * To convert to string, concatenate the char of each node's int
     * into a string.
     */
    for (node = first; node; node = node->next){
        char temp = node->val + 48;
        val += temp;
    } node = last;
    //concatenate the list of numbers and the sign
    val = sign + val;
    return val;
}
