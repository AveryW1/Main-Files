// Contains print, parse, and remove functions definitions
//  roster.cpp
//  C867app
//
//  Created by Avery Washington on 9/4/20.
//  Copyright © 2020 General Cloud Applications LLC. All rights reserved.
//

#include "roster.h"

// Takes the studentData and seperates the long strings. Testins -8 in degree program to check for solutions to identifiying degree type.
void Roster::parse(string studentData) {
    DegreeProgram dp = UNDECIDED;
    if (studentData.back() == 'K') dp = NETWORK;
    else if (studentData.back() == 'E') dp = SOFTWARE;
    else if (studentData.back() == 'Y') dp = SECURITY;
    
    int rightSide = (int)studentData.find(",");
    string stuID = studentData.substr(0, rightSide);
    
    int leftSide = rightSide + 1;
    rightSide = (int)studentData.find(",", leftSide);
    string fstnm = studentData.substr(leftSide, rightSide - leftSide);
    
    leftSide = rightSide + 1;
    rightSide = (int)studentData.find(",", leftSide);
    string lstnm = studentData.substr(leftSide, rightSide - leftSide);
    
    leftSide = rightSide + 1;
    rightSide = (int)studentData.find(",", leftSide);
    string ema = studentData.substr(leftSide, rightSide - leftSide);
    
    leftSide = rightSide + 1;
    rightSide = (int)studentData.find(",", leftSide);
    string age = studentData.substr(leftSide, rightSide - leftSide);
    
    leftSide = rightSide + 1;
    rightSide = (int)studentData.find(",", leftSide);
    int d1 = stod(studentData.substr(leftSide, rightSide - leftSide));
    leftSide = rightSide + 1;
    
    leftSide = rightSide + 1;
    rightSide = (int)studentData.find(",", leftSide);
    int d2 = stod(studentData.substr(leftSide, rightSide - leftSide));
    leftSide = rightSide + 1;
    
    leftSide = rightSide + 1;
    rightSide = (int)studentData.find(",", leftSide);
    int d3 = stod(studentData.substr(leftSide, rightSide - leftSide));
 
    add(stuID, fstnm, lstnm, ema, age, d1, d2, d3, dp);
    
}
// This method creates the student object and adds it to the classRosterArray.
void Roster::add(string studentID, string firstName, string lastName, string email, string currentAge, int daysComplete1, int daysComplete2, int daysComplete3, DegreeProgram dp){
    int darray[3] = {daysComplete1, daysComplete2, daysComplete3};
    classRosterArray[++lastStudent] = new Student(studentID, firstName, lastName, email, currentAge, darray, dp);
}

// Displays all data using Accessors and displays strings instead of ints for our DegreeProgram enumeration.
void Roster::printAll(){
    Student::printHeader();
    for (int i = 0; i <= Roster::lastStudent; i++){
        cout << classRosterArray[i]->getStudentID() << '\t';
        cout << classRosterArray[i]->getFirstName() << '\t';
        cout << classRosterArray[i]->getLastName() << '\t';
        cout << classRosterArray[i]->getEmail() << '\t';
        cout << classRosterArray[i]->getCurrentAge() << '\t';
        cout << classRosterArray[i]->getDaysComplete()[0] << '\t';
        cout << classRosterArray[i]->getDaysComplete()[1] << '\t';
        cout << classRosterArray[i]->getDaysComplete()[2] << '\t';
        cout << degreeProgramStrings[classRosterArray[i]->getDegreeProgram()] << '\t';
        cout << endl;
    }
}

// Print by Degree Programs
void Roster::printByDegreeProgram(DegreeProgram dp){
    Student::printHeader();
    for (int i = 0; i <= Roster::lastStudent; i++) {
        if (Roster::classRosterArray[i]->getDegreeProgram() == dp) {
            classRosterArray[i]->print();
        }
    }
    cout << endl;
}

// Prints invalid email addresses. Checks for no spaces and presence of '.' and '@'.
void Roster::printInvalidEmails() {
    bool anyBad = false;
    for (int i = 0; i <=Roster::lastStudent; i++) {
        string stEmail = (classRosterArray[i]->getEmail());
        if (stEmail.find('@') == string::npos || stEmail.find('.') == string::npos){ // Sets emails to 'anyBad == true' if they do not contain @ or . and no " ".
            anyBad = true;
            cout << stEmail << " : " << classRosterArray[i]->getFirstName() << ' ' << classRosterArray[i]->getLastName() << endl;
        }
        if ((!(stEmail.find(' ') == string::npos))){
                       cout << stEmail << " : " << classRosterArray[i]->getFirstName() << ' ' << classRosterArray[i]->getLastName() << endl;
                   }
    }
     if (!anyBad) cout << "NONE" << endl; // Ask if opposite of andBad.
}

// Simple average calculation for days complete. Must use a double as divisor to keep the answer as a double. Else it will drop the fraction as an int. Once student is found, loop breaks.
void Roster::printAverageDaysInCourse(string studentID){
    for (int i = 0; i <= lastStudent; i++){
        if (this->classRosterArray[i]->getStudentID() == studentID) {
            cout << studentID << ": ";
            cout << (classRosterArray[i]->getDaysComplete()[0] + classRosterArray[i]->getDaysComplete()[1] + classRosterArray[i]->getDaysComplete()[2])/3.0 << endl;
            cout << endl;
            break;
        }
        else {
            cout << "Student not found." << endl;
        }
        cout << endl;
    }
}


// Student removal function. Success determines whether or not studentID is found and will
void Roster::remove(string studentID){
    bool success = false;
    for (int i = 0; i <= Roster::lastStudent; i++){
        if (classRosterArray[i]->getStudentID() == studentID){
            success = true;
            if (i < numStudents - 1){
                Student* temp = classRosterArray[i]; // IMPORTANT: Swaps with last student to ensure that you can delete the last entry.
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            Roster::lastStudent--; // This marks last entry as invisible(essentially)! Reduces last index by one which will make the last entry not avaliable.
        }
    }
    if (success){
        cout << studentID << " removed from roster." << endl << endl;
    }
    else cout << studentID << " not found." << endl << endl;
}

// Destructor(Garbo-Man! Will delete data marked unavaliable by remove function. Output for destructors isn't needed.
Roster::~Roster(){
    cout << "Garbo-Man the DESTRUCTOR has been called!" << endl << endl;
    for (int i = 0; i < numStudents; i++){
        cout << "Eliminating student " << i+1 << endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr; // Used to prevent crashes when attempts to call that pointer.
    }
}
