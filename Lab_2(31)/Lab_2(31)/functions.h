#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>
#include "structures.h"
using namespace std;
University input_university(University);
vector <string> max_student(string, vector <University>);
vector <NewFileUniversity> acreditation(vector <University>);
vector <University> FirstFile(int);
void NewFile(vector < NewFileUniversity >);
void OutofEndFile(vector <NewFileUniversity>);
void OutofFirstfile(vector <University>);