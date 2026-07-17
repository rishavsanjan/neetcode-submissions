class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size() == 1)
            return 1;
        int l = 0;
        int r = 1;

        int res = 1;
        char sign = ' ';

        while (r < arr.size()) {
            if (arr[r - 1] > arr[r] and sign != '>') {
                res = max(res, r - l + 1);
                r++;
                sign = '>';
            } else if (arr[r - 1] < arr[r] and sign != '<') {
                res = max(res, r - l + 1);
                r++;
                sign = '<';
            } else {
                if (arr[r - 1] == arr[r]) {
                    l = r;
                    sign = ' ';
                } else {
                    l = r - 1;
                    sign = (arr[r - 1] > arr[r]) ? '>' : '<';
                }
                r++;
            }
        }

        return res;
    }
};