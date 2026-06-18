class Solution {
   public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<array<int, 3>> t(n);

        vector<int> ans;
        for (int i = 0; i < tasks.size(); i++) {
            t[i] = {tasks[i][0], tasks[i][1], i};
        }

        sort(t.begin(), t.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        long long time = 0;
        int ptr = 0;

        while (ans.size() < n) {
            while (ptr < n && t[ptr][0] <= time) {
                pq.push({t[ptr][1], t[ptr][2]});
                ptr++;
            }

            if(pq.empty()){
                time = t[ptr][0];
                continue;
            }

            auto[prod, idx] = pq.top();
            pq.pop();
            time += prod;
            ans.push_back(idx);
        }

        return ans;
    }
};