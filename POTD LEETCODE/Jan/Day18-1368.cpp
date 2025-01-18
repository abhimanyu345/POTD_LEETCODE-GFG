class Solution {
public:
    struct Cell {
    int x, y, cost;
};

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
    vector<vector<int>> cost(m, vector<int>(n, INT_MAX)); // Cost matrix
    deque<Cell> dq;
    
    
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    
    dq.push_front({0, 0, 0});
    cost[0][0] = 0;

    while (!dq.empty()) {
        Cell cur = dq.front();
        dq.pop_front();

        // If we reached the bottom-right corner, return the cost
        if (cur.x == m - 1 && cur.y == n - 1) {
            return cur.cost;
        }

        // Try moving in all 4 directions
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                int newCost = cur.cost + (grid[cur.x][cur.y] == i + 1 ? 0 : 1);
                
                if (newCost < cost[nx][ny]) {
                    cost[nx][ny] = newCost;
                    if (newCost == cur.cost) {
                        dq.push_front({nx, ny, newCost}); // Priority for 0-cost moves
                    } else {
                        dq.push_back({nx, ny, newCost});
                    }
                }
            }
        }
    }

    return -1; // This should never be reached
    }
};