class TimeMap {
   public:
    map<string, vector<pair<int, string>>> mpp;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp, value});
        // if(mpp.find(key) != mpp.end()){

        // }else{
        // }
    }

    string get(string key, int timestamp) {
        if (mpp.find(key) != mpp.end()) {
            int l = 0;
            int r = mpp[key].size() - 1;
            string ans = "";
            while(l <= r){
                int m = (l + r) / 2;

                if(mpp[key][m].first == timestamp){
                    return mpp[key][m].second;
                }

                if(mpp[key][m].first <= timestamp){
                    ans = mpp[key][m].second;
                    l = m + 1;
                }else{
                    r = m - 1;
                }
            }

            return ans;

        } else {
            return "";
        }
    }
};
