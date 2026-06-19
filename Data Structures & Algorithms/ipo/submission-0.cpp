class Solution {
   public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects(n);

        for (int i = 0; i < profits.size(); i++) {
            projects[i] = {capital[i], profits[i]};
        }
        sort(projects.begin(), projects.end());

        priority_queue<int> maxProfit;
        int idx = 0;

        for (int i = 0; i < k; i++) {
            while(idx < n && projects[idx].first <= w) {
                maxProfit.push(projects[idx].second);
                idx++;
            }

            if(maxProfit.empty()) break;
            w += maxProfit.top();
            maxProfit.pop();
        }

        return w;
    }
};