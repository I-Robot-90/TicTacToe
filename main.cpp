#include <iostream>

using namespace std;

char xToken = 'x';
char oToken = 'o';
char vertical = '|';
char horizontal = '-';

class Board {
public:
    const static int rows = 6;
    const static int cols = 6;
    char grid[rows][cols]{};

    Board() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                grid[i][0] = '0' + i;
                grid[0][j] = '0' + j;

                if (j == 2 || j == 4) {
                        grid[i][j] = vertical;
                    }

                    if (i == 2 || i == 4) {
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

        cout << "choose index you want to play in" << endl;
        cin >> i;
        cout << ",";
        cin >> j;
        cout << i << ", " << j << endl;

            if (Board().grid[i][j] != vertical && Board().grid[i][j] != horizontal) {
                grid[i][j] = xToken;
                printBoard();
            }
    }
};


int main() {
    cout << "Let's play a game of Xs & Os" << endl;
    cout << endl;
    Board().play();
    return 0;
    }
