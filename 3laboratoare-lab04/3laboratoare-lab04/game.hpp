#ifndef GAME_HPP
#define GAME_HPP

#include "board.hpp"
#include <memory>
using namespace std;

class Game {
public:
    shared_ptr<Board> board;
    char currentPlayer;

    Game();

    void switchPlayer();

    void play();
};

#endif
