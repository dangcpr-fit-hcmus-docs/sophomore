
#include <iostream>
using namespace std;

#include "IShape.h"
#include "Triangle.h"
#include "RandomDoubleGenerator.h"

class RandomTriangleGenerator {
private:
    inline static RandomTriangleGenerator* _instance = NULL;
    
    RandomTriangleGenerator() {
        
    }
public:
    IShape* next(int left, int right) {
        int a = RandomDoubleGenerator::instance()->next(left, right);
        int b = RandomDoubleGenerator::instance()->next(left, right);
        int c = RandomDoubleGenerator::instance()->next(left, right);
        
        IShape* result = new Triangle(a, b, c);
        return result;
    }
    
    static RandomTriangleGenerator* instance() {
        if (_instance == NULL)  {
            _instance = new RandomTriangleGenerator();
        }
        
        return _instance;
    }
};

