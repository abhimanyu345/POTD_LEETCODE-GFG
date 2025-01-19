struct Cell {
    int row, col, height;
    Cell(int r, int c, int h) : row(r), col(c), height(h) {}
    bool operator>(const Cell& other) const {
        return height > other.height; // Min-heap based on height
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if (m < 3 || n < 3) return 0; // No space to trap water

        priority_queue<Cell, vector<Cell>, greater<Cell>> minHeap;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Push all boundary cells into the heap
        for (int i = 0; i < m; i++) {
            minHeap.emplace(i, 0, heightMap[i][0]);
            minHeap.emplace(i, n - 1, heightMap[i][n - 1]);
            visited[i][0] = visited[i][n - 1] = true;
        }
        for (int j = 1; j < n - 1; j++) {
            minHeap.emplace(0, j, heightMap[0][j]);
            minHeap.emplace(m - 1, j, heightMap[m - 1][j]);
            visited[0][j] = visited[m - 1][j] = true;
        }

        int waterTrapped = 0;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Process cells in min-heap
        while (!minHeap.empty()) {
            Cell curr = minHeap.top();
            minHeap.pop();

            for (auto& dir : directions) {
                int ni = curr.row + dir[0], nj = curr.col + dir[1];

                if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj]) {
                    visited[ni][nj] = true;
                    waterTrapped += max(0, curr.height - heightMap[ni][nj]);
                    minHeap.emplace(ni, nj, max(curr.height, heightMap[ni][nj]));
                }
            }
        }

        return waterTrapped;
    }
};