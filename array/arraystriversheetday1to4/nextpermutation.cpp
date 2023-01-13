#include <bits/stdc++.h>
using namespace std;
 class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //using two pointers from the end to change
        int len = nums.size();
        int i,j,flag = 0;
        
        //my solution
        // for(i = len-1;i>=0;i--)
        // {//loops for the element to be changed
        //     for(j = len-1;j>i;j--)
        //     {
        //         if(nums[i]<nums[j])
        //         {
        //             int k = nums[i];
        //             nums[i] = nums[j];
        //             nums[j] = k;
        //             flag =1;
        //             break;
        //         }
        //     }
        //     if(flag ==1) break;
        // }
        
        //optimal solution
        //finding the downward tree
        for(i = len-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                break;
            }
        }
        //now replacing the current element with a greater element from last
        if(i != -1){
        for(int j = len -1;j>=i;j--)
        {
            if(nums[i]<nums[j])
            {
                int k = nums[i];
                nums[i] = nums[j];
                nums[j] = k;
                break;
            }
        }
        }


        //now arraging all the elements after the i'th element in ascending order
        sort(nums.begin()+i+1,nums.end());

        // printing the vector
        for(auto k :nums)
        {
            cout<<k<<" ";
        }
        // cout<<endl;
        //time complexity = O(n^2) my solution
        //time complextiy = O(n) optimal solution
        //space complexity = O(1)
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1,3,2};
    s.nextPermutation(nums);
    cout<<endl;
    //solution 2 is inbuilt function
    int arr[] = {1,3,2};
    
    next_permutation(arr,arr+3);//using in-built function of C++
    
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];

}