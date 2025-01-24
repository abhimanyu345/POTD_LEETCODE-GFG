class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revGraph(n);
        vector<int> inDegree(n, 0);
        
        // Reverse the graph: store incoming edges for each node
        for (int i = 0; i < n; i++) {
            for (int neighbor : graph[i]) {
                revGraph[neighbor].push_back(i);
                inDegree[i]++;
            }
        }

        queue<int> q;
        vector<int> safeNodes;
        
        // Push terminal nodes (inDegree == 0) into the queue
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Process nodes in topological order
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            
            for (int neighbor : revGraph[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // Sort safe nodes in ascending order
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
