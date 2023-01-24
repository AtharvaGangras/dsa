#include <bits/stdc++.h>
using namespace std;
void printmat(vector<vector<int>> mat)
{   cout<<endl;
        for(auto i : mat)
    {   
        for(auto j: i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //bruteforce method - take dummy array 2.(given square matrix) -- not allowed
        // int n = matrix.size();
        // vector<vector<int>> rotated(n,vector<int> (n,0));
        // for(int i = 0; i<n;i++)
        // {
        //     for(int j = 0; j<n;j++)
        //     {
        //         rotated[j][n-i-1] = matrix[i][j];
        //     }
        // }
        // printmat(rotated);

        //four way swap - take 3 temp variables to swap positions time complexity - O(N^2)
        // int n = matrix.size();
        // int l;
        // if(n%2 == 0) l = n/2;
        // else l = n/2 +1;
        // for(int i = 0; i<l; i++)
        // {
        //     for(int j = 0; j<n/2;j++)
        //     {
        //         swap(matrix[i][j],matrix[n-j-1][i]);
        //         swap(matrix[n-j-1][i],matrix[n-i-1][n-j-1]);
        //         swap(matrix[n-i-1][n-j-1],matrix[j][n-i-1]);
        //     }
        // }

        //transpose the matrix then reverse the rows.--- time complexity O(N*2)
        int n = matrix.size();
        //transpose
        for(int i = 0; i<n; i++)
        {
            for(int j = 0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);

            }
        }
        //reverse rows
        for(int i = 0; i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }

        
        
    }
};
int main()
{
    Solution s;
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    s.rotate(mat);
    printmat(mat);
}