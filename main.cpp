#include <iostream>
#include "Player.cpp"
#include "Snake.cpp"
#include "Ladder.cpp"
#include "Board.cpp"
#include "Dice.cpp"


using namespace std;

int main(){
    //Get Board Size
    int boardSize;
    do {
        cout<<"What is the size of board you want in nxn format (between 2 and 10)!"<<endl;
        cin>>boardSize;

        if(boardSize < 2 || boardSize > 10)
        {
            cout<<"Invalid board size. Please enter a size between 2 and 10."<<endl;
        }
    } while(boardSize < 2 || boardSize > 10);

    int boardMaxSize = boardSize * boardSize;
    
    //Get no of players
    int playerNo;
    do {
        cout<<"How many players you want to start the game with?"<<endl;
        cin>>playerNo;

        if(playerNo < 2)
        {
            cout<<"Cannot start a game with "<<playerNo<<" players!"<<endl;
        }
    } while(playerNo < 2);

    //Get player details
    string name;
    queue<Player> players;
    for (int i = 0; i < playerNo; i++)
    {   
        cout<<"Enter name of Player "<<i + 1<<endl;
        cin>>name;
        players.push(Player(name, 0));
    }

    vector<Player> winners;

    //Get dice count
    int diceCount;
    do {
        cout << "How many dice do you want to use?" << endl;
        cin >> diceCount;

        if (diceCount < 1) {
            cout << "Invalid number of dice. Please enter at least 1." << endl;
        }
    } while (diceCount < 1);

    //Get no of snakes and their details
    int snakeSize;
    vector<Snake> snakeList;
    cout<<"How many snakes you want in your board?"<<endl;
    cin>>snakeSize;

    int head;
    int tail;
    for (int i = 0; i < snakeSize; i++)
    {   
        cout<<"Enter head position of snake "<<i+1 <<" : "<<endl;
        cin>>head;
        cout<<"Enter tail position of snake "<<i+1 <<" : "<<endl;
        cin>>tail;
        snakeList.push_back(Snake(head,tail));
    }
    
    //Get no of ladders and their details
    int ladderSize;
    vector<Ladder> ladderList;
    cout<<"How many ladders you want in your board?"<<endl;
    cin>>ladderSize;

    int top;
    int bottom;
    for (int i = 0; i < ladderSize; i++)
    {   
        cout<<"Enter bottom position of ladder "<<i+1 <<" : "<<endl;
        cin>>bottom;
        cout<<"Enter top position of ladder "<<i+1 <<" : "<<endl;
        cin>>top;
        ladderList.push_back(Ladder(bottom,top));
    }

    //Initialize the board with snakes, ladders and dices
    Board board = Board(boardSize, snakeList, ladderList, diceCount);
    map<int, int> snakeMap = board.getSnakeMap();
    map<int, int> ladderMap = board.getLadderMap();

    //Start the game
    int maxTurns =0;
    while(players.size() > 1){
        Player currentPlayer = players.front();
        players.pop();
        int currentPosition = currentPlayer.getPosition();
        int diceValue = board.rollDice();
        int newPosition = currentPlayer.getPosition() + diceValue;

        cout<<currentPlayer.getName()<<"'s position is "<<currentPosition<<" and dice value is "<<diceValue<<", so the expected position is "<<newPosition<<endl;

        if(newPosition <= boardMaxSize){
            //Check if player got bit by a snake
            if(snakeMap.find(newPosition) != snakeMap.end()){
                cout<<currentPlayer.getName()<<" got bit by a snake at "<<newPosition<<" and the got dropped to "<<snakeMap[newPosition]<<endl;
                currentPlayer.setPosition(snakeMap[newPosition]);
            }
            //check of player climbed a ladder
            else if(ladderMap.find(newPosition) != ladderMap.end()){
                cout<<currentPlayer.getName()<<" got a ladder at "<<newPosition<<" and climbed to "<<ladderMap[newPosition]<<endl;
                currentPlayer.setPosition(ladderMap[newPosition]);
                if(newPosition == boardMaxSize){
                    cout<<currentPlayer.getName()<<" you won! Congrats!"<<endl;
                    winners.push_back(currentPlayer);
                    if(players.size() == 1)
                    {
                        cout<<"Stopping game as only 1 player is left to play!"<<endl;
                        winners.push_back(players.front());
                        break;
                    }
                }
                else{
                    players.push(currentPlayer);
                }
            }
            //move ahead normally
            else{
                currentPlayer.setPosition(newPosition);
                if(newPosition == boardMaxSize){
                    cout<<currentPlayer.getName()<<" you won! Congrats!"<<endl;
                    winners.push_back(currentPlayer);
                    if(players.size() == 1)
                    {
                        cout<<"Stopping game as only 1 player is left to play!"<<endl;
                        winners.push_back(players.front());
                        break;
                    }
                }
                else{
                    players.push(currentPlayer);
                }
            }
        }
        //check if new position exceeds board limit 
        else{
            cout<<currentPlayer.getName()<<" cannot move as new position exceeds the board limits!"<<endl;
            players.push(currentPlayer);
        }
        
        maxTurns++;
        //stop game if total no of turns exceeds max turns allowed
        if(maxTurns > 100){
            cout<<"Total no of turns exceeds the max turns limit! Stopping the game!"<<endl;
            break;
        }
    }

    //Print the winners
    for(int i =0 ; i<winners.size(); i++)
    {
        cout<<"Rank "<<i+1<< " : "<<winners[i].getName()<<endl;
    }
    return 0;
}