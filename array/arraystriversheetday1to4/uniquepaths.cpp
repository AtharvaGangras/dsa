#include <bits/stdc++.h>
using namespace std;
// fail due to integer overflow
//  unsigned long long int fact(int n) -- fail due to integer overflow.
//  {
//      unsigned long long int ans = 1;
//      for(unsigned long long int i = 1;i<=n;i++)
//      {
//          ans*= i;
//      }
//      return ans;
//  }
//  class Solution {
//  public:
//      unsigned long long int uniquePaths(int m, int n) {
//          //answer nCr
//          if(m<n) m,n = n,m;
//          unsigned long long int ans = 1;
//          for(int i = m+n-2;i>m-1;i--)
//          {
//              ans *= i;
//          }
//          ans /= fact(n-1);
//          return ans;
//      }
//  };

class Solution
{
public:
    // int uniquePaths(int m, int n) {
    //     int ans = 0;
    //     //solution 1: recursive
    //     if(m == 0 || n == 0)
    //     {
    //         return ans;
    //     }
    //     else if(m == 1 || n == 1)
    //     {
    //         ans = 1;
    //         return ans;
    //     }
    //     else
    //     {
    //         ans =  this->uniquePaths(m-1,n) + uniquePaths(m,n-1);
    //         return ans;
    //     }

    // }

    // solution 2: recursive implementation:striver time - exponential space exponential
    //using dynamic programming time O(m*n) space O(m*n)
    // int countpaths(int i, int j, int m, int n, vector<vector<int>> &dp) // i,j -> denotes start of the matrix and m,n denotes the number of rows and columns
    // {
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     if (i == m - 1 || j == n - 1)
    //         return 1;
    //     if (i >= m || j >= n)
    //         return 0;
    //     else
    //     {
    //         dp[i][j] = countpaths(i + 1, j, m, n,dp) + countpaths(i, j + 1, m, n,dp);
    //         return dp[i][j];
    //     }
    // }
    // int uniquePaths(int m, int n)
    // {
    //     vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    //     return countpaths(0, 0, m, n, dp);
    // }

    //solution 3: nCr solution 
    //time complexity O(m) space O(1);
        int uniquePaths(int m, int n) {
        int N = m+n-2;
        int r = m-1;
        double ans = 1;
        for(int i =1;i<=r;i++)
        {
            ans= ans*(N-r+i)/i;
        }
        return (int)ans;
    }
};
int main()
{
    Solution s;
    cout << s.uniquePaths(3, 7);
}