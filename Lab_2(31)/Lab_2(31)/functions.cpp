#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>
#include "structures.h"
University input_university(University u) {

	vector <Fakultet> fv;
	cout << "¬вед≥ть назву ¬”«у" << endl;
	cin >> u.name;
	cout << "¬вед≥ть м≥сто" << endl;
	cin >> u.town;
	cout << "¬вед≥ть ступ≥нь акредитац≥њ" << endl;
	cin >> u.degree_of_acreditation;
	cout << "¬вед≥ть к-ть факультет≥в" << endl;
	cin >> u.number_of_fakultets;
	for (int i = 0; i < u.number_of_fakultets; i++) {
		Fakultet f;
		cout << "¬вед≥ть назву факультету" << endl;
		cin >> f.name;
		cout << "¬вед≥ть к-ть студент≥в факультету" << endl;
		cin >> f.number_of_students;
		fv.push_back(f);
	}
	cout << endl;
	u.fakultet = fv;


	return u;
}
vector <string> max_student(string town, vector <University> uv) {
	vector <int> students;
	vector <string> name_and_fakultet;
	for (int i = 0; i < uv.size(); i++) {
		if (uv[i].town == town) {
			for (int j = 0; j < uv[i].fakultet.size(); j++) {
				students.push_back(uv[i].fakultet[j].number_of_students);
			}
		}
	}
	int max = 0;
	for (int i = 0; i < students.size(); i++) {
		if (students[i] > max) {
			max = students[i];
		}
	}
	for (int i = 0; i < uv.size(); i++) {
		if (uv[i].town == town) {
			for (int j = 0; j < uv[i].fakultet.size(); j++) {
				if (uv[i].fakultet[j].number_of_students == max) {
					name_and_fakultet.push_back(uv[i].name);
					name_and_fakultet.push_back(uv[i].fakultet[j].name);
				}
			}
		}
	}
	return name_and_fakultet;
}
vector <NewFileUniversity> acreditation(vector <University> uv) {
	vector <NewFileUniversity> nfuv;

	for (int i = 0; i < uv.size(); i++) {
		if (uv[i].degree_of_acreditation == 3 || uv[i].degree_of_acreditation == 4) {
			NewFileUniversity nfu;
			nfu.name = uv[i].name;
			nfu.town = uv[i].town;
			nfu.degree_of_acreditation = uv[i].degree_of_acreditation;
			nfuv.push_back(nfu);

		}
	}
	return nfuv;
}
vector <University> FirstFile(int n) {
	vector <University> uv;
	University u;
	ofstream file("Universities.bin", ios::binary);
	for (int i = 0; i < n; i++) {
		u = input_university(u);
		file.write((char*)&(u), sizeof(University));
		uv.push_back(u);
	}
	
	file.close();
	return uv;
}
void NewFile(vector < NewFileUniversity > nfuv) {
	ofstream file("NewUniversities.bin", ios::binary);
	for (int i = 0; i < nfuv.size(); i++) {
		file.write((char*)&nfuv[i], sizeof(nfuv[i]));
	}
	file.close();
}

/*


void OutofFirstfile(string name) {
	vector <University> uv1;
	Fakultet f;
	ifstream file(name, ios::binary);
	if (!file.is_open())
	{
		cout << "ѕорожн≥й файл" << endl;
	}

	file.read((char*)&uv1, sizeof(vector<University>));
	for (int i = 0; i < uv1.size(); i++) {
		uv1[i].toString();
		cout << endl;
	}


	file.close();
}

void OutofFirstfile(string name) {
	vector <University> uv1;
	Fakultet f;
	ifstream file(name, ios::binary);
	if (!file.is_open())
	{
		cout << "ѕорожн≥й файл" << endl;
	}

	file.read((char*)&uv1, sizeof(vector<University>));
	for (int i = 0; i < uv1.size(); i++) {
		uv1[i].toString();
		cout << endl;
	}


	file.close();
}

*/
void OutofEndFile(vector <NewFileUniversity> nfuv) {
	for (int i = 0; i < nfuv.size(); i++) {
		nfuv[i].toString();
		cout << endl;
	}
}
void OutofFirstfile(vector <University> uv) {
	for (int i = 0; i < uv.size(); i++) {
		uv[i].toString();
		cout << endl;
	}
}
