class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;

        for(auto x : stones){
            pq.push(x);
        }

        while(true){
            if(pq.size() <= 1){
                break;
            }

            int x = pq.top();
            pq.pop();

            int y = pq.top();
            pq.pop();

            if(x == y){
                continue;
            }else{
                pq.push(abs(y - x));
            }
        }

        if(pq.size() == 1){
            return pq.top();
        }else{
            return 0;
        }
    }
};
