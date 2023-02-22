#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        // solution 1: bruteforce using four loops -- time O(n^4)
        // time limit exceeded
        // sort(nums.begin(), nums.end());
        // set<vector<int>> v;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     for (int j = i + 1; j < nums.size(); j++)
        //     {
        //         for (int k = j + 1; k < nums.size(); k++)
        //         {
        //             for (int l = k + 1; l < nums.size(); l++)
        //             {
        //                 if ((long long)nums[i] + nums[j] + nums[k] + nums[l] == target)
        //                 {
        //                     v.insert({nums[i], nums[j], nums[k], nums[l]});
        //                 }
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>> v2(v.begin(), v.end());
        // return v2;

        // solution2 : 3 pointer approach choosing 3 numbers and then binary search for the fourth number
        // in the sorted array. time O(nlogn + n^3logn)
        // sort(nums.begin(), nums.end());
        // set<vector<int>> v;

        // for (int i = 0; i < nums.size(); i++)
        // {
        //     for (int j = i + 1; j < nums.size(); j++)
        //     {
        //         for (int k = j + 1; k < nums.size(); k++)
        //         {
        //             long long x = (long long)target - nums[i] - nums[j] - nums[k];

        //             if (binary_search(nums.begin() + k + 1, nums.end(), x))
        //             {
        //                 vector<int> tmp;
        //                 tmp.push_back(nums[i]);
        //                 tmp.push_back(nums[j]);
        //                 tmp.push_back(nums[k]);
        //                 tmp.push_back(x);
        //                 sort(tmp.begin(), tmp.end());
        //                 v.insert(tmp);
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>> v2(v.begin(), v.end());
        // return v2;

        // approach 3: 2pointer + 2sum- 2pointer+ skipping repeated elements
        //time complexity O(nlogn+n^3) space - O(1)
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        int k,l;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                k = j+1;
                l = nums.size()-1;
                long long x = (long long)target - nums[i] - nums[j];
                while(k<l)
                {
                    
                    if(nums[k]+nums[l] == x)
                    {
                        int t1 = nums[k];
                        int t2 = nums[l];
                        v.push_back({nums[i],nums[j],nums[k],nums[l]});
                        //processing duplicates.
                        while(k<l && nums[k] == t1) k++;
                        while(k<l && nums[l] == t2) l--;
                    }
                    else if(nums[k]+nums[l] > x)
                    {
                        l--;
                        continue;
                    }
                    else
                    {
                        k++;
                        continue;
                    }
                }
                while(j+1<nums.size() && nums[j+1] == nums[j]) j++;
            }
            while(i+1<nums.size() && nums[i+1] == nums[i]) i++;
        }
        return v;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    auto v = s.fourSum(nums, target);
    for(auto i: v)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}