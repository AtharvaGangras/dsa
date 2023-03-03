#include <bits/stdc++.h>
using namespace std;
int minimizeIt(vector<int> A, int k)
{
    // approach 1: bruteforce : sort the array and then add subtract based on conditions
    // time complexity O(nlogn)
    //I have still not understood this at all
    sort(A.begin(),A.end());
    int n = A.size();
    int ans = A[n-1]-A[0];
    int mini = A[0]+k,maxi = A[n-1]-k;
    int current_min,current_max;
    for(int i = 0; i<n;i++)
    {
        current_min = min(mini,A[i+1]-k);
        current_max = max(maxi,A[i]+k);
        if (current_min>=0){
            ans = min(ans,current_max-current_min);
        }
    }
    return ans;
}
int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    int k = 2;
    cout<<minimizeIt(a,k);
}