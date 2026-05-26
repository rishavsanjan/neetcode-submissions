class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {
        int l = 0;
        int r = people.size() - 1;
        int count = 0;
        sort(people.begin(), people.end());

        while (l <= r) {
            int sum = people[l] + people[r];

            if (sum <= limit) {
                l++;
                r--;

            } else {
                r--;
            }
            count++;
        }

        return count;
    }
};