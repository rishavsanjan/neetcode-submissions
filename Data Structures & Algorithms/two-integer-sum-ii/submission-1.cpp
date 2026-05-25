class Solution {
public:

    int bs(vector<int>& a, int low, int high, int target){
        if(low > high) return -1;
        int mid = (low + high)/2;
        if(a[mid] == target){
            return mid;
        }else if(target < a[mid]){
            return bs(a, low, mid - 1, target);
        }else{
            return bs(a, mid +1, high, target);
        }
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i =0; i<numbers.size();i++){
            int key = target - numbers[i];
            int ans = bs(numbers, i + 1, n - 1, key);
            if (ans != -1) {
                return {i + 1, ans + 1}; 
            }

        }


        // for(int i = 0; i<numbers.size();i++){
        //     int sum = 0;
        //     for(int j = 1; j<numbers.size();j++){
        //         if(numbers[i] + numbers[j] == target){
        //             return {i + 1, j + 1};
        //         }
        //     }
        // }
    }
};
