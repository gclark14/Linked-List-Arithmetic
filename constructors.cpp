#include "hw09.h"
LargeInt::LargeInt(){

	length = 0;
	node = new entry;
	length++;
	first = node;
	last = node;
	tail = node;
	tail->next = NULL;
	tail->prev = NULL;
	sign = '+';	
} // Point everything to null in this constructor.


LargeInt::LargeInt(string input){
    length = 0;
    node = new entry;
    length++;
    first = node;// Set both ends of the list to be node.
    last = node;
    tail = node;
    node->prev = NULL;
   
	// Transferring data from the string linked list to my own linked list.
    for(unsigned int i = 0;i < input.length();i++){
        node->val = input.at(i) - 48; // Char by char
        if(i < input.length()-1){
            node = new entry;
            length++;
            tail->next = node;
            node->prev = tail;
            tail = node;
            last = node;
        }
    }
    node->next = NULL;// Once it ends update the last next to point to null.
    findSign();
}

LargeInt::LargeInt(const LargeInt& original){

	sign = original.sign; 
	//findSign(); 
    /** Pointers for my new list*/
    length = 0;
    node = new entry;
    length++;
    first = node;// Set both ends of the list to be node.
    last = node;
    tail = node;
    /*
     * Copy the argument list to new list
     * This creation and copy mechanism will be implemented by addVal()  
     * To allow this constructor to compile with const on my original variable
     * I need to create a pointer that acts on it.
     */
    node->prev = NULL;
    entry *iter;
    for(iter = original.first; iter; iter = iter->next){
        node->val = iter->val;
        
        if(iter->next != NULL){
            node = new entry;
            length++;
            tail->next = node;
            node->prev = tail;
            tail = node;
            last = node;
        }
    }
    node->next = NULL;
}

LargeInt::~LargeInt(){
    if(!first) 
        return;
    /** Deleting the list, those are the only pointers the class holds */
    entry* iter;
    
    iter = first;
    node = first;
    node = node->next;
    if (iter->next){ /** If the list is multiple elements long */
        /* iter is going to be one behind node */
        for(node = first->next; node; node = node->next) {
            iter->next = NULL;
            iter->prev = NULL;
            node->prev = NULL;
            delete iter;
            iter = NULL;
            iter = node;
        } delete iter;
    } else {
        /** If the list is only one node long delete this way */
        iter->next = NULL;
        iter->prev = NULL;
        delete iter;
        iter = NULL;
    }
    
    /** Make sure EVERYTHING is pointing to NULL */
    first = last = tail = node = NULL;
}
