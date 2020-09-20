// Contains all get and set function definitions
//  student.cpp
//  C867app
//
//  Created by Avery Washington on 9/4/20.
//  Copyright © 2020 General Cloud Applications LLC. All rights reserved.
//

#include "roster.h"


// Parameterless constructor set ot default values. Prevents potitential crashing if somehow called during program execution.
Student::Student(){
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->currentAge = "";
    this->degreeProgram = DegreeProgram::UNDECIDED;
    
    // This 'for' statement sets each value in the array to zero.
    for (int i = 0; i < SIZE; i++) this->daysComplete[i] = 0;
}

// Full Constructor
Student::Student(string studentID,
                 string firstName,
                 string lastName,
                 string emailAddress,
                 string currentAge,
                 int daysComplete[],
                 DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->currentAge = currentAge;
    this->degreeProgram = degreeProgram;
    
    for (int i = 0; i <SIZE; i++) this->daysComplete[i] = daysComplete[i];
}

// Destructor. Doesn't do anything
Student::~Student(){}


// Getters definitions
string Student::getStudentID(){
    return this->studentID;
}

string Student::getFirstName() {
    return this->firstName;
}

string Student::getLastName() {
    return this->lastName;
}

string Student::getEmail() {
    return this->emailAddress;
}

string Student::getCurrentAge() {
    return this->currentAge;
}

int* Student::getDaysComplete() {
    return this->daysComplete;
}

DegreeProgram Student::getDegreeProgram() {
    return this->degreeProgram;
}

void Student::setStudentId(string studentID) {
    this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(string lastName) {
    this->lastName = lastName;
}

void Student::setEmail(string emailAddress) {
    this->emailAddress = emailAddress;
}

void Student::setCurrentAge(string currentAge) {
    this->currentAge = currentAge;
}

void Student::setDaysComplete(int daysComplete[]) {
    for (int i =0; i <SIZE; i++) this->daysComplete[i] = daysComplete[i];
}

void Student::setDegreeProgram(DegreeProgram degreeProgram){
    this->degreeProgram = degreeProgram;
}

// Using this header method is optional. Will allow some clarity to user when a student's data is pulled.
void Student::printHeader() {
    cout << "Output format: StudentID|FirstName|LastName|Email|Age|DaysComplete|Degree" << endl;
}

/* This print function will seperate the return values of Getters with a tab spacing. The array is pulled one at a time.
 Degree program uses the parallel array of strings created in degree.h to give an understandable value to the degree enumeration's output when used instead of a 0,1,2,3. */
void Student::print() {
    cout << this->getStudentID() << '\t';
    cout << this->getFirstName() << '\t';
    cout << this->getLastName() << '\t';
    cout << this->getEmail() << '\t';
    cout << this->getCurrentAge() << '\t';
    cout << this->getDaysComplete()[0] << '\t';
    cout << this->getDaysComplete()[1] << '\t';
    cout << this->getDaysComplete()[2] << '\t';
    cout << degreeProgramStrings[this->getDegreeProgram()] << endl;
}
