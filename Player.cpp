#include <iostream>
#include <string>

using namespace std;

class Player{
    string name;
    int position;

    public:
    Player(string name, int position){
        this->name = name;
        this->position = position;
        cout<<"Created player "<<this->name<<" at poisiton "<<this->position<<endl;
    }

    string getName(){
        return this->name;
    }

    int getPosition(){
        return this->position;
    }

    void setPosition(int position){
        this->position = position;
    }

};