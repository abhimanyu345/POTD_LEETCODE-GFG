class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n + 1);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n + 1, 0); // 0: unvisited, 1: color1, -1: color2
        vector<bool> visited(n + 1, false);
        int maxGroups = 0;

        auto bfs = [&](int start) -> int {
            queue<int> q;
            q.push(start);
            unordered_map<int, int> depth;
            depth[start] = 1;
            int maxDepth = 1;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int neighbor : graph[node]) {
                    if (!depth.count(neighbor)) {
                        depth[neighbor] = depth[node] + 1;
                        maxDepth = max(maxDepth, depth[neighbor]);
                        q.push(neighbor);
                    }
                }
            }
            return maxDepth;
        };

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                queue<int> q;
                q.push(i);
                visited[i] = true;
                color[i] = 1;
                vector<int> component;

                // BFS to find the connected component and check bipartiteness
                bool isBipartite = true;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    component.push_back(node);
                    
                    for (int neighbor : graph[node]) {
                        if (color[neighbor] == 0) {
                            color[neighbor] = -color[node];
                            q.push(neighbor);
                            visited[neighbor] = true;
                        } else if (color[neighbor] == color[node]) {
                            return -1; // Not bipartite, return -1
                        }
                    }
                }

                // Compute the max groups for this component
                int maxComponentGroups = 0;
                for (int node : component) {
                    maxComponentGroups = max(maxComponentGroups, bfs(node));
                }
                maxGroups += maxComponentGroups;
            }
        }
        return maxGroups;
    }
};
