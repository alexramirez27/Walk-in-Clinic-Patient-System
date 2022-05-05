/*
 * List.cpp
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - (For you to fill: Add the other invariant(s) of this List class.)
 *
 * Author: Alex Ramirez
 * Date: February 4, 2022
 */

#include <iostream>
#include <string>
#include "List.h"


List::List() {
    arr = new Patient[INITIAL_CAPACITY];
    elementCount = 0;
    capacity = INITIAL_CAPACITY;    
  }

List::~List() {
  delete [] arr;
}

// Description: Compare two strings to see if they're the same
    //              Returns true if they're the same,
    //              otherwise, returns false
  bool List::cmpStr ( string a, string b ) {

    bool condition = true;
    int counter = 0;

    while ( condition ) {
      if ( a[counter] != b[counter])
        return false;
      counter++;
    }

    return true;
  }

// Description: Returns the total element count currently stored in List.
	int List::getElementCount() const {
    return elementCount;
  }

	// Description: Insert an element.
	// Precondition: newElement must not already be in data collection.  
	// Postcondition: newElement inserted and elementCount has been incremented.   
	bool List::insert(const Patient& newElement) {
    
    Patient* newArr;

    // Array is full, increase its size by two
    if ( elementCount == INITIAL_CAPACITY ) {
      capacity = capacity * 2;
      newArr = new Patient[capacity];
    
      for ( int i = 0; i < elementCount; i++ ) {
        newArr[i] = arr[i];
      }

      delete(arr);

      arr = newArr;

      // See if element is already in the array
      for ( int i = 0; i < elementCount; i++ ) {
        if ( arr[i].getCareCard() == newElement.getCareCard() )
          return false;
      }

      arr[elementCount] = newElement;
      elementCount++;
      return true;
    }

    else {
      for ( int i = 0; i < elementCount; i++ ) {
        if ( arr[i].getCareCard() == newElement.getCareCard() )
          return false;
      }

      arr[elementCount] = newElement;
      elementCount++;

      return true;
    }
  }

	// Description: Remove an element. 
	// Postcondition: toBeRemoved is removed and elementCount has been decremented.	
	bool List::remove( const Patient& toBeRemoved ) { 
	  
    bool elementFound = false;
    bool lastElement = false;

    for( int i = 0; i < elementCount; i++ ) {
      cout << elementCount << endl;
      if ( elementCount == 0 ) {
        return true;
      }
      
      if ( i == elementCount - 1 ) {
        lastElement = true;
      }
      
      if ( arr[i].getCareCard() == toBeRemoved.getCareCard() ) {
        elementFound = true;
      }
        
      if ( ( elementFound == true ) && ( i != elementCount - 1 ) ) {
        arr[i] = arr[i + 1];
      }
      
      if ( elementFound == true && lastElement == true ) {
        elementCount--;
      }
    }

    return 0;
  }
	
	// Description: Remove all elements.
	void List::removeAll() {
    for ( int i = elementCount - 1; i >= 0; i-- )
      elementCount--;
  }
   
	// Description: Search for target element.
	//              Returns a pointer to the element if found,
	//              otherwise, returns NULL.
	Patient* List::search(const Patient& target) {

    Patient* ret;

    for ( int i = 0; i < elementCount; i++ ) {
      if ( arr[i].getCareCard() == target.getCareCard() ) {
        ret = arr + i;
        return ret;
      }
    }

    return NULL;
  }
	
  // Swap two Patients
  void swap(Patient* a, Patient* b) {
    Patient temp = *a;
    *a = *b;
    *b = temp;
  }

  // Rearrange
  int rearrange ( Patient arr[], int low, int high ) { 
    Patient pivot = arr[high]; //pivot
    int i = ( low - 1 );

    for ( int k = low; k <= high - 1; k++ ) {

      // If current element is smaller than or
      // equal to pivot
      if ( stol(arr[k].getCareCard()) <= stol(pivot.getCareCard()) ) {
        i++;
        swap(&arr[i], &arr[k]);
      }
    }
    swap( &arr[i + 1], &arr[high] );
    return ( i + 1 );
  }
  
  // Quick Sort
  void quickSort( Patient arr[], int low, int high ) {
    if ( low < high ) {
      int pi = rearrange(arr, low, high);

      quickSort( arr, low, pi - 1);
      quickSort( arr, pi + 1, high);
    }
  }

	// Description: Prints all elements stored in List by descending order of search key.
	void List::printList() {

    Patient* arrCopy = new Patient[elementCount];

    // fill up the arrays
    for ( int i = 0; i < elementCount; i++ ) {
      arrCopy[i] = arr[i];
    }

    // quick sort
    quickSort( arrCopy, 0, elementCount - 1 );

    for ( int i = 0; i < elementCount; i ++ ) {
      cout << arrCopy[i].getCareCard() << " - Patient: " << arrCopy[i].getName() << ", " << arrCopy[i].getAddress() << ", " << arrCopy[i].getPhone() << ", " << arrCopy[i].getEmail() << endl;
    }
    cout << endl;
    
  }

