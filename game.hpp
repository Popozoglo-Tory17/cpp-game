#ifndef GAME_HPP
#define GAME_HPP

#include "board.hpp"

class Game {
public:
    Board board;
    char currentPlayer;

    Game();

    void switchPlayer();

    void play();
};

#endif