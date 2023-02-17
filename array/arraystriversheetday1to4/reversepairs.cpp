#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // solution 1: bruteforce O(n^2)
    //     int reversePairs(vector<int>& nums) {
    //              //method 1: bruteforce using two loops
    //      int counter = 0;
    //      for(int i = 0;i<nums.size();i++)
    //      {
    //          for(int j = i+1;j<nums.size();j++)
    //          {
    //              if((long long)nums[i]>(long long)2*nums[j])
    //              {
    //                  counter++;
    //              }
    //          }
    //      }
    //      return counter;
    //  }

    // approach 2: merge sort -- O(nlogn + n+ n)
    int merge(vector<int> &arr, int l, int m, int h)
    {
        int count = 0;
        int t = m+1;
        for (int q = l; q <= m; q++) //traversing the first array
        {
            while(t<=h && arr[q]> 2LL*arr[t])
            {
                t++;
            }
            count+=t-(m+1);
        }
        
        vector<int> tmp(h - l + 1);
        int i = l, j = m + 1; // pointers to the array
        int k = 0;            // tmp array element tracker
        while (i <= m && j <= h)
        {
            if (arr[i] >= arr[j])
            {
                tmp[k] = arr[j];
                j++;
                k++;
            }
            else
            {
                tmp[k] = arr[i];
                i++;
                k++;
            }
        }
        while (i <= m)
        {
            tmp[k] = arr[i];
            i++;
            k++;
        }
        while (j <= h)
        {
            tmp[k] = arr[j];
            j++;
            k++;
        }
        k = 0;
        for (i = l; i <= h; i++)
        {
            arr[i] = tmp[k++];
        }
        return count;
    }
    int mergesort(vector<int> &arr, int l, int h)
    {
        if (l >= h)
            return 0;
        int count = 0;
        int m = (l + h) / 2;
        count += mergesort(arr, l, m);     // sorting left array
        count += mergesort(arr, m + 1, h); // sorting right array
        count += merge(arr, l, m, h);
        return count;
    }
    int reversePairs(vector<int> &nums)
    {

        return mergesort(nums, 0, nums.size() - 1);
    }

};
int main()
{
    Solution s;
    vector<int> nums = {5,1};
    cout << s.reversePairs(nums);
    // for (auto i : nums)
    //     cout << i << " ";
    // cout << endl;
}