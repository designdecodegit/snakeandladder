#include <iostream>
#include<queue>
#include<map>
#include"Snake.cpp"
#include"Ladder.cpp"
#include"Dice.cpp"

using namespace std;

class Board{
    private:
    int size;
    map<int, int> snakeMap;
    map<int, int> ladderMap;
    int diceCount;
    Dice dice;

    public:
    Board(int size, vector<Snake> snakeList, vector<Ladder> ladderList, int diceCount){
        this->size = size*size;
        this->diceCount = diceCount;
        for(int i = 0; i<snakeList.size() ; i++){
            snakeMap[snakeList[i].getMouth()] = snakeList[i].getTail();
            cout<<"Adding snake from "<<snakeList[i].getMouth()<<" to "<<snakeList[i].getTail()<<endl;
        }
        for(int i = 0; i<ladderList.size() ; i++){
            ladderMap[ladderList[i].getBottom()] = ladderList[i].getTop();
            cout<<"Adding Ladder with top at "<<ladderList[i].getTop()<<" and bottom at "<<ladderList[i].getBottom()<<endl;
        }
        cout<<"Board of size "<<this->size<<" is successfully created!"<<endl;
    }

    map<int, int> getSnakeMap(){
        return this->snakeMap;
    }

    map<int, int> getLadderMap(){
        return this->ladderMap;
    }

    int rollDice(){
        return (this->diceCount)*(dice.roll());
    }

};