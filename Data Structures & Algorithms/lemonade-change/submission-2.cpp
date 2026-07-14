class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int five = 0;
        int ten = 0;

        int total = 0;
        for(auto x : bills){
            if(x == 5){
                five++;
                continue;
            }

            if(x == 10 && five > 0){
                five--;
                ten++;
                continue;
            }

            if(x == 20 && (five > 0 && ten > 0) ){
                five--;
                ten--;
                continue;
            }else if(x == 20 && (five > 2)){
                five -= 3;
                continue;
            }

            return false;

        }

        return true;
    }
};