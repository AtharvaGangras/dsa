#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // //approach 1: linear search on 2d matrix O(m*n)
        // for(int i = 0;i<matrix.size();i++)
        // {
        //     for(int j = 0;j<matrix[0].size();j++)
        //     {
        //         if(matrix[i][j]== target)
        //             return true;
        //     }
        // }
        // return false;

        //approach 2 : row wise comparison O(m+n)
        // int i = 0, j= 0;
        // while(i<matrix.size())
        // {
        //     if(target<matrix[i][0]) break;
        //     else i++;

        // }
        // if(i!= 0) i--;
        // else return false;
        // for(j= 0;j<matrix[0].size();j++)
        // {
        //     if(matrix[i][j]==target)
        //     return true;
        // }
        // return false;

        //approach 3 : binary search on 2d matrix (as the array is sorted) O(log(m*n))
        //total number of elements
        int m = matrix.size();
        int n = matrix[0].size();
        int size = m*n-1;
        int low = 0;
        int high = size;
        while(low<=high)
        {
            int mid = (low+high)/2;
            int row = mid/n;
            int column = mid%n;
            // if (column == -1) column = 3;
            if(matrix[row][column] == target) return true;
            else if (matrix[row][column] < target) low = mid+1;
            else high = mid-1;

        }
        return false;

    }
};
int main()
{
    Solution s;
    vector<vector<int>> v = {{1}};
    cout<<s.searchMatrix(v,1);
}