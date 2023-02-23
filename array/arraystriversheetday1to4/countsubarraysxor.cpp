#include <bits/stdc++.h>
using namespace std;
int subarraysXor(vector<int> &arr, int x)
{
    // method 1 count each subarrays using two loops
    //bruteforce O(N^2)
    // int n = arr.size();
    // int b = 0;
    // int count = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     b = 0;
    //     for (int j = i; j < n; j++)
    //     {
    //         b ^= arr[j];
    //         if (b == x)
    //         {
    //             count++;
    //         }
    //     }
    // }
    // return count;

    //approach 2:
    //storing prefix xor in hash map and then seeing if the required xor is available in hashmap
    //properties to remember xor a number with itself gives 0 and xor with 0 gives num itself
    //P = xor(a[0], a[1], a[2],..., a[q], a[q+1],..., a[p])
    // Q = xor(a[0], a[1], a[2],..., a[q])
// Therefore,
// P^Q = xor(a[q+1],..., a[p]) = M     
//time O(nlogn)
    unordered_map<int,int> mp;
    long long count = 0;
    int curxor = 0;
    int y = 0;
    for(auto i : arr)
    {
        curxor ^= i; //calculates the current xor.
        if(curxor == x) count++;
        y = curxor^x;
        if(mp.find(y)!= mp.end()) count+= mp[y];
        mp[curxor]++;

    }
    return count;


}
int main()
{
    vector<int> arr = {5,3,8,3,10};
    int x = 8;
    cout<<subarraysXor(arr,x);
}