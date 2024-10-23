#include "game.hpp"
using namespace std;

#include <iostream>

Game::Game() {
    currentPlayer = 'X';
}

void Game::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void Game::play() {
    int row, col;
    char winner = ' ';

    while (true) {
        board.printBoard();

        cout << "Jucatorul " << currentPlayer << ", introdu coordonatele (rand si coloana): ";
        cin >> row >> col;

        if (!board.markMove(row, col, currentPlayer)) {
            cout << "Mutare invalida. incearca din nou.\n";
            continue;
        }

        winner = board.checkWin();
        if (winner != ' ') {
            board.printBoard();
            cout << "Jucatorul " << winner << " a castigat!\n";
            break;
        }

        if (board.isFull()) {
            board.printBoard();
            cout << "Jocul s-a terminat cu egalitate!\n";
            break;
        }

        switchPlayer();
    }
}
