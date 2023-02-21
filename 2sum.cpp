#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // approach 1 : bruteforce using two loops
        // time complexity O(n^2) space - O(1)
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     for (int j = i + 1; j < nums.size(); j++)
        //     {
        //         if (nums[i] + nums[j] == target)
        //         {
        //             return {i, j};
        //         }
        //     }
        // }
        // return {0};
        // approach 2: a number's sum is made of two halfs the first number should be lesser than
        // target/2 while the other is greater.
        // so sorting the array we can use two pointers one from the start other from end to find sum.
        // approach 2: make a temp array and copy this array and sort it.Now using two pointers
        //time complexity O(nlogn) space O(n)
        // vector<int> temp(nums),res;
        // sort(temp.begin(), temp.end());
        // int i = 0, j = temp.size() - 1;
        // while (i < j) // O(n)
        // {
        //     if (temp[i] + temp[j] > target)
        //         j--;
        //     else if (temp[i] + temp[j] < target)
        //         i++;
        //     else
        //         break;
        // }
        // for (int k = 0; k < nums.size(); ++k)
        // {
        //         if (nums[k] == temp[i])
        //         res.emplace_back(k);
        //     else if (nums[k] == temp[j])
        //         res.emplace_back(k);
        // }
        // return res;

        // solution 3: hashing -- use unordered map
        //time complexity O(n) space O(N)
        unordered_map <int,int> m;
        vector <int> res;
        int x = 0;
        for(int i = 0; i<nums.size();i++)
        {
            x = nums[i];
            if(m.find(target - x) != m.end())
            {
                res.push_back(i);
                res.push_back(m[target-x]);
            }
            m[nums[i]] = i;
        }
        return res;


    
    }
};
int main()
{
    Solution s;
    vector<int> nums = {3, 3};
    int target = 6;
    vector<int> a = s.twoSum(nums, target);
    for (auto i : a)
    {
        cout << i << " ";
    }
    cout << endl;
}