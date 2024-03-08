
#include <iostream>
using namespace std;

#include "IShape.h"
#include "Rectangle.h"
#include "RandomDoubleGenerator.h"

class RandomRectangleGenerator {
private:
    inline static RandomRectangleGenerator* _instance = NULL;
    
    RandomRectangleGenerator() {
        
    }
public:
    IShape* next(int left, int right) {
        int a = RandomDoubleGenerator::instance()->next(left, right);
        int b = RandomDoubleGenerator::instance()->next(left, right);
        IShape* result = new Rectangle(a, b);
        return result;
    }
    
    static RandomRectangleGenerator* instance() {
        if (_instance == NULL)  {
            _instance = new RandomRectangleGenerator();
        }
        
        return _instance;
    }
};

