#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //approach 1: Naive - using three loops -2 to find subarray and one to find sum O(n^3)
        int n = nums.size();
        int maxival = INT_MIN;
        // for(int i = 0; i<n;i++)//loops for the starting element
        // {
        //     for(int j = i; j<n;j++) //loops for the ending element
        //     {
        //         int sum = 0;
        //         for(int k = i;k<=j;k++)
        //         {
        //             sum+=nums[k];
        //         }
        //         maxival = max(sum,maxival);
        //     }
        // }

        //approach 2: optimize the above using only 2 loops O(n^2)
        // for(int i = 0; i<n;i++)//loops for the starting element
        // {   
        //     int sum = 0;
        //     for(int j = i; j<n;j++) //loops for the ending element
        //     {
        //       sum+=nums[j];
        //     maxival = max(sum,maxival);
        //     }
        // }



        //optimal solution -Kadane's algorithm O(n)
        //approach - maintaining maximum and sum variables
        
        // int sum = 0;
        // for(auto i : nums)
        // {
        //     sum += i;
        //     maxival = max(sum,maxival);
        //     if(sum<0) sum = 0;
        // }

        // cout<<maxival<<endl;
        // return maxival;

        //also return the array
        int mti = 0,s = 0,start,end,i; //maxval as msf
        for(i = 0; i<n;i++)
        {
            mti += nums[i];
            if(mti>maxival)
            {
                maxival = mti;
                end = i;
                start = s;
            }
            if(mti<0)
            {
                mti = 0;
                s = i+1;
            }

        }
        for(int i = start;i<end+1;i++)
        {
            cout<<nums[i]<<" ";
        }
        cout<<endl<<maxival<<endl;

        return maxival;
    }
};
int main()
{
    Solution s;
    vector<int> a = {5,4,-1,7,8};
    s.maxSubArray(a);
}