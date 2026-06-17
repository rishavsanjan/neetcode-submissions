class KthLargest {
   public:
    priority_queue<int> pq;
    int cnt;
    KthLargest(int k, vector<int>& nums) {
        for (auto x : nums) {
            pq.push(x);
        }
        cnt = k;
    }

    int add(int val) {
        pq.push(val);
        vector<int>temp;
        int ans = 0;
        int i = cnt;
        while(i > 0){
            ans = pq.top();
            temp.push_back(ans);
            pq.pop();
            i--;
        }

        for (auto x : temp) {
            pq.push(x);
        }

        return ans;
    }
};
