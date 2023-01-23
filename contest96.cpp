#include <bits/stdc++.h>
using namespace std;
/*
Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.

Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.
*/
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
    //bruteforce method creating a common element array and finding min.

    set<int> commons;
    for(int i : nums1)
    {
        for(int j : nums2)
        {
            if(i == j)
            {
                commons.insert(i);
            }
        }
    }
    auto it = commons.begin();
    return *it;

    //method2: given that arrays are sorted in increasing order - just find the first common element
    for(int i : nums1)
    {
        for(int j : nums2)
        {
            if(i == j)
            {
                return i;
            }
            else if(i<j)
            {
                break;
            }
        }
    } 
    return -1;
    }
};
int main()
{
    Solution s;
    
}