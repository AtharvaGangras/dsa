#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //bruteforce method -uisng selection sort sort O(n^2)
        // for(int i = 0;i<nums.size();i++)
        // {
        //     //finding the minimal element
        //     int j;
        //     int min = nums[i];
        //     int min_ind = i;
        //     for(j = i;j<nums.size();j++)
        //     {
        //         if(min>nums[j]) 
        //         {
        //             min = nums[j];
        //             min_ind = j;

        //         }
        //     }
        //     //swap
        //     swap(nums[i],nums[min_ind]);
        // }

        //method 2: pushing 2 to the end pushing 0 to the start and leaving 1 as it is.(1 pass. variable extra space)
        //very slow as passes end up hidden in inbuilt functions
        // int track = 0;
        // for(int i = 0; i<nums.size();i++)
        // {   
        //     if(nums[track] == 0)
        //     {
        //         nums.erase(nums.begin()+track);
        //         nums.insert(nums.begin(),0);
        //         track++;

        //     }
        //     else if(nums[track] == 1) track++;
        //     else if(nums[track] == 2)
        //     {
        //         nums.push_back(2);
        //         nums.erase(nums.begin()+track);
        //     }
        // }

        //method 3: counting the no. of 0's,1's,2's and then replacing till that.
        // int zeros = 0,ones = 0,twos = 0;
        // for(int i = 0;i<nums.size();i++)
        // {
        //     if(nums[i] == 0) zeros++;
        //     if(nums[i] == 1) ones++;
        //     if(nums[i] == 2) twos++;
        // }
        // ones += zeros;
        // twos += ones;
        // for(int i = 0;i<nums.size();i++)
        // {
        //     if(i<zeros) nums[i] = 0;
        //     else if(i<ones) nums[i] = 1;
        //     else if(i<twos) nums[i] = 2;
        // }

        //method 4: 3 pointer approach(optimal approach)
        int low = 0,mid = 0;
        int high = nums.size()-1;
        while(mid<=high)
        {
            if(nums[mid] == 0) swap(nums[low++],nums[mid++]);
            else if(nums[mid] == 1) mid++;
            else if(nums[mid] == 2) swap(nums[mid],nums[high--]);
        }



        

        
    }
};
//as this algorithm needs to be inplace we can't use multiset.
int main()
{
    Solution s;
    vector<int> t = {2,2,1};
    s.sortColors(t);
    for(auto i : t)
    {
        cout<<i<<" ";
    }
    cout<<endl;

}