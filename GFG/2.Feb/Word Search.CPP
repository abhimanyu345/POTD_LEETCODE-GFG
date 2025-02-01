bool dfs(vector<vector<char>>& mat, string& word, int i, int j, int index) {
        if (index == word.size()) return true; // Word found

        int n = mat.size(), m = mat[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || mat[i][j] != word[index]) 
            return false; // Out of bounds or mismatch

        char temp = mat[i][j];
        mat[i][j] = '#'; // Mark as visited

        // Explore all four directions
        bool found = dfs(mat, word, i + 1, j, index + 1) ||
                     dfs(mat, word, i - 1, j, index + 1) ||
                     dfs(mat, word, i, j + 1, index + 1) ||
                     dfs(mat, word, i, j - 1, index + 1);

        mat[i][j] = temp; // Backtrack

        return found;
    }

    bool isWordExist(vector<vector<char>>& mat, string& word) {
        int n = mat.size(), m = mat[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0] && dfs(mat, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }