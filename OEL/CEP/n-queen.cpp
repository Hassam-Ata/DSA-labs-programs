#include <bits/stdc++.h>

using namespace std;

// Function to check if placing a queen at given position (row, col) is safe
bool isSafe(int row, int col, vector<string> &board, int n)
{
    // Check for queens in the same row to the left
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    // Check for queens in the same column above
    col = col;
    row = row;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }

    // Check for queens in the upper-left diagonal
    col = col;
    row = row;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    // If no conflicts found, the position is safe
    return true;
}

// Recursive function to solve N-Queens problem using backtracking
void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
    // If all queens are placed successfully, add the solution to the result
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    // Try placing a queen in each row of the current column
    for (int row = 0; row < n; row++)
    {
        // Check if it's safe to place a queen at the current position
        if (isSafe(row, col, board, n))
        {
            // Place the queen at the current position
            board[row][col] = 'Q';

            // Recursively try placing queens in the next columns
            solve(col + 1, board, ans, n);

            // Backtrack: Remove the queen from the current position
            board[row][col] = '.';
        }
    }
}

// Function to find all possible solutions for N-Queens problem
vector<vector<string>> solveNQueens(int n)
{
    // Initialize the result vector to store all solutions
    vector<vector<string>> ans;

    // Initialize the chessboard with empty cells
    vector<string> board(n, string(n, '.'));

    // Start the recursive backtracking algorithm
    solve(0, board, ans, n);

    // Return the list of solutions
    return ans;
}

int main()
{
    int n = 4; // Set the size of the chessboard and number of queens
    vector<vector<string>> ans = solveNQueens(n);

    // Print each solution
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Arrangement " << i + 1 << "\n";
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j];
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
