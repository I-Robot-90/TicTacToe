#include <iostream>

using namespace std;



class IBoard{
public:
    const static int rows = 3;
    const static int cols = 3;
    int grid[rows][cols]{};
    pair<char, int> token;

    int printBoard();

    int xPlay(int &i, int &j);

    int oPlay(int &i, int &j);

    void play();

    bool is_winner(int token);
};

class Board : public IBoard{
};


int IBoard::printBoard() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << grid[i][j];
            if (j < cols - 1)
                cout << " |     ";
        }
        cout << endl;
        if (i < rows - 1)
            cout << "- - - - - - - - - -" << endl;
    }
    return grid[rows - 1][cols - 1];
}

int IBoard::xPlay(int &i, int &j) {
    token.first = 'x';
    token.second = 1;
    cout << "choose index you want to play in" << endl;
    cout << "Player 1" << endl;
    cout << "Row: " << endl;
    cin >> i;
    cout << "Column: " << endl;
    cin >> j;
    cout << i << ", " << j << endl;
    grid[i - 1][j - 1] = token.second;
    printBoard();

    if (i > 3 || j > 3) {
        cout << "Please choose an index between 1, 2 and 3" << endl;
        xPlay(i, j);
    }

    return token.second;
}

int IBoard::oPlay(int &i, int &j) {
        token.first = 'o';
        token.second = -1;
        cout << "choose index you want to play in" << endl;
        cout << "Player 2" << endl;
        cout << "Row: " << endl;
        cin >> i;
        cout << "Column: " << endl;
        cin >> j;
        cout << i << ", " << j << endl;
        grid[i - 1][j - 1] = token.second;
        printBoard();

if (i > 3 || j > 3) {
            cout << "Please choose an index between 1, 2 and 3" << endl;
            oPlay(i, j);
        }
    return token.second;
}


void IBoard::play() {
    int row;
    int col;

        xPlay(row, col);
        oPlay(row, col);
    if(!is_winner(token.second)){
        play();
    }
    cout << "PLayer wins!" << endl;
}

bool IBoard::is_winner(int tokenVal) {
    int sumb = 0;
    int sumd = 0;
    for(int i = 0; i != 3; ++i){
        int row_sum[3];
        int col_sum[3];


        for(int j = 0; j != 3; j++){
            row_sum[i] += grid[i][j];
            col_sum[j] += grid[i][j];
            if(row_sum[i] == -3 * tokenVal || col_sum[j] == - 3 * tokenVal){
//              return {true, false};
                return true;
            }
            if(row_sum[i] == 3 * tokenVal || col_sum[j] == 3 * tokenVal){
//                return {false, true};
                return true;
            }
        }
        sumb += grid[i][i];
        sumd += grid[i][2 - i];
        if(sumb == -3 * tokenVal || sumd == -3 * tokenVal){
//        return {true, false};
            return true;
        }
        if(sumb == 3 * tokenVal || sumd == 3 * tokenVal){
//        return {false, true};
            return true;
        }
    }
//    return {true, false};
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
