class Solution {
public:
    int search(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) {
            return 0;
        }
        int fish = grid[i][j]; // Collect fish from the current cell
        grid[i][j] = 0; // Mark as visited
        
        // Explore all 4 possible directions
        fish += search(grid, i + 1, j);
        fish += search(grid, i - 1, j);
        fish += search(grid, i, j + 1);
        fish += search(grid, i, j - 1);
        
        return fish;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int maxFish = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 0) {
                    maxFish = max(maxFish, search(grid, i, j)); // Perform DFS and get the max fish
                }
            }
        }
        return maxFish;
    }
};
