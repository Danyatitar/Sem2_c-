#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>

using namespace std;
struct Fakultet {
    string name;
    int number_of_students;
    void toString() {
        cout << "Назва факультету: " << name << endl << "К-ть студентів факультету: " << number_of_students << endl;
    }
};
struct University {
    string name;
    string town;
    int degree_of_acreditation;
    int number_of_fakultets;
    vector <Fakultet> fakultet;
    void toString() {
        cout << "Назва: " << name << endl << "місто : " << town << endl << "ступінь акредитації : " << degree_of_acreditation << endl << "К - ть факультетів : " << number_of_fakultets << endl;
        for (int i = 0; i < fakultet.size(); i++) {
          fakultet[i].toString();
       }
    }
};
struct NewFileUniversity {
    string name;
    string town;
    int degree_of_acreditation;
    void toString() {
        cout << "Назва: " << name << endl << "місто : " << town << endl << "ступінь акредитації : " << degree_of_acreditation << endl;
    }
};
