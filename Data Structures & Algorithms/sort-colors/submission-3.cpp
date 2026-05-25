class Solution {
public:
    void sortColors(vector<int>& nums) {
      
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
           
            mid++;
        }
        else if (nums[mid] == 2)
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }


        // vector<int> ans;
        // int  blue = 0;
        // int red = 0;
        // int white = 0;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (nums[i] == 0)
        //     {
        //         red++;
        //     }
        //     else if (nums[i] == 1)
        //     {
        //         white++;
        //     }
        //     else
        //     {
        //         blue++;
        //     }
        // }
        // cout<<red<< " " <<white<< " "<<blue<<endl;
        // int i =0;
        // while(red != 0){
        //     nums[i] = 0;
        //     red--;
        //     i++;
        // }
        //  while(white != 0){
        //     nums[i] = 1;
        //     white--;
        //     i++;
        // }
        //  while(blue != 0){
        //     nums[i] = 2;
        //     blue--;
        //     i++;
        // }


    }
};