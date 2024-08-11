#include <iostream>

using namespace std;

class IBoard{
public:
    const static int rows = 3;
    const static int cols = 3;
    pair<char, int> grid[rows][cols]{};
    pair<char, int> token;

    int printBoard();

    int xPlay(int &i, int &j);

    int oPlay(int &i, int &j);

    int play();

    bool is_winner(int token);
};

class Board : public IBoard{
};

int IBoard::printBoard() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << grid[i][j].first;
            if (j < cols - 1)
                cout << " |     ";
        }
        cout << endl;
        if (i < rows - 1)
            cout << "- - - - - - - - - -" << endl;
    }
    return grid[rows - 1][cols - 1].second;
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
    grid[i - 1][j - 1].first = token.first;
    grid[i - 1][j - 1].second = token.second;
    printBoard();


    if (i > 3 || j > 3) {
        cout << "Please choose an index between 1, 2 and 3" << endl;
        xPlay(i, j);
    }
//    if (grid[i - 1][j - 1].second == oPlay(i, j)){
//        cout << "Please enter another cell" << endl;
//        xPlay(i, j);
//    }
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
        grid[i - 1][j - 1].first = token.first;
        grid[i - 1][j - 1].second = token.second;
        printBoard();

if (i > 3 || j > 3) {
            cout << "Please choose an index between 1, 2 and 3" << endl;
            oPlay(i, j);
        }
    return token.second;
}

int IBoard::play() {
    int row;
    int col;

    xPlay(row, col);
    oPlay(row, col);
    if (is_winner(xPlay(row, col))){
        cout << "Player 1 wins!" << endl;
        //return 0;
    } else
    if (is_winner(oPlay(row, col))){
        cout << "Player 2 wins!" << endl;
        //return 0;
    }if(!is_winner(xPlay(row, col)) && !is_winner(oPlay(row, col))){
        play();
    }
       return -1;
}

bool IBoard::is_winner(int tokenVal) {
    int row_sum = 0;
    int col_sum = 0;
    int sumb = 0;
    int sumd = 0;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; j++){
            row_sum += grid[i][j].second;
            col_sum += grid[j][i].second;
            if(row_sum == 3 * tokenVal || col_sum == 3 * tokenVal){
                if(tokenVal == 1){
                    cout << "Player 1 wins!" << endl;
                } else if (tokenVal == -1){
                    cout << "Player 2 wins!" << endl;
                }
                return true;
            }
        }
        sumb += grid[i][i].second;
        sumd += grid[i][2 - i].second;
        if(sumb == 3 * tokenVal || sumd == 3 * tokenVal){
            if(tokenVal == 1){
                cout << "Player 1 wins!" << endl;
            } else if (tokenVal == -1){
               cout << "Player 2 wins!" << endl;
            }
            return true;
        }
    }
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
