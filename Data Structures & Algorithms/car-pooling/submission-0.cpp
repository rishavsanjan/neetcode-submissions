class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int>mpp;

        for(int i = 0; i<trips.size();i++){
            int passengers = trips[i][0];
            int start = trips[i][1];
            int end = trips[i][2];

            mpp[start] += passengers;
            mpp[end] += -(passengers);
        }
        int cnt = 0;
        for(auto x : mpp){
            cnt += x.second;
            if(cnt > capacity){
                return false;
            }
        }

        return true;
    }
};