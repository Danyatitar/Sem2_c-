#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
vector<string> input(string name) {
    string input, line;
    vector<string> text;
    ofstream file(name + ".txt", ios::out);
    if (file.is_open()) {
        cout << "Input text, to end input Ctrl+X " << endl;
        cin.ignore();
        getline(cin, line);

        while (int(line[0]) != 24) {
            text.push_back(line);
            file <<line + '\n';
            getline(cin, line);
        }
       
        file.close();
        return text;
    }
    else {
        cout << "File didn`t open" << endl;
    }
}
vector<string> process(vector<string> text) {
    for (int i = 0; i < text.size(); i++) {
        text[i] = to_string(text[i].size())+" " + text[i]+" "+ to_string(i + 1);
    }
   
    return text;
}
void toNewFile(vector<string> text, string name) {
    ofstream file("New_" + name + ".txt", ios::out);
    if (file.is_open()) {
        string s;
        for (int i = 0; i < text.size(); i++) {
            file << text[i] << endl;

        }
        file.close();
    }
    else {
        cout << "File didn`t open" << endl;
    }
}
void out(string name) {
    ifstream file(name + ".txt", ios::in);
    ifstream new_file("New_" + name + ".txt", ios::in);
    cout << endl;
    cout << "First file:" << endl;
    string str;
    while (!file.eof()) {
        str = "";
        getline(file, str);
        cout << str << endl;
    }
    file.close();
    cout << "New file:" << endl;
    while (!new_file.eof()) {
        str = "";
        getline(new_file, str);
        cout << str << endl;
    }
    new_file.close();
}