#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>
#include <string>

class Board {
public:
    std::array<std::array<char, 3>, 3> grid;
    Board();

    void printBoard();

    char checkWin();

    bool isFull();

    bool markMove(int row, int col, char player);
};

#endif
