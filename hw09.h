/* 
 * File:   hw09.h
 * Author: Gabriel
 *
 * Created on April 14, 2017, 3:17 PM
 */

#ifndef HW09_H
#define HW09_H
#include <iostream>
#include <string>
using namespace std;

class LargeInt{

private: 
    
    /** Entry is the struct to hold all integers for the LargeInt class */
    struct entry{ 
        int val;
        entry* next;
		entry* prev;
    };    
	
	int length; 

    /** The class will by default hold all necessary traversal pointers*/
    entry* node;
    entry* first;
    entry* last;
    entry* tail;
	
	// (+/-)
	char sign;	
	
	/*
	* Trim to remove unwanted 0s from arithmetic methods
	* as in 0001345 -> 1345
	*/
	void trim();
	
	void reverse();

	/** Creates a new empty node */
	//void addToFront();
	
	/** Creates a new node with value */ 
	void addToFront(int);
	
	/** Finds and sets the sign of the list (positive or negative */
	void findSign();

public:
    
    /** Set everything to NULL */
    LargeInt();
    
    /** Constructor receives string and translates it into a linked list*/
    LargeInt(string);
    
    /** Copy constructor*/
    LargeInt(const LargeInt&);

	/** Delete the list */
    ~LargeInt();
    
    /** Return the value of a LargeInt via string */
    string getVal();
   
    /** Just like the string class's get length*/
    int getLength();

    /** Compare the length of one list to another */
    int compareTo(LargeInt&);    

	/** Shows address of a LargeInt */
	void outputListAddress();

	/** Updates the value of a LargeInt */
	void setVal(string);

	/** Subtract two LargeInts, overloads '-' */
	LargeInt operator-(LargeInt&);
    
    /** Add two LargeInts, will overload '+' operator */
    LargeInt operator+(LargeInt&);
 
	/** Multiply two LargeInts, overloads '*' */
	LargeInt operator*(LargeInt&);

	/** Makes sure data doesnt get corrupted on assignment */
	const LargeInt& operator=(const LargeInt&);
	
	/** Append 0s */
	void addZeros();
	
	/** Interaction hidden in a menu */
	void menu();

};
#endif /* HW09_H */
