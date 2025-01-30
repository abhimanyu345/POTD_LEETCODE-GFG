vector<vector<int>> nQueen(int n) {
        vector<vector<int>> results;
        vector<int> board;
        unordered_set<int> columns, pos_diagonal, neg_diagonal;
        
        solve(0, n, board, results, columns, pos_diagonal, neg_diagonal);
        return results;
    }

private:
    void solve(int col, int n, vector<int>& board, vector<vector<int>>& results, 
               unordered_set<int>& columns, unordered_set<int>& pos_diagonal, unordered_set<int>& neg_diagonal) {
        if (col == n) {
            results.push_back(board);
            return;
        }
        
        for (int row = 1; row <= n; ++row) {
            if (columns.count(row) || pos_diagonal.count(row + col) || neg_diagonal.count(row - col)) 
                continue;
            
            // Place the queen
            board.push_back(row);
            columns.insert(row);
            pos_diagonal.insert(row + col);
            neg_diagonal.insert(row - col);
            
            // Recurse for the next column
            solve(col + 1, n, board, results, columns, pos_diagonal, neg_diagonal);
            
            // Backtrack
            board.pop_back();
            columns.erase(row);
            pos_diagonal.erase(row + col);
            neg_diagonal.erase(row - col);
        }
    }