#include <iostream>

using namespace std;



class IBoard{
public:
    const static int rows = 3;
    const static int cols = 3;
    char grid[rows][cols]{};
    pair<char, int> token;

    int printBoard();

    int xPlay(int &i, int &j);

    int oPlay(int &i, int &j);

    void play();

    pair<bool, bool> is_winner() {
        int sumb = 0;
        int sumd = 0;

        for(int i = 0; i != 3; ++i){
            int row_sum = 0;
            int col_sum = 0;

            for(int j = 0; j != 3; j++){
                row_sum += grid[3 * i][ j];
                col_sum += grid[3 * j][i];

                if(row_sum == -3 || col_sum == -3){
                    return {true, false};
                }
                if(row_sum == 3 || col_sum == 3){
                    return {false, true};
                }

                sumb += grid[i][i];
                sumd += grid[i][2 - i];
            }

        }
        if(sumb == -3 || sumd == -3){
            return {true, false};
        }
        if(sumb == 3 || sumd == 3){
            return {false, true};
        }
        return {false, false};
    }

    void Check();
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

    if (i > 3 || j > 3) {
        cout << "Please choose an index between 1, 2 and 3" << endl;
        xPlay(i, j);
    }

    //is_winner();
    grid[i - 1][j - 1] = token.first;
    return printBoard();
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

        if (i > 3 || j > 3) {
            cout << "Please choose an index between 1, 2 and 3" << endl;
            oPlay(i, j);
        }
        //is_winner();
    grid[i - 1][j - 1] = token.first;
        return printBoard();
}


void IBoard::play() {
    int row;
    int col;

    xPlay(row, col);

    oPlay(row, col);
    //printBoard();

    Check();
}

void IBoard::Check() {
    if(is_winner().first){
        cout << "Player 1 Wins!" << endl;
    }
    else if (is_winner().second){
        cout << "Player 2 Wins!" << endl;
    }
    else{
        play();
    }
}




int main() {
        cout << "Let's play a game of Xs & Os" << endl;
        Board board;
        board.printBoard();
        cout << endl;
        board.play();
        return 0;
    }