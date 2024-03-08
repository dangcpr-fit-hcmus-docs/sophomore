#include <iostream>

using namespace std;


class RandomIntegerGenerator {
private:
    inline static RandomIntegerGenerator* _instance = NULL;
    
    RandomIntegerGenerator();
public:
    int next(int);
    int next(int, int);
    
    static RandomIntegerGenerator* instance();
};