class Solution {
public:
bool linearSearch(vector<int> nums, int num)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == num)
        {
            return true;
        }
    }
    return false;
}

    int longestConsecutive(vector<int>& nums) {
       int n = nums.size();
       if ( n == 0) return 0;
        int longest = 1;
        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            int count = 1;
            while (linearSearch(nums, num + 1) == true)
            {
                num++;

                count++;
            }
            longest = max(count, longest);
        }
        return longest;
    }
};
