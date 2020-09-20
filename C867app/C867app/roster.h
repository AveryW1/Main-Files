//
//  roster.h
//  C867app
//
//  Created by Avery Washington on 9/4/20.
//  Copyright © 2020 General Cloud Applications LLC. All rights reserved.
//

#pragma once
#include "student.h"

class Roster {

// The array object 'classRosterArray' has to be static for this project since we are not using vectors. Vectors would allow dynamic sizing.
public:
    int lastStudent = -1;
    static const int numStudents = 5;
    Student* classRosterArray[numStudents];
    
public:
    // This method will take in the given information and seperate it at the commas.
    void parse(string studentData);
    
    // May need to rename strings given here since they match student.h
    void add(string studentID,
             string firstName,
             string lastName,
             string email,
             string currentAge,
             int daysComplete1,
             int daysComplete2,
             int daysComplete3,
             DegreeProgram degreeProgram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    ~Roster();
};
