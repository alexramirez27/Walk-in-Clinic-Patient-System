/*
 * Patient.cpp
 * 
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified. 
 *
 * Author: Alex Ramirez
 * Date: February 4, 2022
 */

// You can add #include statements if you wish.
#include <iostream>
#include <string>
#include "Patient.h"
#include "List.h"

// From Patient.h

// Default Constructor
// Description: Create a patient with a care card number of "0000000000". 
// Postcondition: All data members set to "To be entered", 
//                except the care card number which is set to "0000000000".       
Patient::Patient() {
  name = "To be entered";
  address = "To be entered";
  phone = "To be entered";
  email = "To be entered";
  careCard = "0000000000";
}

// Parameterized Constructor
// Description: Create a patient with the given care card number.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aCareCard) {
  name = "To be entered";
  address = "To be entered";
  phone = "To be entered";
  email = "To be entered";
  
  char index = aCareCard[0];
  int length = 0;

  while (index != '\0') { //loop until null character is found
    length++;
    index = aCareCard[length];
  }

  if ( length != 10 )
    careCard = "0000000000";
  else
    careCard = aCareCard;

}

// Parameterized Constructor
  // Description: Create a patient with the given care card number and name
  // Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
  //                All other data memebrs set to "To be entered".
Patient::Patient(string aCareCard, string aName) {
    name = aName;
    address = "To be entered";
    phone = "To be entered";
    email = "To be entered";
  
    char index = aCareCard[0];
    int length = 0;

    while (index != '\0') {
      length++;
      index = aCareCard[length];
    }

    if ( length != 10 )
      careCard = "0000000000";
    else
      careCard = aCareCard;

  }

  // Parameterized Constructor
  // Description: Create a patient with the given care card number, name, and phone
  // Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
  //                All other data memebrs set to "To be entered".
  Patient::Patient(string aCareCard, string aName, string aPhone) {
    name = aName;
    address = "To be entered";
    phone = aPhone;
    email = "To be entered";
  
    char index = aCareCard[0];
    int length = 0;

    while (index != '\0') {
      length++;
      index = aCareCard[length];
    }

    if ( length != 10 )
      careCard = "0000000000";
    else
      careCard = aCareCard;

  }

  // Parameterized Constructor
  // Description: Create a patient with the given care card number, name, phone, and email
  // Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
  //                All other data memebrs set to "To be entered".
  Patient::Patient(string aCareCard, string aName, string aPhone, string anEmail) {
    name = aName;
    address = "To be entered";
    phone = aPhone;
    email = anEmail;
  
    char index = aCareCard[0];
    int length = 0;

    while (index != '\0') {
      length++;
      index = aCareCard[length];
    }

    if ( length != 10 )
      careCard = "0000000000";
    else
      careCard = aCareCard;

  }

  // Parameterized Constructor
  // Description: Create a patient with the given care card number, name, phone, email, and address
  // Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
  //                All other data memebrs set to "To be entered".
  Patient::Patient(string aCareCard, string aName, string aPhone, string anEmail, string anAddress) {

    name = aName;
    address = anAddress;
    phone = aPhone;
    email = anEmail;
  
    char index = aCareCard[0];
    int length = 0;

    while (index != '\0') {
      length++;
      index = aCareCard[length];
    }

    if ( length != 10 )
      careCard = "0000000000";
    else
      careCard = aCareCard;

  }

// All other parameterized constructors -> You need to implement these methods.

// Getters and setters -> You need to implement these methods.

// Description: Returns patient's name.
	string Patient::getName() const {
    return name;
  }

	// Description: Returns patient's address.
	string Patient::getAddress() const {
    return address;
  }

	// Description: Returns patient's phone.
	string Patient::getPhone() const {
    return phone;
  }

	// Description: Returns patient's email.
	string Patient::getEmail() const {
    return email;
  }
	
	// Description: Returns patient's care card.
	string Patient::getCareCard() const {
    return careCard;
  }

	// Description: Sets the patient's name.
	void Patient::setName(const string aName) {
    name = aName;
  }

	// Description: Sets the patient's address.
	void Patient::setAddress(const string anAddress) {
    address = anAddress;
  }

	// Description: Sets the patient's phone.
	void Patient::setPhone(const string aPhone) {
    phone = aPhone;
  }

	// Description: Sets the patient's email.
	void Patient::setEmail(const string anEmail) {
    email = anEmail;
  }


// Overloaded Operators
// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same care card number.
bool Patient::operator == (const Patient & rhs) {
	
	// Compare both Patient objects
	return this->careCard == rhs.getCareCard();
	
} // end of operator ==

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is > the care card 
//              number of "rhs" Patient object
bool Patient::operator > (const Patient & rhs) {
	
	// Compare both Patient objects
	return this->careCard > rhs.getCareCard();
	
} // end of operator >

// Description: Less than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is < the care card 
//              number of "rhs" Patient object.
bool Patient::operator < (const Patient & rhs) {
	
	// Compare both Patient objects
	return this->careCard < rhs.getCareCard();
	
} // end of operator <

// For testing purposes!
// Description: Prints the content of "this".
ostream & operator<<(ostream & os, const Patient & p) {
	
	os << p.careCard << " - Patient: " << p.name << ", "
	   << p.address << ", " << p.phone << ", " << p.email << endl;  
	     
	return os;

} // end of operator<<

// end of Patient.cpp




