// Lab_2(31)c.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>
#include "structure.h"
#include "Functions.h"
using namespace std;
int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    University u;
    int n;
    cout << "������ �-�� ��ǳ�" << endl;
    cin >> n;
    vector <University> uv = input_university(n);
    Write_to_File(uv);
   
    string name_town;
    cout << endl;
    cout << "������ ����" << endl;
    cin >> name_town;
    cout << endl;
    getUniversity(uv);
    vector <string> name_and_fakultet = max_student(name_town, uv);
    cout << "�������� �-�� �������� � ��� " << name_town << endl << name_and_fakultet[0] << ": " << name_and_fakultet[1] << endl;
    vector <University> nuv = acreditation(uv);
  
    cout << "���� � ������������ 3 �� 4 ����:" << endl;
    getAcreditation(nuv);
    Write_to_File2(nuv);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
