#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class RandomInteger {
public:
	static int next(int l, int r) {
		int result = rand() % (r - l + 1) + l;
		return result;
	}
};
class Dragon {
protected:
	string _name;
	int _level;
	int _HP;
	int _damage;
public:
	Dragon() {
		_name = "";
		_level = 0;
	}
	Dragon(string name, int level) {
		_name = name;
		_level = level;
	}
	virtual void input() = 0;
	virtual int attack() = 0;
	virtual string toString() = 0;
};

class SeaDragon : public Dragon {
public:
	//Default Constructor - Sea Dragon
	SeaDragon() : Dragon() {
		_HP = RandomInteger::next(1000, 10000);
		_damage = RandomInteger::next(200, 1200);
	}
	SeaDragon(string name, int level) : Dragon(name, level) {
		_HP = RandomInteger::next(1000, 10000);
		_damage = RandomInteger::next(200, 1200);
	}

	//Copy Constructor - Sea Dragon
	SeaDragon(SeaDragon& S) {
		_name = S._name;
		_level = S._level;
		_HP = S._HP;
		_damage = S._damage;
	}
	int attack() {
		int totalDamage = _damage * 10;
		return totalDamage;
	}
	void input();
	string toString();
};

class FlameDragon : public Dragon {
public:
	FlameDragon() : Dragon() {
		_HP = RandomInteger::next(5000, 15000);
		_damage = RandomInteger::next(100, 1000);
	}
	FlameDragon(string name, int level) : Dragon(name, level) {
		_HP = RandomInteger::next(5000, 15000);
		_damage = RandomInteger::next(100, 1000);
	}
	int attack() {
		int totalDamage = _damage * 15;
		return totalDamage;
	}
	void input();
	string toString();
};

class Game {
private:
	vector<Dragon*> Dra;
public:
	void input();
	void output();
	int totalAttack();
};