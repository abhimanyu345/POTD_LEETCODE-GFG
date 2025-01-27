class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses);
        vector<unordered_set<int>> reachability(numCourses);

        // Build adjacency list
        for (auto& pre : prerequisites) {
            graph[pre[0]].push_back(pre[1]);
        }

        // Compute reachability using BFS
        for (int i = 0; i < numCourses; ++i) {
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int next : graph[node]) {
                    if (reachability[i].insert(next).second) { // Only push if newly visited
                        q.push(next);
                    }
                }
            }
        }

        // Answer queries
        vector<bool> answer;
        for (auto& query : queries) {
            answer.push_back(reachability[query[0]].count(query[1]));
        }
        return answer;
    }
};
