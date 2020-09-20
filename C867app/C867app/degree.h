//
//  degree.h
//  C867app
//
//  Created by Avery Washington on 9/4/20.
//  Copyright © 2020 General Cloud Applications LLC. All rights reserved.
//

#pragma once
#include <string>
#include <iostream>
using namespace std;


/* Enumeration - creating a custom data type. Has an underlying interger(int) value that starts with 0 and counts 1++.
 Undecided is added as a default value for use in a constructor. */
enum DegreeProgram {
    UNDECIDED, SECURITY, NETWORK, SOFTWARE
};

// Parallel array of strings example from Booktype video. Allows display of degree name instead of interger in output.
static const std::string degreeProgramStrings[] = {"UNDECIDED", "SECURITY", "NETWORK", "SOFTWARE"};
