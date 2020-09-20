//
//  main.cpp
//  C867app
//
//  Created by Avery Washington on 9/3/20.
//  Copyright © 2020 General Cloud Applications LLC. All rights reserved.
//

#include "roster.h"
#include "student.h"

int main() {
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Avery,Washington,awashi1@wgu.edu,30,5,10,15,SOFTWARE"
    };

    cout << "Project for C867 in C++ by Avery Washington ID: 001479569" << endl << endl;
    
    const int numStudents = 5;
    Roster classRoster;

    for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
    cout << "Displaying all students: " << endl;
    classRoster.printAll();
    cout << endl;

    cout << "Displaying students with invalid Emails" << endl;
    classRoster.printInvalidEmails();
    cout << endl;

    cout << "Displaying average days to complete course: " << endl;
    classRoster.printAverageDaysInCourse("A3");
    
    classRoster.printByDegreeProgram(SOFTWARE);
    
    cout << "Removing student ID A3:" << endl;
    classRoster.remove("A3");
    classRoster.printAll();
    cout << "Removing student ID A3:" << endl;
    classRoster.remove("A3");
}


