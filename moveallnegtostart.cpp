#include <bits/stdc++.h>
using namespace std;
vector<int> separateNegativeAndPositive(vector<int> &nums)
{
    // Write your code here.
    // approach 1: sort the array O(nlogn) time space O(1)
    // sort(nums.begin(),nums.end());
    // return nums;
    // approach 2: 2 pointer appraoch time O(n) space O(1)
    //     int i = 0, j = nums.size() - 1;
    //     while (i < j)
    //     {
    //         while (nums[i] < 0)
    //         {
    //             if (i == nums.size() - 1)
    //                 break;
    //             i++;
    //         }
    //         while (nums[j] >= 0)
    //         {
    //             if (j == 0)
    //                 break;
    //             j--;
    //         }
    //         if (i <= j)
    //             swap(nums[i], nums[j]);
    //     }
    //     return nums;
    //better implementation of approach2: 4 cases 
        // int i = 0, j = nums.size() - 1;
        // while (i < j){ //time O(n) reduced comparisons compared to my implementation
        //     if(nums[i]<0 && nums[j]<0) i++;
        //     else if(nums[i]<0 && nums[j]>=0) i++,j--;
        //     else if(nums[i]>=0 && nums[j]<0) {swap(nums[i],nums[j]); i++,j--;}
        //     else j--;
        // }
        // return nums;

    //approach 3: partition in two parts
        // 'j' stores the index of the leftmost positive element.
    int j = 0;

    for (int i = 0; i < nums.size(); i++) {

        if (nums[i] < 0) {

            // Current element is negative.
            if (i != j) {

                // Swap the current element with the leftmost positive element.
                swap(nums[i], nums[j]);
            }

            ++j;
        }
    }

    return nums;

}
int main()
{
    vector<int> vec = {-5, 24,-8};
    vector<int> ans = separateNegativeAndPositive(vec);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}