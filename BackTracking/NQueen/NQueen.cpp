#include <iostream>
using namespace std;

const int N = 4; // You can change this value for N-Queens (e.g., 4, 8, etc.)
int board[N][N]; // Chessboard initialized with 0

// Function to print the board

void printBoard() {
    
    for (int i = 0; i < N; i++) {
        
        for (int j = 0; j < N; j++) {
            if(board[i][j] == 1) cout <<"Q ";
            else cout <<". ";
        }
        
        cout << endl;
    }

    cout << endl;
}

// Check if placing a queen at board[row][col] is safe

bool isSafe(int row, int col) {
    
    // Check this column

    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false;
    }

    // Check upper-left diagonal

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    // Check upper-right diagonal

    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) return false;
    }

    return true;
}

// Solve using backtracking

bool NQueen(int row) {
    if (row == N) { // All queens placed
        
        printBoard();
        return true;
    }

    bool res = false;
    
    for (int col = 0; col < N; col++) {
        
        if (isSafe(row, col)) {
            board[row][col] = 1; // Place queen
            res = NQueen(row + 1) || res;
            board[row][col] = 0; // Backtrack
        }
    }

    return res;
}

int main() {
    
    if (!NQueen(0)) {
        cout << "No solution exists" << endl;
    }

    return 0;
}

/*

Time Complexity  - O(N × N!)
Space Complexity - O(N²) (board) + O(N) (recursion)

*/