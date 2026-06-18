class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mpp(26, 0);

        for (auto x : tasks) {
            mpp[x - 'A']++;
        }

        priority_queue<int> pq;

        for (auto x : mpp) {
            if (x > 0) {
                pq.push(x);
            }
        }

        int time = 0;

        while (!pq.empty()) {
            vector<int> temp;

            for (int i = 0; i < n + 1; i++) {
                if (!pq.empty()) {
                    auto it = pq.top();
                    pq.pop();
                    it--;
                    temp.push_back(it);
                }
            }

            for (auto x : temp) {
                if (x > 0) {
                    pq.push(x);
                }
            }

            if(pq.empty()){
                time += temp.size();
            }else{
                time += n + 1;
            }


        }

        return time;
    }
};
