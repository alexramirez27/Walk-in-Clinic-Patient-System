/*
 * List.h
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - (For you to fill: Add the other invariant(s) of this List class.)
 *
 * Author: Alex Ramirez
 * Date: February 4, 2022
 */

#pragma once

// You can add #include statements if you wish.
#include <string>
#include <stdbool.h>
#include "Patient.h"

using namespace std;


class List  {

private:
	const int INITIAL_CAPACITY = 100;   // constant INITIAL_CAPACITY
	Patient* arr;                      // Data structure of elements
	int elementCount;                  // Number of elements in the data structure
	int capacity;                      // Actual capacity of data structure   

public:
	// Default constructor
	List();

	// Destructor
	// Description: Destruct a List object, releasing heap-allocated memory.
	~List();

	// Description: Compare two strings to see if they're the same
  //              Returns true if they're the same,
  //              otherwise, returns false
  bool cmpStr( string a, string b );
  
  // Description: Returns the total element count currently stored in List.
	int getElementCount() const; 

	// Description: Insert an element.
	// Precondition: newElement must not already be in data collection.  
	// Postcondition: newElement inserted and elementCount has been incremented.   
	bool insert(const Patient& newElement); 

	// Description: Remove an element. 
	// Postcondition: toBeRemoved is removed and elementCount has been decremented.	
	bool remove( const Patient& toBeRemoved ); 
	
	// Description: Remove all elements.
	void removeAll(); 
   
	// Description: Search for target element.
	//              Returns a pointer to the element if found,
	//              otherwise, returns NULL.
	Patient* search(const Patient& target); 
	
	// Description: Prints all elements stored in List by descending order of search key.
	void printList(); 


}; // end List.h