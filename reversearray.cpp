#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h> 
void reverseArray(vector<int> &arr , int m)
{
	//approach 1: bruteforce time O(n) space O(n)
    // int n = arr.size();
    // vector<int> tmp(n-m-1,0);
    // for(int i = m+1;i<n;i++)
    // {
    //     //put the values in array in reverse order
    //     tmp[i-m-1] = arr[n-i+m];
    // }
    // //copy paste in old array
    // for(int i = m+1;i<n;i++)
    // {
    //     arr[i] = tmp[i-m-1];
    // }
    //approach 2: 2 pointer approach O(n/2) space O(1)
    //time complexity O(n/2) space O(1) use two pointer and swap elements
    //2 cases even odd
    int i = m+1,j = arr.size() -1;
    while(i<j)
    {
        swap(arr[i],arr[j]);
        i++;j--;
    }

}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    reverseArray(arr,3);
    for(auto i : arr) cout<<i<<" ";
    cout<<endl;
}