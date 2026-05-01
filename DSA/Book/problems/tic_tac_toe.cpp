/*3-8. [5] Tic-tac-toe is a game played on an n×n board (typically n = 3) where two
players take consecutive turns placing “O” and “X” marks onto the board cells.
The game is won if n consecutive “O” or ‘X” marks are placed in a row, column,
or diagonal. Create a data structure with O(n) space that accepts a sequence
of moves, and reports in constant time whether the last move won the game.*/

#include <cstdlib>
#include <vector>
#include <tuple>
#include <iostream>
#define BOARD_SIZE 3

using namespace std;

int tic_tac_toe(vector<tuple<int,int>> moves); 

int main(void){

    vector<tuple<int,int>> moves;

    int result = tic_tac_toe(moves);

    cout << "Winner: ";
    if(result == 1)
    {
        cout << 'X';
    }
    else if (result == -1) 
    {
        cout << 'O';
    }
    else 
    {
        cout << "Tie";
    }

}

/* The alghoritim here since the question requires O(n) space was to separate the winning
    possibilites being  8 in total n rows, n colns and diagonal + antidigoanl on a n x n board
    which is n + n + 2 possilites, for those we simplified the row and collum in a frequency array
    since they work the same.*/
int tic_tac_toe(vector<tuple<int,int>> moves)
{
    int row[BOARD_SIZE] = {0,0,0};
    int col[BOARD_SIZE] = {0,0,0};
    int diag = 0;
    int anti_diag = 0;

    for (int i = 0 ; i < moves.size(); ++i) 
    {
        int r = get<0>(moves[i]);
        int c = get<1>(moves[i]);

        // X == 1 and O == -1 so we would just have a coprrect answer if 
        // we get any BOARD_SIZE or -BOARD_SIZE
        int mover = (i % 2 == 0) ? 1 : -1;

        row[r] += mover;
        col[c] += mover;

        
        if (r == c)
        {
             diag+= mover;
             // calcualting diag match
             if(abs(diag) == BOARD_SIZE) return mover;
        }
        if (r + c == BOARD_SIZE - 1) 
        {
            anti_diag += mover;
            // anti diagonal match
            if(abs(anti_diag) == BOARD_SIZE) return mover;
        }
        // checking for wins rows/ collums
        if (abs(row[r]) == BOARD_SIZE) return mover;
        if (abs(col[c]) == BOARD_SIZE) return mover;
    }

    // we will return mover ( that can be 1 or -1) or 0 meaning a winner or a tie
    return 0;
}

