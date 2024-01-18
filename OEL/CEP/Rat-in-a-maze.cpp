#include <bits/stdc++.h>

using namespace std;

// Function to find the paths in a matrix
void findPathHelper(int row, int col, vector<vector<int>> &matrix, int rows, vector<string> &ans, string move,
                    vector<vector<int>> &vis) {
    // If we reach the bottom-right cell, add the current path to the answer
    if (row == rows - 1 && col == rows - 1) {
        ans.push_back(move);
        return;
    }

    // Check and explore the downward direction
    if (row + 1 < rows && !vis[row + 1][col] && matrix[row + 1][col] == 1) {
        vis[row][col] = 1;
        findPathHelper(row + 1, col, matrix, rows, ans, move + 'D', vis);
        vis[row][col] = 0;
    }

    // Check and explore the left direction
    if (col - 1 >= 0 && !vis[row][col - 1] && matrix[row][col - 1] == 1) {
        vis[row][col] = 1;
        findPathHelper(row, col - 1, matrix, rows, ans, move + 'L', vis);
        vis[row][col] = 0;
    }

    // Check and explore the right direction
    if (col + 1 < rows && !vis[row][col + 1] && matrix[row][col + 1] == 1) {
        vis[row][col] = 1;
        findPathHelper(row, col + 1, matrix, rows, ans, move + 'R', vis);
        vis[row][col] = 0;
    }

    // Check and explore the upward direction
    if (row - 1 >= 0 && !vis[row - 1][col] && matrix[row - 1][col] == 1) {
        vis[row][col] = 1;
        findPathHelper(row - 1, col, matrix, rows, ans, move + 'U', vis);
        vis[row][col] = 0;
    }
}

// Function to find paths in a matrix
vector<string> findPath(vector<vector<int>> &matrix, int rows) {
    vector<string> ans;
    vector<vector<int>> vis(rows, vector<int>(rows, 0));

    // If the starting cell is valid, start the path finding
    if (matrix[0][0] == 1) {
        findPathHelper(0, 0, matrix, rows, ans, "", vis);
    }
    return ans;
}

// Function to print a matrix
void printMatrix(vector<vector<int>> &matrix) {
    for (auto &row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows = 4;

    // Input matrix
    vector<vector<int>> matrix = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

    // Print the input matrix
    cout << "Input Matrix:\n";
    printMatrix(matrix);

    // Find and display paths
    vector<string> result = findPath(matrix, rows);
    if (result.size() == 0)
        cout << "No valid paths found.";
    else {
        cout << "Paths:\n";
        for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
