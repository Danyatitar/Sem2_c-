#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>
#include "structure.h"
using namespace std;
void getUniversity(vector <University> uv) {
	for (int i = 0; i < uv.size(); i++) {
		cout << "�����: " << uv[i].name << endl << "���� : " << uv[i].town << endl << "������ ����������� : " << uv[i].degree_of_acreditation << endl << "� - �� ���������� : " << uv[i].number_of_fakultets << endl;
		for (int j= 0; j < uv[i].fakultet.size(); j++) {
			cout << "����� ����������: " << uv[i].fakultet[j].name << endl << "�-�� �������� ����������: " << uv[i].fakultet[j].number_of_students << endl;
		}
		cout << endl;
	}
}
void getAcreditation(vector <University> uv) {
	for (int i = 0; i < uv.size(); i++) {
		cout << "�����: " << uv[i].name << endl << "���� : " << uv[i].town << endl << "������ ����������� : " << uv[i].degree_of_acreditation << endl;
		cout << endl;
	}
}
vector<University> input_university(int n) {
	vector <University> uv;
	for (int i = 0; i < n; i++) {
		University u;
		vector <Fakultet> fv;
		cout << "������ ����� ����" << endl;
		cin >> u.name;
		cout << "������ ����" << endl;
		cin >> u.town;
		cout << "������ ������ �����������" << endl;
		cin >> u.degree_of_acreditation;
		cout << "������ �-�� ����������" << endl;
		cin >> u.number_of_fakultets;
		for (int i = 0; i < u.number_of_fakultets; i++) {
			Fakultet f;
			cout << "������ ����� ����������" << endl;
			cin >> f.name;
			cout << "������ �-�� �������� ����������" << endl;
			cin >> f.number_of_students;
			fv.push_back(f);
		}
		cout << endl;
		u.fakultet = fv;
		uv.push_back(u);
	}
	return uv;
}
void Write_to_File(vector <University> uv) {
	ofstream file("University.bin", ios::binary | ios::trunc);
	for (int i=0; i < uv.size(); i++) {
		file.write((char*)&uv[i], sizeof(University));
	}
	file.close();
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
vector <University> acreditation(vector <University> uv) {
	vector <University> nuv;

	for (int i = 0; i < uv.size(); i++) {
		if (uv[i].degree_of_acreditation == 3 || uv[i].degree_of_acreditation == 4) {
			nuv.push_back(uv[i]);
		}
	}
	return nuv;
}
void Write_to_File2(vector <University> uv) {
	ofstream file("Acreditation.bin", ios::binary | ios::trunc);
	for (int i = 0; i < uv.size(); i++) {
		file.write((char*)&uv[i].name, sizeof(string));
		file.write((char*)&uv[i].town, sizeof(string));
		file.write((char*)&uv[i].degree_of_acreditation, sizeof(int));
	}
	file.close();
}
