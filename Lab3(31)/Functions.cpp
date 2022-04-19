#include <iostream>
#include <vector>
#include <random>
#include <string>
#include "Text.h"
using namespace std;
void getInfo(Text* t, int n) {
    for (int i = 0; i < n; i++) {
        t[i].Print();
        cout << endl;
    }
}
vector <int> max_percent(Text* t, int n) {
    vector <int> percent;
    vector <int> max_percent;
    for (int i = 0; i < n; i++) {
        percent.push_back(t[i].percent_of_consonants());
    }
    int max = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (percent[i] > max) {
            max = percent[i];
            j = i;
        }
    }
    max_percent.push_back(j+1);
    max_percent.push_back(max);
    return max_percent;
}
void add(Text* t, int n) {
    for (int i = 0; i < n; i++) {
        cout << "input line for text "<<i+1<< endl;
        t[i].add();
    }
}