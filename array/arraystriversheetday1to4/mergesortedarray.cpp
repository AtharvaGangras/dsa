#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //this is basically a merge function from merge sort

        //approach 1: bruteforce + memory approach - as we do not need an inplace algo.
        // time  O(n)       space O(m+n) 
        // vector<int> arr;
        // arr.resize(m+n);

        // //declaring pointers
        // int i = 0,j = 0,k = 0; // i-> nums1,j-> nums2,k-> sol
        // while(i<m && j<n)
        // {
        //     if(nums1[i]<nums2[j])
        //     {
        //         arr[k] = nums1[i];
        //         i++;k++;
        //     }
        //     else
        //     {
        //         arr[k] = nums2[j];
        //         j++;k++;
        //     }
        // }
        // while(i<m)
        // {
        //     arr[k] = nums1[i];
        //     i++;k++;
        // }
        // while(j<n)
        // {
        //     arr[k] = nums2[j];
        //     j++;k++;
        // }

        // for(i = 0; i<m+n;i++)
        // {
        //     nums1[i] = arr[i]; //copy into nums1
        // }
    //but the problem states that no extra memory can be allocated.
    //approach 2 : bruteforce method-> copy the second array into the empty space of first array and then
    //sort the array.
    //as the first array is given to have empty space to store the first array we do not need new array.
    //time complexity O((m+n)log(m+n)+n) -- O(m+nlog(m+n)) -- nlogn complexity for sort().
    // for(int i = 0;i<n;i++)
    // {
    //     nums1[m+i] = nums2[i];
    // } 
    // sort(nums1.begin(),nums1.end());

    //approach 3:compare the elements of the first array to the first element of second array and if greater
    //swap them. then rearrange the second array and continue. finally merge at end.
    //insertion sort type approach
    //space O(1) time O(m*n)
    for(int i = 0; i<m;i++)
    {
        if(n == 0) break;
        if(nums1[i]>nums2[0])//if we find a lesser element in nums2 it would be at a point where its location would belong in nums1.
        {
            swap(nums1[i],nums2[0]);// the 0th element gets inserted at its correct place
            //sorting the nums2 array to get least element
            for(int j = 1; j<n; j++)
            {   
                if(nums2[j-1]>nums2[j])
                {
                    swap(nums2[j-1],nums2[j]);
                }
                else break;
            }
        }
    }
    for(int i = 0;i<n;i++) //copying the rest of the array
    {
        nums1[m+i] = nums2[i];
    }                        

    //approach 4: gap method
            //copying the array
        //time complexity - O(n+m(log(n+m)))
        for(int i = 0;i<n;i++)
        {
            nums1[m+i] = nums2[i];//O(n)
        }
        //calculating initial gap
        int gap = ceil((m+n)/2.0);
        while(gap>0) //O(logn(gap operations)*n)
        {
            int k = 0;
            int j = gap;
            while(j<(m+n))
            {
                if(nums1[k]>nums1[j])
                {
                    swap(nums1[k],nums1[j]); 

                }
                k++;j++;
            }
            if(gap == 1) gap = 0;
            else gap = ceil(gap/2.0);
        }
    }

        
};
int main()
{
    Solution s;
    vector<int> v1 = {4,5,6,0,0,0};
    vector<int> v2 = {1,2,3};
    s.merge(v1,3,v2,v2.size());
    for(auto i : v1)
    {
        cout<<i<<" ";
    }
    cout<<endl;

}