#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>
#include "structure.h"
using namespace std;
void getUniversity(vector <University>);
vector<University> input_university(int);
vector <string> max_student(string, vector <University>);
void Write_to_File(vector <University>);
vector <University> Read_from_file();
void Write_to_File2(vector <University>);
vector <University> acreditation(vector <University>);
vector <string> max_student(string, vector <University>);
void getAcreditation(vector <University>);