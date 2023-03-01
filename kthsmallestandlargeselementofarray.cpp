#include <bits/stdc++.h>
using namespace std;
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Solution 1: bruteforce O(nlogn) sort the array and then return the 3rd and 3rd last element
    // sort(arr.begin(),arr.end());
    // return {arr[k-1],arr[n-k]};

    // Solution 2: repeatedly find smallest and largest element and replace them with infinities.
    //time O(n^2) space O(1)
    // if(n==0) return {0}; //interfere with each other
    // int min,max;
    // while(true)
    // {
    //     min = 0,max = 0;
    //     for(int i=1;i<n;i++)
    //     {
    //         if(arr[i]>arr[max])
    //         {
    //             max = i;
    //         }
    //         else if(arr[i]<arr[min])
    //         {
    //             min = i;
    //         }
            
    //     }
    //     if(k==1) break;
    //     k--;
    //     arr[min] = INT_MAX;
    //     arr[max] = INT_MIN;
    // }
    //     return {arr[min],arr[max]};

    //sol2:updated only min values replace with int max. O(n^2)
    //left--
    //implement later - quickselect,heap tree,bruteforce.


}
int main()
{
    vector<int> arr = {1,2,5,4};
    int k = 3;
    int n = 4;
    for(auto i: kthSmallLarge(arr,n,k))
    {
        cout<< i<<" ";
    }
    cout<<endl;
}