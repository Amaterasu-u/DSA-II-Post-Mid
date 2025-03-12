#include <iostream>
#include <vector>
using namespace std;


bool isSafe(const vector<string>& board, int row, int col, int n) {

    for (int i = 0; i < n; i++) {
        if (board[i][col] == 'Q')
            return false;
    }

    for (int j = 0; j < n; j++) {
        if (board[row][j] == 'Q')
            return false;
    }
    

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return false;
    }
    

    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q')
            return false;
    }
    
    return true;
}


void solveNQueens(int n, int row, vector<string>& board, vector<vector<string>>& solutions) {
    if (row == n) { // All queens are placed
        solutions.push_back(board);
        return;
    }

    for (int j = 0; j < n; j++) {
        if (isSafe(board, row, j, n)) {
            board[row][j] = 'Q';        
            solveNQueens(n, row + 1, board, solutions); 
            board[row][j] = '.';   
        }
    }
}

int main() {
    int n = 4; 
    vector<string> board(n, string(n, '.')); 
    vector<vector<string>> solutions;
    
    solveNQueens(n, 0, board, solutions);
    
    cout << "Total solutions for " << n << " queens: " << solutions.size() << "\n";
    
    if (!solutions.empty()) {
        cout << "One of the solutions:\n";
        for (int i = 0; i < n; i++) {
            cout << solutions[0][i] << "\n";
        }
    }
    
}
