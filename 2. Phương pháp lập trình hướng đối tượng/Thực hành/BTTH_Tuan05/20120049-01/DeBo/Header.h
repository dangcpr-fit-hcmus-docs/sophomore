#pragma once
#include <iostream>
#include <vector>
using namespace std;

class BoSua {
private:
	int _id;
	double _weight;
	double _age;
public:
	int getID() { return _id; };
	double getWeight() { return _weight; };
	double getAge() { return _age; };
	void setWeight(double weight) { _weight = weight; };
	void setAge(double age) { _age = age; };
	BoSua();
	BoSua(int, double, double);
	void operator=(const BoSua& obj);
	string Info();
	~BoSua();
};
class De {
private:
	int _id;
	double _weight;
	double _age;
public:
	int getID() { return _id; };
	double getWeight() { return _weight; };
	double getAge() { return _age; };
	void setWeight(double weight) { _weight = weight; };
	void setAge(double age) { _age = age; };
	De();
	De(int, double, double);
	void operator=(const De& obj);
	string Info();
	//~De();
};

class NongTrai {
private:
	vector<BoSua> ds_bo_sua;
	vector<De> ds_de;
public:
	void Nhap();
	void Xuat();
	void Xuat_Theo_Tuoi(int min, int max);
	~NongTrai();
};