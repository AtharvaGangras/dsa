#include <bits/stdc++.h>
using namespace std;
int LongestSubsetWithZeroSum(vector<int> arr)
{
    // approach 1: bruteforce as we are told it is a subarray we can use two loops too calculate all
    // possiblilites.
    // time complexity O(N^2) space O(1)
    //  int sum = 0;
    //  int maxlen = 0;
    //  for(int i = 0; i<arr.size();i++)
    //  {
    //      // i is the first element
    //      sum = 0;
    //      for(int j = i; j<arr.size();j++)
    //      {
    //          sum+= arr[j];
    //          if(sum == 0)
    //          {
    //              maxlen = max(maxlen,j-i+1);
    //          }
    //      }
    //  }
    //  return maxlen;
    // approach 2: storing the prefix sums in another array
    // we can say that if for any two elements at index i and j their prefix sum is same
    // then the subarray between them has sum 0
    //time complexity - O(n) space O(n)
    unordered_map<int, int> m;
    int maxlen = 0;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == 0)
            maxlen = i + 1;
        else
        {
            if (m.find(sum) != m.end())
            {
                maxlen = max(maxlen, i - m[sum]);
            }
            else
            {
                m[sum] = i;
            }
        }
    }
    return maxlen;
}
int main()
{
    vector<int> v = {1, 3, -1, 4, -4};
    cout << LongestSubsetWithZeroSum(v) << endl;
}