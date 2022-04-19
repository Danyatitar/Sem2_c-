#include <iostream>
#include <vector>
#include <random>
#include <string>
#include "Text.h";
    Text::Text() {
        text = InputText();
        number_of_lines = InputRandomnumber();
    }
    void Text::setNumber_of_lines(int number_of_lines) {
        this->number_of_lines = number_of_lines;
    }
    void Text::setText(vector <string> text) {
        this->text = text;
    }
    int Text::getNumber_of_lines() {
        return number_of_lines;
    }
    vector <string> Text::GetText() {
        return text;
    }
    void Text::Print() {
        cout << "Text with "<<number_of_lines<<" lines:" << endl;
        for (int i = 0; i < text.size(); i++) {
            cout << text[i] << endl;
        }
    }
    void Text::add() {
        
        string s;
        getline(cin,s);
        text.push_back(s);
    }

    int Text::percent_of_consonants() {
        int count_all=0;
        int count_consonants=0;
        float percent;
        for (int i = 0; i < text.size(); i++) {
            for (int j = 0; j < text[i].length(); j++) {
                count_all++;
                if (text[i][j] != 'A' && text[i][j] != 'a' && text[i][j] != 'O' && text[i][j] != 'o' && text[i][j] != 'u' && text[i][j] != 'U' && text[i][j] != 'I' && text[i][j] != 'i' && text[i][j] != 'E' && text[i][j] != 'e' && text[i][j] != 'y' && text[i][j] != 'Y') {
                    count_consonants++;
                }
            }
        }
        percent = ((float)count_consonants / (float)count_all) * 100;
        percent = (int)percent;
        return percent;
    }
    vector <string> Text::InputText() {
        int n;
        vector <string> text;
        cout << "input number of lines" << endl;
        cin >> n;
        cout << "input text" << endl;
        for (int i = 0; i <= n; i++) {
            string s;
            getline(cin, s);
            text.push_back(s);
        }
        return text;
    }
    int Text::InputRandomnumber() {
        srand(time(NULL));
        return rand() % 5 + 2;
    }
    vector <string> Text::InputRandomText()
    {     
       vector <string> text;
        int n = InputRandomnumber();
        for (int i = 0; i < n; i++) {
            srand(time(NULL));
            string s = "";
            int m = rand() % 5 + 2;
            for (int j = 0; j < m; j++) {
                if (j == m - 1) {
                    string str("abcdefghijklmnopqrstuvwxyz");
                    random_device rd;
                    mt19937 generator(rd());
                    shuffle(str.begin(), str.end(), generator);
                    s = s + str.substr(0, rand() % j+rand()%7);
                }
                else {
                    string str("abcdefghijklmnopqrstuvwxyz");
                    random_device rd;
                    mt19937 generator(rd());
                    shuffle(str.begin(), str.end(), generator);
                    s = s + str.substr(0, rand() % (j+1) + rand() % 7)+ " ";
                }
            }
            text.push_back(s);
            n = InputRandomnumber();
        }
        return text;
    }