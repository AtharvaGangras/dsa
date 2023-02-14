#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //given that we can assume majority element always exist
        //as majority element is n/2 times that means only one such element can exist
        //method 1: naive /bruteforce method
        //uisng for loop we can count occurences of each element
        //time complexity O(n^2) //space complexity O(1)
        // int counter = 0;
        // int anscount = nums.size()/2;
        // for(int i = 0; i<nums.size();i++)
        // {
        //     int ans = nums[i];
        //     counter = 0;
        //     for(int j = 0;j<nums.size();j++)
        //     {
        //         if(nums[j] == ans)
        //         {
        //             counter++;
        //         }
        //     }
        //     if(anscount<counter)
        //     {
        //         return ans;
        //     }
        // }
        // return 0;

        //approach 2: better approach- use a unordered set to track the elements already tracked.
        //time complexity O(n^2)(worst case) but average case better. space complexity - O(n)
        // int counter = 0;
        // unordered_set <int> track;
        // unordered_set <int>::iterator it;
        // int anscount = nums.size()/2;
        // for(int i = 0; i<nums.size();i++)
        // {
        //     int ans = nums[i];
        //     it = track.find(ans); // if the value is already in ans then skip
        //     if(it != track.end()) continue;
        //     track.insert(ans);
        //     counter = 0;
        //     for(int j = 0;j<nums.size();j++)
        //     {
        //         if(nums[j] == ans)
        //         {
        //             counter++;
        //         }
        //     }
        //     if(anscount<counter)
        //     {
        //         return ans;
        //     }
        // }
        // return 0;

        //approach 3 see all the unique elements in the array using for loop and initialize with zero
        //in unordered map. and count them
        // 
        // then using the second for loop return the solution from the unordered map.
        //time O(nlogn) space O(n)
        // unordered_map <int,int> track;
        // auto it = track.end();
        // int ans = nums.size()/2;
        // for(auto i: nums)
        // {
        //     it = track.find(i);
        //     if(it == track.end())
        //     {
        //         track[i] = 1;
        //     }
        //     else{
        //         it->second++;
        //     }
        // }
        // for(auto it2:track)
        // {
        //     if(it2.second>ans)
        //     {
        //         return it2.first;
        //     }
        // }
        // return 0;

        //solution3 : moore's voting algorithm (important)
        //time complexity O(n) 
        int ele=0,count = 0;
        for(int i = 0; i<nums.size();i++)
        {
            if(count == 0)
            {
                ele = nums[i];
            }
            if(ele== nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return ele;



    }
};
int main()
{
    Solution s;
    vector<int> nums = {3,3,4};
    cout<<s.majorityElement(nums)<<endl;
}
