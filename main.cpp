#include <iostream>
using namespace std;

char xToken;
char oToken;
char vertical = '|';
char horizontal = '-';

class Board {
public:
    const static int rows = 5;
    const static int cols = 5;
    char grid[rows][cols]{};

    Board() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (j == 1 || j == 3) {
                    grid[i][j] = vertical;
                }

                if (i == 1 || i == 3) {
                    grid[i][j] = horizontal;
                }
            }
        }
    }

    void printBoard() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << grid[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void play() {
        printBoard();
        int i = 0;
        int j = 0;
        while(i < rows && j < cols){
            i++;
            j++;
            if (Board().grid[i][j] != vertical && Board().grid[i][j] != horizontal) {
                cin >> grid[i][j];
                printBoard();
            }
        }
        }
    };


int main() {
    cout << "Let's play a game of Xs & Os" << endl;
    Board().play();
    return 0;
    }
