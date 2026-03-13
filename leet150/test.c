// gcc -o test test.c && ./test

#include <stdio.h>
#include <stdlib.h>
int isValidSudoku(char** board, int boardSize, int* boardColSize) {
    
    

    for(int i = 0; i < boardSize ; i++){

        int seen_row[9] = {0};
        int seen_col[9] = {0};
        for (int j = 0; j < *boardColSize; j++)
        {

        // ignore anuthing besides numbers
        int row_num    = board[i][j] - 48;

        if(row_num < 0 || row_num > 9) { 
            // if any number in collum rep
        
            if (seen_row[row_num - 1] == 1){
                return 0;
            }
            else {
                seen_row[row_num - 1] = 1;
            }
        }
        
        // COLLUMN
        int collum_num = board[j][i] - 48; // or '0'

        if(collum_num < 0 || collum_num > 9) 
        { 
            // if any number in collum rep
        
            if (seen_col[collum_num - 1] == 1){
                return 0;
            }
            else {
                seen_col[collum_num - 1] = 1;
            }
        }

        }
        for (int i = 0; i < boardSize; i++) 
        {
            printf("%d ", seen_row[i]);
        }
        
    puts("");
    }

    
    return 0;
}
int main(void) {
    char *board[] = {
        "53..7....",
        "6..135...",
        ".98....6.",
        "89..6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79"
    };

    int boardSize = 9;
    int boardColSize[] = {9,9,9,9,9,9,9,9,9};

    isValidSudoku(board, boardSize, boardColSize);
}