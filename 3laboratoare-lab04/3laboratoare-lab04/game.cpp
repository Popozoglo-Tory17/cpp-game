#include "game.hpp"
#include <iostream>
#include <sstream>
using namespace std;    

Game::Game() : board(make_shared<Board>()), currentPlayer('X') {}

void Game::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void Game::play() {
    int row, col;
    string input;
    char winner = ' ';

    while (true) {
        board->printBoard();

        cout << "Jucătorul " << currentPlayer << ", introdu coordonatele (rând și coloană): ";
        getline(cin, input);
        istringstream iss(input);
        if (!(iss >> row >> col)) {
            cout << "Intrare invalidă. Încercați din nou.\n";
            continue;
        }

        if (row < 0 || row > 2 || col < 0 || col > 2) {
            cout << "Coordonate în afara limitelor. Încercați din nou.\n";
            continue;
        }

        if (!board->markMove(row, col, currentPlayer)) {
            cout << "Mutare invalidă. Încercați din nou.\n";
            continue;
        }

        winner = board->checkWin();
        if (winner != ' ') {
            board->printBoard();
            cout << "Jucătorul " << winner << " a câștigat!\n";
            break;
        }

        if (board->isFull()) {
            board->printBoard();
            cout << "Jocul s-a terminat cu egalitate!\n";
            break;
        }

        switchPlayer();
    }
}
