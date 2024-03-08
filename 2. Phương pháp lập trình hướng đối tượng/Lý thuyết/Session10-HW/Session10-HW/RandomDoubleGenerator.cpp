#include "RandomDoubleGenerator.h"

RandomDoubleGenerator::RandomDoubleGenerator() {
}

RandomDoubleGenerator* RandomDoubleGenerator::instance() {
    if (_instance == NULL) {
        _instance = new RandomDoubleGenerator();
    }
    
    return _instance;
}

double RandomDoubleGenerator::next(int left, int right) {
    int result = left + (double)(rand()) / ((double)(RAND_MAX/(right - left)));
    
    return result;
}