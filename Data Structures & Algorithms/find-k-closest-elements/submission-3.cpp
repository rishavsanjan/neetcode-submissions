class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i = 0; i< arr.size(); i++){
           
            pq.push({abs(arr[i] - x), i});
        }
        int i = 0;
        for(int i = 0; i < k; i++){
            ans.push_back(arr[pq.top().second]);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};