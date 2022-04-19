#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <string>
using namespace std;
class Text {
private:
    int number_of_lines;
    vector <string> text;
public:
    Text();
    void setNumber_of_lines(int number_of_lines);
    void setText(vector <string> text);
    int getNumber_of_lines();
    vector <string> GetText();
    void Print();
    void add();
    int percent_of_consonants();
    vector <string> InputText();
    int InputRandomnumber();
    vector <string> InputRandomText();
};
