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
            string ans = mpp[key][0].second;
            int t = mpp[key][0].first;
            bool found = false;
            for (auto p : mpp[key]) {
                if (p.first == timestamp) {
                    return p.second;
                }

                if (p.first <= timestamp && p.first >= t) {
                    t = p.first;
                    ans = p.second;
                    found = true;
                }
            }
            if (found == true) {
                return ans;
            } else {
                return "";
            }

        } else {
            return "";
        }
    }
};
