#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); // returns rows
        int n = matrix[0].size(); //returns columns

        //bruteforce
        //learing - substituting the value with another number so that the loop succeeds
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n;j++)
            {
                if(matrix[i][j] == 0)
                {
                    //changing the columns
                    for(int k = 0; k<n;k++)
                    {
                        if(matrix[i][k] !=0)
                        matrix[i][k] = -1; // first changing it to -1 instead of 0 as we are using it in comparison
                    }
                    
                    //changing the rows 
                    for(int l = 0; l<m; l++)
                    {   
                        if(matrix[l][j] !=0)
                        matrix[l][j] = -1;
                    }

            
                }
            }
        }

        //Now everyting changed to -1 change it back to +1
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(matrix[i][j] == -1)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        //time complexity - O(mn*(m+n)+m+n) space - O(1)


        //printing the array.      
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }        
    }

    //dummy array approach- take 2 dummy arrays to store where the values are -
    //additional memory approach - record the row and column numbers having zero in an unordered set.
    //                             Now iterate over the unordered set and change the values to 0. timecomplexity O(mn) space(m+n)

    //approach 2 using first row and column as flags to see which rows and columns are zero
    //to decrease time complexity
    void setZeroes2(vector<vector<int>>& matrix){
        //while using the 1st row and column as flag we have 
        int m = matrix.size(); // returns rows
        int n = matrix[0].size(); //returns columns
        int col0 = 1;
        for(int i = 0; i<m;i++) //looping rows
        {  //checking if there is 0 in the first column
            if (matrix[i][0] == 0) col0 = 0;
            for(int j = 1; j<n;j++)
            {
                //checking for all other columns
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }

        }

        //traversing in reverse direction and setting the values accordingly.
        for(int i = m-1;i>=0;i--)
        {
            for(int j = n-1; j>=1;j--)
            {
                if(matrix[i][0] == 0 || matrix[0][j]== 0)
                {
                    matrix[i][j] = 0;
                }
            }
            if(col0 == 0)
            {
                matrix[i][0] = 0;
            }
        }
        //printing the array.      
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }    
    }
    //space complexity - O(1) time complexity O(m*n)
};

int main()
{
    vector<vector<int>> m = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    Solution t;
    t.setZeroes2(m);
    
}