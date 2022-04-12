
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
vector<string> input(string name);
vector<string> process(vector<string> text);
void toNewFile(vector<string> text, string name);
void out(string name);