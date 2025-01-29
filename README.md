# Snake and Ladder Game

## Overview
This is a simple console-based Snake and Ladder game implemented in C++. Players roll dice to advance on the board while encountering snakes and ladders that either move them forward or set them back. The game supports multiple players and customizable board sizes.

## Features
- User-defined board size (between 2x2 and 10x10).
- Support for multiple players.
- Configurable number of dice.
- Customizable snakes and ladders.
- Automatic game progression with win detection.
- Console-based interactive gameplay.

## Installation
To run this game, ensure you have a C++ compiler installed on your system.

1. Clone this repository:
   ```sh
   git clone https://github.com/designdecodegit/snake-and-ladder.git
   ```
2. Navigate to the project directory:
   ```sh
   cd snake-and-ladder
   ```
3. Compile the program:
   ```sh
   g++ main.cpp -o SnakeAndLadder
   ```
4. Run the game:
   ```sh
   ./SnakeAndLadder
   ```

## How to Play
1. Choose a board size (e.g., 3x3, 5x5, etc.).
2. Enter the number of players (minimum 2).
3. Input player names.
4. Select the number of dice to roll per turn.
5. Configure the number of snakes and their positions.
6. Configure the number of ladders and their positions.
7. The game begins, and players take turns rolling dice until one reaches the final tile.

## Game Rules
- Players roll dice and move forward by the rolled number.
- Landing on a snake moves the player back to its tail.
- Landing on a ladder moves the player up to its top.
- The first player to reach the final board position wins.
- The game stops when only one player remains.

## File Structure
- `main.cpp` - The main game logic.
- `Player.cpp` - Player class implementation.
- `Snake.cpp` - Snake class implementation.
- `Ladder.cpp` - Ladder class implementation.
- `Board.cpp` - Board setup and game mechanics.
- `Dice.cpp` - Dice rolling logic.

## Future Enhancements
- Add a graphical user interface (GUI).
- Implement network-based multiplayer support.
- Add AI-based computer players.

## License
This project is licensed under the MIT License.

## Contributing
Contributions are welcome! Feel free to open an issue or submit a pull request.

## Author
Developed by [Design Decode](https://github.com/designdecodegit).

