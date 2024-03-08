#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class Element {
protected:
    string _name;
    double _price;
public:
    Element(string name, double  price) {
        _name = name;
        _price = price;
    }
    Element() { _name = ""; _price = 0; }
    string name() { return _name; }
    double price() { return _price; }
    void setName(string name) { _name = name; }
    void setPrice(double price) { _price = price; }
};
class Computer {
protected:
    int _ID;
    string _name;
    string _factory;
public:
    virtual double totalPrice() = 0;
    virtual string toString() = 0;
    string factory() { return _factory; }
    Computer(int ID, string name, string factory) {
        _ID = ID;
        _name = name;
        _factory = factory;
    }
};

class Desktop : public Computer {
private:
    vector<Element*> _Ele;
public:
    Desktop(int ID, string name, string factory, vector<Element*> Ele) :Computer(ID, name, factory) {
        //_ID = ID;
        //_name = name;
        //_factory = factory;
        _Ele = Ele;
    }

    double totalPrice() {
        double total = 0;
        for (int i = 0; i < _Ele.size(); i++) {
            total += _Ele[i]->price();
        }
        return total * 1.1;
    }

    string toString() {
        stringstream ss;
        ss << "ID: " << _ID << "- Category: Desktop";
        ss << "\n\tName: " << _name;
        ss << "\n\tFactory: " << _factory;
        ss << "\n\tGia linh kien: ";
        for (int i = 0; i < _Ele.size(); i++) {
            ss << "\n\t\t" << i + 1 << ": " << _Ele[i]->name() << " - " << _Ele[i]->price();
        }
        ss << "\n";

        string s = ss.str();
        return s;
    }
};

class Laptop : public Computer {
private:
    double _priceFactory;
public:
    Laptop(int ID, string name, string factory, double priceFactory) :Computer(ID, name, factory) {
        //_ID = ID;
        //_name = name;
        //_factory = factory;
        _priceFactory = priceFactory;
    }

    double totalPrice() {
        if (_factory == "Apple") return _priceFactory;
        else return _priceFactory * 1.1;
    }

    string toString() {
        stringstream ss;
        ss << "ID: " << _ID << "- Category: Laptop";
        ss << "\n\tName: " << _name;
        ss << "\n\tFactory: " << _factory;
        ss << "\n\tPrice factory: " << _priceFactory;
        ss << "\n";

        string s = ss.str();
        return s;
    }
};

class Store {
private:
    vector<Computer*> _Product;
public:
    void input() {
        int n, k; double d;
        string tmp1, tmp2, tmp3;
        vector<Element*> ListEle;
        cout << "So san pham can nhap: "; cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Nhap san phan thu " << i + 1 << ":\n";
            cout << "Nhap 1 neu la Desktop, 0 neu la Laptop: "; cin >> k;  cin.ignore();
            cout << "Ten san pham: "; getline(cin, tmp1);
            cout << "Nha san xuat: "; getline(cin, tmp2);
            if (k == 1) {
                cout << "So linh kien: "; cin >> k; cin.ignore();
                for (int j = 0; j < k; j++) {
                    cout << "Nhap linh kien " << j + 1 << ": "; getline(cin, tmp3);
                    cout << "Nhap gia link kien " << j + 1 << ": "; cin >> d; cin.ignore();
                    Element* E = new Element;
                    E->setName(tmp3); E->setPrice(d);
                    ListEle.push_back(E);
                }
                Computer* Com = new Desktop(i + 1, tmp1, tmp2, ListEle);
                _Product.push_back(Com);
                ListEle.resize(0);
            }
            else {
                cout << "Nhap gia nha san xuat: "; cin >> d;
                Computer* Com = new Laptop(i + 1, tmp1, tmp2, d);
                _Product.push_back(Com);
            }
        }
    }
    void infoComputer() {
        for (int i = 0; i < _Product.size(); i++) {
            cout << _Product[i]->toString();
        }
    }
    void Sort() {
        for (int i = 0; i < _Product.size() - 1; i++)
            for (int j = 1; j < _Product.size(); j++) {
                if (_Product[i]->factory() > _Product[j]->factory()) {
                    Computer* tmp = _Product[i];
                    _Product[i] = _Product[j];
                    _Product[j] = tmp;
                }
            }
        for (int i = 0; i < _Product.size() - 1; i++)
            for (int j = 1; j < _Product.size(); j++) {
                if (_Product[i]->totalPrice() > _Product[j]->totalPrice()) {
                    Computer* tmp = _Product[i];
                    _Product[i] = _Product[j];
                    _Product[j] = tmp;
                }
            }
    }
    double total() {
        double price = 0;
        for (int i = 0; i < _Product.size(); i++) {
            price += _Product[i]->totalPrice();
        }
        return price;
    }
    vector<Computer*> Product() { return _Product; }
};
int main() {
    Store S;
    S.input();
    int k = 0;
    S.infoComputer();
    string factory;
    cout << "\nNhap nha san xuat muon tim: "; getline(cin, factory);
    cout << "Cac san pham cua NSX " << factory;
    for (int i = 0; i < S.Product().size(); i++) {
        if (S.Product()[i]->factory() == factory) {
            cout << '\n' << S.Product()[i]->toString();
            k++;
        }
    }
    cout << "\nTong chi phi thu duoc: " << S.total();
    S.Sort();
    cout << "\nCac san pham sau khi sap xep: "; S.infoComputer();
}