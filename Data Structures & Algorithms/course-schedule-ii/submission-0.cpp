class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adj(numCourses);
        vector<int> ans;
        vector<int> indegree(numCourses, 0);
        for (auto x : pre) {
            adj[x[1]].push_back(x[0]);
        }

        for (auto it : adj) {
            for (auto x : it) {
                indegree[x]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                ans.push_back(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto x : adj[node]) {
                indegree[x]--;
                if (indegree[x] == 0) {
                    q.push(x);
                    ans.push_back(x);
                }
            }
        }

        for (auto x : indegree) {
            if (x >= 1) {
                
                return {};
            }
        }
        return ans;
    }
};