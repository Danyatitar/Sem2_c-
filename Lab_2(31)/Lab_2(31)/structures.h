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
        cout << "����� ����������: " << name << endl << "�-�� �������� ����������: " << number_of_students << endl;
    }
};
struct University {
    string name;
    string town;
    int degree_of_acreditation;
    int number_of_fakultets;
    vector <Fakultet> fakultet;
    void toString() {
        cout << "�����: " << name << endl << "���� : " << town << endl << "������ ����������� : " << degree_of_acreditation << endl << "� - �� ���������� : " << number_of_fakultets << endl;
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
        cout << "�����: " << name << endl << "���� : " << town << endl << "������ ����������� : " << degree_of_acreditation << endl;
    }
};
