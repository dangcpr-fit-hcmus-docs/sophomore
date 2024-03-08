
#include <iostream>
using namespace std;

#include "IShape.h"
#include "Circle.h"
#include "RandomDoubleGenerator.h"

class RandomCircleGenerator {
private:
    inline static RandomCircleGenerator* _instance = NULL;
    
    RandomCircleGenerator() {
        
    }
public:
    IShape* next(int left, int right) {
        int r = RandomDoubleGenerator::instance()->next(left, right);
        IShape* result = new Circle(r);
        return result;
    }
    
    static RandomCircleGenerator* instance() {
        if (_instance == NULL)  {
            _instance = new RandomCircleGenerator();
        }
        
        return _instance;
    }
};

