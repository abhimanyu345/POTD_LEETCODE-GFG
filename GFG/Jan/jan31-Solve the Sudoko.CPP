bool isValid(vector<vector<int>> &mat, int row, int col, int num) {
        for (int i = 0; i < 9; i++) {
            if (mat[row][i] == num) return false; // Check row
            if (mat[i][col] == num) return false; // Check column
            if (mat[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) return false; // Check 3x3 subgrid
        }
        return true;
    }

    // Backtracking function to solve the Sudoku.
    bool solve(vector<vector<int>> &mat) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (mat[row][col] == 0) { // Empty cell found
                    for (int num = 1; num <= 9; num++) {
                        if (isValid(mat, row, col, num)) { // Check validity
                            mat[row][col] = num; // Place the number
                            if (solve(mat)) return true; // Recursively solve
                            mat[row][col] = 0; // Backtrack if no solution
                        }
                    }
                    return false; // No valid number found, trigger backtrack
                }
            }
        }
        return true; // Sudoku solved
    }
    void solveSudoku(vector<vector<int>> &mat) {
        solve(mat);
    }