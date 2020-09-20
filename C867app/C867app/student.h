//
//  student.h
//  C867app
//
//  Created by Avery Washington on 9/4/20.
//  Copyright © 2020 General Cloud Applications LLC. All rights reserved.
//

#pragma once
#include "degree.h"

// Declared class student and the associated functions and variables.

class Student {
public:
    /* Static constant for size of days complete array. Arrays must be constant. Had to be defined before usage below. */
    static const int SIZE = 4;
    
public:
    
    // Getters (Accessors)
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    string getCurrentAge();
    int* getDaysComplete();
    DegreeProgram getDegreeProgram();
    
    // Setters (Mutators)
    void setStudentId(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string emailAddress);
    void setCurrentAge(string currentAge);
    void setDaysComplete(int daysComplete[]);
    void setDegreeProgram(DegreeProgram degreeProgram);
    
    // Constructors (Includes parameterless and full (Contains all parameters used in Student class.) and destructor (~).
    Student();
    Student(
        string studentID,
        string firstName,
        string lastName,
        string emailAddress,
        string currentAge,
        int daysComplete[],
        DegreeProgram degreeProgram);
    ~Student();
    
    // Creates header for displaying Degree Programs.
    static void printHeader();
    
    // Prints selected student's data
    void print();
    
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    string currentAge;
    int daysComplete[SIZE];
    DegreeProgram degreeProgram;
};

