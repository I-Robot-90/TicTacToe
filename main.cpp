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
        for (auto & i : grid) {
            for (char j : i) {
                cout << j << "\t";
            }
            cout << endl;
        }
    }

    char xPlay(int &i, int &j) {
        cout << "choose index you want to play in" << endl;
        cout << "Player 1" << endl;
        cout << "Row: " << endl;
        cin >> i;
        cout << "Column: " << endl;
        cin >> j;
        cout << i << ", " << j << endl;
        if (grid[i][j] == vertical || grid[i][j] == horizontal) {
            cout << "Please select an index from 1, 3 and 5" << endl;
            xPlay(i, j);
        }

       return grid[i][j] = xToken;
    }

    char oPlay(int &i, int &j) {
        cout << "choose index you want to play in" << endl;
        cout << "Player 2" << endl;
        cout << "Row: " << endl;
        cin >> i;
        cout << "Column: " << endl;
        cin >> j;
        cout << i << ", " << j << endl;

        if (grid[i][j] == vertical || grid[i][j] == horizontal) {
            cout << "Please select an index from 1, 3 and 5" << endl;
            oPlay(i, j);
        }

           return grid[i][j] = oToken;
    }

    void play() {
        int i;
        int j;

        xPlay(i, j);
        printBoard();

        oPlay(i, j);
        printBoard();


        if(grid[1][1] == grid[3][3]) {
            cout << "You Win!" << endl;
        }
        else
            play();
    }
};

    int main() {
        cout << "Let's play a game of Xs & Os" << endl;
        Board().printBoard();
        cout << endl;
        Board().play();
        return 0;
    }