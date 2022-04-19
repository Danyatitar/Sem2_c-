#pragma once
#include <string>
#include <Windows.h>
#include <vector>

using namespace std;
struct Fakultet {
    string name;
    int number_of_students;

};
struct University {
    string name;
    string town;
    int degree_of_acreditation;
    int number_of_fakultets;
    vector <Fakultet> fakultet;

};
