#include <iostream>
#pragma once
using namespace std;

class Ladder{
    private:
    int bottom;
    int top;

    public:
    Ladder(int bottom, int top){
        this->bottom = bottom;
        this->top = top;
    }

    int getBottom(){
        return this->bottom;
    }

    int getTop(){
        return this->top;
    }
};