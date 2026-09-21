#include<vector>
#include<iostream>
#include<array>
#include<tuple>
using namespace std;
class Solution {
    public:
        void dfs(vector<vector<char>>& board,int row, int col) {
            vector<pair<int,int>> directions = {{0,-1},{-1,0},{0,1},{1,0}};
            if (board[row][col] == 'X' ||  board[row][col] == 't') {
                return;
            }
            
            board[row][col] = 't';
            
            for(auto [dr,dc] : directions) {
                int newrow = row + dr;
                int newcol = col + dc;
                if (0 <= newrow && newrow < board.size() && 0 <= newcol && newcol < board[0].size()) {
                    dfs(board,newrow,newcol);
                }
            }
        }
        void solve(vector<vector<char>>& board) {
            int rows = board.size();
            int cols = board[0].size();
            for(int i = 0; i < cols; i++) {
                dfs(board,0,i);
                dfs(board,rows-1,i);
            }
            for(int i = 0; i < rows; i++) {
                dfs(board,i,0);
                dfs(board,i,cols-1);
            }
            for (int r = 0; r < rows; r++) {
                for (int c = 0; c < cols; c++) {
                    if (board[r][c] == 'O') {
                        board[r][c] = 'X';
                    }
                    else if(board[r][c] == 't') {
                        board[r][c] = 'O';
                    }
                }
            }
        }
    };

/* int main() {
    vector<vector<char>> board;
    board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };
    Solution sol;
    sol.solve(board);

    for (int r = 0; r < board.size(); r++) {
        for (int c = 0; c < board[0].size(); c++) {
            cout << board[r][c] << ' ';
        }
    cout << '\n';
    }
} */