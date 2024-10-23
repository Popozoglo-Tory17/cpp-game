#ifndef BOARD_HPP
#define BOARD_HPP

class Board {
public:
    char grid[3][3];
    Board();

    void printBoard();

    char checkWin();

    bool isFull();

    bool markMove(int row, int col, char player);
};

#endif
