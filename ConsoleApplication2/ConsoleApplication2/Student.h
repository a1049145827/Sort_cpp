#pragma once
#include <string>
#include <ostream>

using namespace std;

struct Student {
	string name;
	int score;

	bool operator<(const Student& otherStudent) {
		bool equal = score == otherStudent.score;
		bool value = false;
		if (equal)
		{
			value = name < otherStudent.name;
		}
		else {
			value = score < otherStudent.score;
		}
		return value;
	}

	friend ostream& operator<<(ostream &os, Student &student) {
		os << "Student: " << student.name << " " << student.score << endl;
		return os;
	}
};