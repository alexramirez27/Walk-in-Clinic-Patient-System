/*
 * walkIn.cpp
 * 
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified. 
 *
 * Author: Alex Ramirez
 * Date: February 4, 2022
 */


#include "List.h"
#include "Patient.h"


int main() {

    cout << "----- Walk-in Clinic Patient System" << endl << endl;

    cout << "To enter a new patient into the system                            enter: n" << endl;
    cout << "To remove a patient from the system                               enter: r" << endl;
    cout << "To search for an existing patient                                 enter: s" << endl;
    cout << "To modify a patient's record                                      enter: m" << endl;
    cout << "To print all patients by descending order of care card numbers    enter: p" << endl;
    cout << "To exit                                                           enter: x" << endl << endl;
    
    List newList = List();

    bool condition = true;

    while ( condition ) {
      cout << "Your choice: ";
      char choice;
      cin >> choice; 
      cout << endl;

      if ( choice == 'x' )
        condition = false;

      if ( choice == 'n' ) {
        string newCard;
        cout << "Enter patient care card: ";
        cin >> newCard;
        Patient newPatient = Patient(newCard);
        newList.insert(newPatient);

        cout << endl;
      }

      if ( choice == 'r' ) {
        string newRemoval;
        cout << "Enter care car number of patient to be removed: ";
        cin >> newRemoval;
        Patient* found = newList.search(newRemoval);
        
        if ( found != NULL )
          newList.remove(*found);
        else
          cout << "Patient not in the system" << endl;
      }

      if ( choice == 's' ) {
        string newSearch;
        cout << "Enter care card number of patient to search in the system" << endl;
        cin >> newSearch;
        Patient* ret = newList.search(newSearch);

        if ( ret != NULL )
          cout << "Patient in the system" << endl;
        else
          cout << "Patient not in the system" << endl;
      }

      if ( choice == 'm' ) {
        
        string patientChosen;
        cout << "Enter patient's care card number: ";
        cin >> patientChosen;
        cout << endl;

        Patient* actualPatient = newList.search(patientChosen);
        
        cout << "Patient's Information to modify:" << endl << endl;
        cout << "To modify patient's name        enter: na" << endl;
        cout << "To modify patient's address     enter: ad" << endl;
        cout << "To modify patient's phone       enter: ph" << endl;
        cout << "To modify patient's email       enter: em" << endl;
        cout << "To exit                         enter: ex" << endl;
        cout << endl;

        bool newCondition = true;
        string modification;
        while ( newCondition ) {
          cout << "Your choice: ";
          cin >> modification;
          cin.ignore();
          cout << endl;
          
          if ( modification == "ex" )
            newCondition = false;

          else if ( modification == "na" ) {
            string newName;
            cout << "Enter new name: ";
            getline(cin, newName);
            actualPatient->setName(newName);
            cout << endl;
          }

          else if ( modification == "ad" ) {
            string newAddress;
            cout << "Enter new address: ";
            getline(cin, newAddress);
            actualPatient->setAddress(newAddress);
            cout << endl;
          }

          else if ( modification == "ph" ) {
            string newPhone;
            cout << "Enter new phone number: ";
            getline(cin, newPhone);
            actualPatient->setPhone(newPhone);
            cout << endl;
          }

          else if ( modification == "em" ) {
            string newEm;
            cout << "Enter new email: ";
            getline(cin, newEm);
            actualPatient->setEmail(newEm);
            cout << endl;
          }
        } // end of nested while loop
      } // end of modification option

      if ( choice == 'p' ) {
        newList.printList();
      }

    } // end of main while loop

    return 0;
}

