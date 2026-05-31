class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue<vector<double>>pq;
        for (int i = 0; i < speed.size(); i++) {
            double time = (double)(target - position[i]) / speed[i];
            pq.push({(double)position[i], time});
        }
        
        int fleet = 0;
        while(true){
            if(pq.size() == 1){
                fleet++;
                break;
            }

            auto ahead = pq.top();
            pq.pop();
            auto behind = pq.top();
            pq.pop();

            if(ahead[1] >= behind[1]){
                pq.push(ahead);
            }else{
                pq.push(behind);
                fleet++;
            }
        }

        return fleet;
    }
};
 