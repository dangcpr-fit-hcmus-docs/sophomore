#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <sstream>
#include <map>
#include <fstream>
using namespace std;

#include "IShape.h"
#include "RandomIntegerGenerator.h"
#include "RandomRectangleGenerator.h"
#include "RandomCircleGenerator.h"
#include "RandomTriangleGenerator.h"

struct {
    vector<IShape*> shapes;
} state;

tuple<bool, int, string, int> getInteger(int left, int right);


class ShapeFactory {
private:
    static inline ShapeFactory* _instance = NULL;
    vector<IShape*> _prototypes;

    ShapeFactory() { // Cau hinh 1 lan duy nhat
        _instance = NULL;
        _prototypes.push_back(new Rectangle());
        _prototypes.push_back(new Circle());
        _prototypes.push_back(new Triangle());
    }

public:
    int suportedTypesCount() {
        return _prototypes.size();
    }

    IShape* create(int type) {
        const int left = 6;
        const int right = 12;
        IShape* shape = _prototypes[type]->generate(left, right);

        return shape;
    }

    static ShapeFactory* instance() {
        if (_instance == NULL) {
            _instance = new ShapeFactory();
        }

        return _instance;
    }
};


class IConverter {
public:
    static inline fstream* _f = NULL;
public:
    virtual void convert(void* shape) = 0;
};

class RectangleUIConverter : public IConverter {
public:
    void convert(void* shape) {
        Rectangle* rectangle = (Rectangle*)shape;

        stringstream builder;
        builder << rectangle->className() << ": ";
        builder << "Width=" << rectangle->a() << " Height=" << rectangle->b() << " Perimeter=" << rectangle->perimeter() << " Area=" << rectangle->area();

        string result = builder.str();
        cout << result;
    }
};
class RectangleDataConverter : public IConverter {
public:
    RectangleDataConverter() : IConverter() {
        if (IConverter::_f == NULL) {
            IConverter::_f = new fstream;
            IConverter::_f->open("IShape.txt", ios::out);
        }
    }
    void convert(void* shape) {
        Rectangle* rectangle = (Rectangle*)shape;

        stringstream builder;
        builder << rectangle->className() << ": ";
        builder << "Width=" << rectangle->a() << " Height=" << rectangle->b() << " Perimeter=" << rectangle->perimeter() << " Area=" << rectangle->area();

        string result = builder.str();

        *(IConverter::_f) << result << endl;
    }
};

class CircleUIConverter : public IConverter {
public:
    void convert(void* shape) {
        Circle* circle = (Circle*)shape;

        stringstream builder;
        builder << circle->className() << ": ";
        builder << "Radius=" << circle->r() << " Perimeter=" << circle->perimeter() << " Area=" << circle->area();

        string result = builder.str();
        cout << result;
    }
};
class CircleDataConverter : public IConverter {
public:
    CircleDataConverter() : IConverter() {
        if (IConverter::_f == NULL) {
            IConverter::_f = new fstream;
            IConverter::_f->open("IShape.txt", ios::out);
        }
    }
    void convert(void* shape) {
        Circle* circle = (Circle*)shape;

        stringstream builder;
        builder << circle->className() << ": ";
        builder << "Radius=" << circle->r() << " Perimeter=" << circle->perimeter() << " Area=" << circle->area();

        string result = builder.str();
        *(IConverter::_f) << result << endl;
    }
};

class TriangleUIConverter : public IConverter {
public:
    void convert(void* shape) {
        Triangle* triangle = (Triangle*)shape;

        stringstream builder;
        builder << triangle->className() << ": ";
        builder << "a=" << triangle->a() << ", b=" << triangle->b() << ", c=" << triangle->c() << " Perimeter=" << triangle->perimeter() << " Area=" << triangle->area();

        string result = builder.str();
        cout << result;
    }
};
class TriangleDataConverter : public IConverter {
public:
    TriangleDataConverter() : IConverter() {
        if (IConverter::_f == NULL) {
            IConverter::_f = new fstream;
            IConverter::_f->open("IShape.txt", ios::out);
        }
    }
    void convert(void* shape) {
        Triangle* triangle = (Triangle*)shape;

        stringstream builder;
        builder << triangle->className() << ": ";
        builder << "a=" << triangle->a() << ", b=" << triangle->b() << ", c=" << triangle->c() << " Perimeter=" << triangle->perimeter() << " Area=" << triangle->area();

        string result = builder.str();
        *(IConverter::_f) << result << endl;
    }
};

int main()
{
    // 1. Sinh ngau nhien so nguyen n trong khoang [6, 12]
    const int left = 6;
    const int right = 12;
    int n = RandomIntegerGenerator::instance()->next(left, right);

    // 2. Sinh ra n hinh
    for (int i = 0; i < n; i++) {
        int count = ShapeFactory::instance()->suportedTypesCount();
        int type = RandomIntegerGenerator::instance()->next(count);
        IShape* shape = ShapeFactory::instance()->create(type);
        state.shapes.push_back(shape);
    }

    // Cau hinh
    map<string, IConverter*> ui = {
        {(new Rectangle())->className(), new RectangleUIConverter() },
        {(new Circle())->className(), new CircleUIConverter() },
        {(new Triangle())->className(), new TriangleUIConverter() }
    };
    map<string, IConverter*> data = {
    {(new Rectangle())->className(), new RectangleDataConverter() },
    {(new Circle())->className(), new CircleDataConverter() },
    {(new Triangle())->className(), new TriangleDataConverter() }
    };
    for (int i = 0; i < n; i++) {
        auto converter = ui[state.shapes[i]->className()];
        converter->convert((void*)state.shapes[i]);

        cout << endl;
    }
    for (int i = 0; i < n; i++) {
        auto converter = data[state.shapes[i]->className()];
        converter->convert((void*)state.shapes[i]);
    }
    IConverter::_f->close();
    delete IConverter::_f;

    // bool shouldRepeat = false;
    // bool success = false;
    // int errorCode = 0;
    // string message = "";

    // do {
    //     cout << "Hay nhap so nguyen trong doan [" << left << ", " << right << "]: ";
    //     tie(success, errorCode, message, n) = getInteger(left, right);

    //     if (success) {
    //         shouldRepeat = false;
    //     } else {
    //         cout << "Loi khi nhap lieu:" << message << endl << endl;
    //         shouldRepeat = true;
    //     }
    // } while (shouldRepeat);

    cout << n;

    return 0;
}