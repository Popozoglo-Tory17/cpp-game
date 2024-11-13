#include "board.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

Board::Board() {
    for (auto& row : grid) {
        row.fill(' ');
    }
}

void Board::printBoard() {
    cout << "  0 1 2\n";
    for (int i = 0; i < 3; i++) {
        cout << i << " ";
        for (int j = 0; j < 3; j++) {
            cout << grid[i][j];
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "  -----\n";
    }
}

bool Board::markMove(int row, int col, char player) {
    if (grid[row][col] == ' ') {
        grid[row][col] = player;
        return true;
    }
    return false;
}

char Board::checkWin() {
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] != ' ' && all_of(grid[i].begin(), grid[i].end(),
            [this, i](char c) { return c == grid[i][0]; }))
            return grid[i][0];
    }
    for (int i = 0; i < 3; i++) {
        char c = grid[0][i];
        if (c != ' ' && grid[1][i] == c && grid[2][i] == c)
            return c;
    }
    char c = grid[1][1];
    if (c != ' ') {
        if (grid[0][0] == c && grid[2][2] == c)
            return c;
        if (grid[0][2] == c && grid[2][0] == c)
            return c;
    }
    return ' ';
}

bool Board::isFull() {
    return all_of(grid.begin(), grid.end(), [](const array<char, 3>& row) {
        return all_of(row.begin(), row.end(), [](char c) { return c != ' '; });
    });
}
