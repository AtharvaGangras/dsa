#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //solution 1 - using two loops O(n^2) -- time limit exceeded.
        // int counter;
        // for(auto i : nums)
        // {   counter = 0;
        //     for(auto j : nums)
        //     {   
        //         if (i == j)
        //         {
        //             counter++;
        //             if(counter == 2)
        //             {
        //                 return i;
        //             }
        //         }
                
        //     }
        // }
        // return -1;

        // sol2 -- O(nlogn) time complexity sorting the array and then finding two elements that
        //are consecutively same --wrong solution because nums was modified.
        // sort(nums.begin(),nums.end());
        // int n = nums.size();
        // for(int i = 0; i<n-1;i++)
        // {
        //     if(nums[i] == nums[i+1])
        //     {
        //         return nums[i];
        //     }
        // }
        // return -1;

        //sol3 -- frequency approach time complexity - O(N) space- O(N)
        int n = nums.size();
        vector<int> freq (n+1,0);
        for(auto i: nums)
        {
            if(freq[i] == 0) freq[i]++;
            else return i;
        }
        return 0; 
        //sol4 -- linked list cycle method -- later while doing linked list.
        
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1,3,4,2,2};
    cout<<s.findDuplicate(nums);
}