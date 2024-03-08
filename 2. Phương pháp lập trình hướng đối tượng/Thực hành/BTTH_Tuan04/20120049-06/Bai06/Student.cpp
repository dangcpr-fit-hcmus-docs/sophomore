#include "Student.h"
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

ArrayStudent::ArrayStudent(string file) {
	fstream f;
	Student std;
	NgaySinh tmp3;
	double tmp4;
	char tmp5[256];
	int tmp6[3];
	f.open(file, ios::in);
	f.getline(tmp5, 256, '\n');
	while (!f.eof()) {
		f.getline(tmp5, 40, ','); 
		std.setID(string(tmp5));
		f.getline(tmp5, 40, ',');
		std.setLName(string(tmp5));
		f.getline(tmp5, 40, ',');
		std.setFName(string(tmp5));
		f.getline(tmp5, 40, ',');
		std.setAddress(string(tmp5));
		f >> tmp6[0]; f.seekg(1, ios::cur);
		f >> tmp6[1]; f.seekg(1, ios::cur);
		f >> tmp6[2]; f.seekg(1, ios::cur);
		tmp3.day = tmp6[0]; tmp3.month = tmp6[1]; tmp3.year = tmp6[2];
		std.setBirth(tmp3);
		//f.seekg(1, ios::cur);
		f >> tmp4;
		std.setMark(tmp4);
		_S.push_back(std);
		f.ignore();
	}
	cout << "Da doc duoc " << _S.size() << " sinh vien.\n";
	f.close();
}

void ArrayStudent::SortByLName() {
	for (int i = 0; i < _S.size() - 1; i++) {
		for (int j = i; j < _S.size(); j++) {
			if (_S[i].getLName() > _S[j].getLName())
				swap(_S[i], _S[j]);
		}
	}
	cout << "Da sap xep!\n";
}

void ArrayStudent::writeXML(string file) {
	fstream f;
	f.open(file, ios::out);
	f << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
	f << "<ArrStd>\n";
	for (int i = 0; i < _S.size(); i++) {
		f << "\t<Student id=\"" << i << "\">\n";
		f << "\t\t<StdID>" << _S[i].getID() << "</StdID>\n";
		f << "\t\t<LastName>" << _S[i].getLName() << "</LastName>\n";
		f << "\t\t<FirstName>" << _S[i].getFName() << "</FirstName>\n";
		f << "\t\t<Address>" << _S[i].getFName() << "</Address>\n";
		f << "\t\t<Birth_Day>" << _S[i].getBirth().day << "</Birth_Day>\n";
		f << "\t\t<Birth_Month>" << _S[i].getBirth().month << "</Birth_Month>\n";
		f << "\t\t<Birth_Year>" << _S[i].getBirth().year << "</Birth_Year>\n";
		f << "\t\t<Mark>" << _S[i].getMark() << "</Mark>\n";
		f << "\t</Student>\n";
	}
	f << "</ArrStd>";
	cout << "Da ghi vao file XML!\n";
}
ArrayStudent::~ArrayStudent() {
	cout << "Destructor Student!";
}