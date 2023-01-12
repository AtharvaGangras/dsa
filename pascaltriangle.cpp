//pascal's triangle has elements of form nCr
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v(numRows);
        for(int i = 0; i<numRows;i++)
        { //first and last elements are always 1
            v[i].resize(i+1); //gives the size of the array 
            v[i][0] = 1;
            v[i][i] = 1;

            for(int j = 1; j<i;j++)
            {
                v[i][j] = v[i-1][j-1] +v[i-1][j];
            }

        }
    // //printing this vector
    // for(auto i:v)
    // {
    //     for(auto j:i)
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    return v;
    }
};
int main()
{
    Solution s;
    s.generate(5);
}