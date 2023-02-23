#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //given - to write an algo in O(n) time.

        //approach 1: bruteforce - sort the array and then find the longest consecutive chain
        //time O(nlogn) space O(1)
        // if(nums.empty() == true)
        // {
        //     return 0;
        // }
        // sort(nums.begin(),nums.end());
        // int n = 1;
        // int ans = 1;
        // for(int i = 1; i<nums.size();i++)
        // {
        //     if(nums[i] - nums[i-1] == 1)
        //     {
        //         n++;
        //     }
        //     else if(nums[i] - nums[i-1] == 0)
        //     {
        //         continue;
        //     }
        //     else
        //     {
        //         n = 1;
        //     }
        //     ans = max(ans,n);
        // }
        // return ans;

        //approach 2: hash set O(3n) n - insert  n-arrayiterate n- checking
        unordered_set<int> s;
    
        for(auto i :nums)
        {
            s.insert(i);//O(1)
        }
        int conmax = 0,current = 1;
        for(auto i: nums)
        {  
            if(s.find(i-1) != s.end())
            {
                continue; // this prevents O(n2) time complexity
            }
            current = 1;
            int tmp = i;
            while(s.find(tmp+1) != s.end())
            {
                tmp++;
                current++;
            }
            conmax = max(conmax,current);
        }
        return conmax;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1,2,0,1};
    int a = s.longestConsecutive(nums);
    cout<<a<<endl;

}