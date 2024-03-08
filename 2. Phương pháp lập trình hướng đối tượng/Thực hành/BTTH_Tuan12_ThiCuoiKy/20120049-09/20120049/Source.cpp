#include "Header.h"
#include <sstream>

void SeaDragon::input() {
	cout << "Nhap ten Sea Dragon: "; getline(cin, _name);
	cout << "Nhap cap do: "; cin >> _level;
}
string SeaDragon::toString() {
	stringstream ss;
	ss << "Ten: " << _name << " - Loai: Sea Dragon";
	ss << "\n\tCap do: " << _level;
	ss << "\n\tLuong mau: " << _HP;
	ss << "\n\tMuc sat thuong: " << _damage;
	ss << "\n\tSuc sat thuong: " << attack() << '\n';

	string s = ss.str();
	return s;
}

void FlameDragon::input() {
	cout << "Nhap ten Flame Dragon: "; getline(cin, _name);
	cout << "Nhap cap do: "; cin >> _level;
}
string FlameDragon::toString() {
	stringstream ss;
	ss << "Ten: " << _name << " - Loai: Flame Dragon";
	ss << "\n\tCap do: " << _level;
	ss << "\n\tLuong mau: " << _HP;
	ss << "\n\tMuc sat thuong: " << _damage;
	ss << "\n\tSuc sat thuong: " << attack() << '\n';

	string s = ss.str();
	return s;
}

void Game::input() {
	int n, k;
	cout << "Nhap so luong rong: "; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Nhap con rong thu: " << i + 1 << '\n';
		cout << "Nhap 1 neu la Sea Dragon, nhap 0 neu la Flame Dragon: "; cin >> k;
		if (k == 1) {
			Dragon* tmp = new SeaDragon();
			cin.ignore(); tmp->input();
			Dra.push_back(tmp);
		}
		else {
			Dragon* tmp = new FlameDragon();
			cin.ignore(); tmp->input();
			Dra.push_back(tmp);
		}
	}
}
void Game::output() {
	for (int i = 0; i < Dra.size(); i++) {
		cout << Dra[i]->toString();
	}
}
int Game::totalAttack() {
	int total = 0;
	for (int i = 0; i < Dra.size(); i++) {
		total += Dra[i]->attack();
	}
	return total;
}