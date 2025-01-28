#include <iostream>
#pragma once
using namespace std;

class Snake{
    private:
    int mouth;
    int tail;

    public:
    Snake(int mouth, int tail){
        this->mouth = mouth;
        this->tail = tail;
    };

    int getMouth(){
        return this->mouth;
    }

    int getTail(){
        return this->tail;
    }
};