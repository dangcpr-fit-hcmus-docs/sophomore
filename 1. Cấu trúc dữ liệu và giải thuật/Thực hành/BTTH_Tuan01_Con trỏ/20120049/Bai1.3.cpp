#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
struct thiSinh {
	char* id, * hovaten;
	float toan, van, vatLy, hoaHoc, sinhHoc, lichSu, diaLy, giaoducCongDan, khoaHocTuNhien, khoaHocXaHoi, ngoaiNgu, Tong;
};
string convertString(char* a) {
	string s(a);
	return a;
}
void HoanDoiTen(char*& a, char*& b) {
	char* tmp = a;
	a = b;
	b = tmp;
}
void Diem(fstream& f, float& a) {
	char b[6];
	f.getline(b, 6, ',');
	if (strlen(b) == 0) a = 0;
	else a = atof(b);
}
thiSinh docThongTinThiSinh(fstream& f) {
	thiSinh TS;
	char a[100];
	TS.id = (char*)malloc(10);
	TS.hovaten = (char*)malloc(40);
	f.getline(TS.id, 10, ',');
	f.getline(TS.hovaten, 40, ',');
	Diem(f, TS.toan);
	Diem(f, TS.van);
	Diem(f, TS.vatLy);
	Diem(f, TS.hoaHoc);
	Diem(f, TS.sinhHoc);
	Diem(f, TS.lichSu);
	Diem(f, TS.diaLy);
	Diem(f, TS.giaoducCongDan);
	Diem(f, TS.khoaHocTuNhien);
	Diem(f, TS.khoaHocXaHoi);
	Diem(f, TS.ngoaiNgu);
	f.getline(a, 100);
	return TS;
}
vector<thiSinh> docDanhSachThiSinh(char* tenFile) {
	vector<thiSinh> DS;
	thiSinh TS;
	fstream f;
	char header[150];
	f.open(tenFile, ios::in);
	f.getline(header, 150);
	int k = 0;
	while (!f.eof()) {
		k++;
		DS.resize(k);
		DS[k - 1] = docThongTinThiSinh(f);
	}
	f.close();
	return DS;
}
void daoTenThiSinh(char* hovaten) {
	char* pch;
	int size = strlen(hovaten);
	pch = strtok(hovaten, " ");
	vector<char*> ten;
	int i = 0;
	while (pch != NULL)
	{
		ten.push_back(pch);
		pch = strtok(NULL, " ");
	}
	char s[40] = "";
	i = ten.size() - 1;
	int n = i;
	while (n>=0) {
		int i = n;
		if (i != 0) {
			strcat(s, ten[i]);
			strcat(s, " ");
		}
		else {
			strcat(s, ten[i]);
		}
		n--;
		i--;
	}
	strcpy(hovaten, s);
}
void daoNguocTenThiSinh(vector<thiSinh>& danhSachThiSinh) {
	for (int i = 0; i < danhSachThiSinh.size(); i++) {
		int length = strlen(danhSachThiSinh[i].hovaten);
		daoTenThiSinh(danhSachThiSinh[i].hovaten);
	}
}
int TimKiem(const char* a, vector<thiSinh>& danhSachThiSinh) {
	for (int i = 0; i < danhSachThiSinh.size(); i++) {
		if(strcmp(a, danhSachThiSinh[i].id) == 0)
			return i;
	}
}
void doiTenThiSinh(vector<thiSinh>& danhSachThiSinh) {
	int a = TimKiem("BD1200001", danhSachThiSinh);
	int b = TimKiem("BD1200003", danhSachThiSinh);
	HoanDoiTen(danhSachThiSinh[a].hovaten, danhSachThiSinh[b].hovaten);
	int c = TimKiem("BD1200005", danhSachThiSinh);
	int d = TimKiem("BD1200002", danhSachThiSinh);
	HoanDoiTen(danhSachThiSinh[c].hovaten, danhSachThiSinh[d].hovaten);
}
void tinhDiem(vector<thiSinh>& danhSachThiSinh) {
	for (int i = 0; i < danhSachThiSinh.size(); i++) {
		danhSachThiSinh[i].khoaHocTuNhien = danhSachThiSinh[i].vatLy + danhSachThiSinh[i].hoaHoc + danhSachThiSinh[i].sinhHoc;
		danhSachThiSinh[i].khoaHocXaHoi = danhSachThiSinh[i].lichSu + danhSachThiSinh[i].diaLy + danhSachThiSinh[i].giaoducCongDan;
		danhSachThiSinh[i].Tong = danhSachThiSinh[i].toan + danhSachThiSinh[i].van + danhSachThiSinh[i].ngoaiNgu + danhSachThiSinh[i].khoaHocTuNhien + danhSachThiSinh[i].khoaHocXaHoi;
	}
}
void xuatFile(const vector<thiSinh>& danhSachThiSinh, const char* tenFile){
	fstream f;
	f.open(tenFile, ios::out);
	f << "SBD,Ho va ten,KHTN,KHXH,Tong\n";
	for (int i = 0; i < danhSachThiSinh.size(); i++) {
		f << danhSachThiSinh[i].id << ",";
		f << danhSachThiSinh[i].hovaten << ",";
		f << danhSachThiSinh[i].khoaHocTuNhien << ",";
		f << danhSachThiSinh[i].khoaHocXaHoi << ",";
		f << danhSachThiSinh[i].Tong << "\n";
	}
	f.close();
}
int main() {
	vector<thiSinh> DS;
	thiSinh TS;
	char file[10] = "data.txt";
	DS = docDanhSachThiSinh(file);
	char ten[20] = "Dang Nguyen Hai";
	daoNguocTenThiSinh(DS);
	doiTenThiSinh(DS);
	tinhDiem(DS);
	xuatFile(DS, "tongketdiemthi.txt");
	return 0;
}