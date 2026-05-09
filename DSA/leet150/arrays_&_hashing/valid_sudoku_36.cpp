#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) 
        {
            unordered_set<int> rows[9];    // rows[i] = digits seen in row i
            unordered_set<int> cols[9];    // cols[j] = digits seen in col j
            unordered_set<int> boxes[9];   // boxes[b] = digits seen in box b

            
            for (int i  = 0; i < 9; ++i) 
            {
                for (int j = 0; j < 9; j++) 
                {
                    if (board[i][j] == '.') continue;
                    int val = board[i][j] - '0';
                    int box = (i / 3) * 3 + (j / 3);

                    if (rows[i].count(val) || cols[j].count(val) || boxes[box].count(val))
                    {
                        
                        return false;
                    }

                    rows[i].insert(val);
                    cols[j].insert(val);
                    boxes[box].insert(val);
                }
            }
            return true;
        }

        
    };

