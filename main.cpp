#include <iostream>

using namespace std;



class IBoard{
public:
    const static int rows = 3;
    const static int cols = 3;
    char grid[rows][cols]{};
    char token = ' ';

    void printBoard();

    char xPlay(int &i, int &j);

    char oPlay(int &i, int &j);

    void play();

    bool threeRCD(char& beeToken);
};

class Board : public IBoard{
};

char IBoard::xPlay(int &i, int &j) {
    token = 'x';
    cout << "choose index you want to play in" << endl;
    cout << "Player 1" << endl;
    cout << "Row: " << endl;
    cin >> i;
    cout << "Column: " << endl;
    cin >> j;
    cout << i << ", " << j << endl;

    if (i > 3 || j > 3) {
        cout << "Please choose an index between 1, 2 and 3" << endl;
        xPlay(i, j);
    }

    return grid[i - 1][j - 1] = token;

}

char IBoard::oPlay(int &i, int &j) {
        token = 'o';
        cout << "choose index you want to play in" << endl;
        cout << "Player 2" << endl;
        cout << "Row: " << endl;
        cin >> i;
        cout << "Column: " << endl;
        cin >> j;
        cout << i << ", " << j << endl;

        if (i > 3 || j > 3) {
            cout << "Please choose an index between 1, 2 and 3" << endl;
            oPlay(i, j);
        }

        return grid[i - 1][j - 1] = token;
}

void IBoard::printBoard() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << grid[i][j];
            if (j < cols - 1)
                cout << " |     ";
        }
        cout << endl;
        if (i < rows - 1)
            cout << "- - - - - - -" << endl;
    }
}


void IBoard::play() {
    int row;
    int col;
    char newToken;

    xPlay(row, col);
    printBoard();

    oPlay(row, col);
    printBoard();

    threeRCD(newToken);

}

bool IBoard::threeRCD(char& token) {
    if (token == 'x' && ((grid[0][0] == token) && (grid[1][1] == token) && (grid[2][2]== token)) ||
    token == 'o' && (grid[0][0] == token) && (grid[1][1] == token) && (grid[2][2] == token)){
        return true;
    }
    play();
    return false;
}


int main() {
        cout << "Let's play a game of Xs & Os" << endl;
        Board board;
        board.printBoard();
        cout << endl;
        board.play();
        return 0;
    }