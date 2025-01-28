#pragma once
#include <cstdlib>
using namespace std;

class Dice{

    public:
    int roll(){
        return (rand() % 6) + 1;
    }

};