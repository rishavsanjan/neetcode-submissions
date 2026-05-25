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
    sort(nums.begin(), nums.end());
    int longest = 1;
    int count = 0;
    int lastElement = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] - 1 == lastElement)
        {
            count++;
            lastElement = nums[i];
        }else if(nums[i] != lastElement){
            count = 1;
            lastElement = nums[i];
        }
        longest = max(longest, count);
    }
    return longest;
      // int n = nums.size();
      // if ( n == 0) return 0;
      //  int longest = 1;
      //  for (int i = 0; i < n; i++)
      //  {
      //      int num = nums[i];
      //      int count = 1;
      //      while (linearSearch(nums, num + 1) == true)
      //      {
      //          num++;
//
      //          count++;
      //      }
      //      longest = max(count, longest);
      //  }
      //  return longest;
    }
};
