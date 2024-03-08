#pragma once
#include <iostream>
using namespace std;


class RandomDoubleGenerator {
private:
    inline static RandomDoubleGenerator* _instance = NULL;
    
    RandomDoubleGenerator();
public:
    double next(int, int);
    
    static RandomDoubleGenerator* instance();
};

