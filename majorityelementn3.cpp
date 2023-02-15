#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //approach 1: bruteforce method 
        //time complexity O(2n) space complexity O(n)
        // vector <int> sol;
        // map <int,int> all;
        // int maj = nums.size()/3;
        // //inserting into map
        // for(auto i: nums)
        // {
        //     all[i]++;
        // }
        // for(auto i:all)
        // {
        //     if(i.second>maj)
        //     sol.push_back(i.first);
        // }
        // return sol;

        //approach2:moore's voting algorithm.
        //only 2 possible elements at most and 0 at least.
        //time complexity O(n) space O(1)
        int ele1=-1,ele2=-1;
        int count1 = 0,count2= 0;
        for(auto i: nums)
        {
            if(i == ele1) count1++;
            else if(i == ele2) count2++;
            else if(count1 == 0) ele1 = i,count1++;
            else if(count2 == 0) ele2 = i,count2++;
            else
            {
                count1--;
                count2--;
            }
        }
            count1 = 0;
            count2 = 0;
        for(auto i : nums)
        {   
            if(i == ele1) count1++;
            else if(i == ele2) count2++;
        }
        vector<int> sol;
        if(count1>nums.size()/3) sol.push_back(ele1);
        if(count2>nums.size()/3) sol.push_back(ele2);
        return sol;

    }
};
int main()
{
    Solution s;
    vector <int> nums = {3,2,3};
    vector <int > arr = s.majorityElement(nums);
    for(auto i : arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}