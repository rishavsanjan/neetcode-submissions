class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int cnt;
    KthLargest(int k, vector<int>& nums) {
        

        for(auto x : nums){
            pq.push(x);

            if(pq.size() > k){
                pq.pop();
            }
        }
        cnt = k;
    }
    
    int add(int val) {
        pq.push(val);

        if(pq.size() > cnt) {
            pq.pop();
        }

        return pq.top();
    }
};
