#pragma once
class Todolist{
public:
	int lastItem = -1;
	static const int numItems = 5;
	ListItem* classToDoListArray[numItems];

public:
    /* This method will take in the given information and seperate it at the commas. Parse needs to be edited to accept user input instead of static string.
    void parse(string studentData);
    */

    // May need to rename strings given here since they match student.h
    void add(string studentID,
        string firstName,
        string lastName,
        string email,
        string currentAge,
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    ~Roster();
};

