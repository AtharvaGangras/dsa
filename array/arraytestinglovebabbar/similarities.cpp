#include <bits/stdc++.h>
using namespace std;
pair < int , int > findSimilarity(vector < int > arr1, vector < int > arr2, int n, int m) 
{
	//approach1: bruteforce-- use two loops to find common elements
    //time O(nm) space O(1)
    // int counter = 0;
    // pair<int,int> ans;
    // for(auto i : arr1)
    // {
    //     for(auto j : arr2)
    //     {
    //         if(i == j) 
    //         {
    //             counter++;
    //             break;
    //         }
    //     }
    // }
    // ans.first = counter;
    // ans.second = n+m - counter;//n(aUb) = n(a) + n(b) - n(a intersection b);
    // return ans;

    //approach 2: sorting the array and then using 2 pointers to traverse and count;
    //time O(n+mlogn+m + n+m) space O(1)
    // sort(arr1.begin(),arr1.end());
    // sort(arr2.begin(),arr2.end());
    // auto ptr1 = arr1.begin(),ptr2 = arr2.begin();
    // int counter = 0;
    // pair<int,int> ans;
    // while(ptr1!=arr1.end() && ptr2!= arr2.end())
    // {
    //     if(*ptr1 == *ptr2)
    //     {
    //         counter++;
    //         ptr1++;ptr2++;
    //     }
    //     else if(*ptr1>*ptr2)
    //     {
    //         ptr2++;
    //     }
    //     else{
    //         ptr1++;
    //     }
    // }
    // ans.first = counter;
    // ans.second = n+m - counter;//n(aUb) = n(a) + n(b) - n(a intersection b);
    // return ans;

    //approach3:use unordered map to store and find
    //time O(n+m) assuming insertion and find time O(1) space O(n);
    unordered_map<int,int> m1;
    int counter = 0;
    pair <int,int> ans;
    for(auto i : arr1)
    {
        m1[i] = 1;
    }
    for(auto j: arr2)
    {
        if(m1.find(j)!= m1.end())
        {
            counter++;
        }
    }
    ans.first = counter;
    ans.second = n+m - counter;//n(aUb) = n(a) + n(b) - n(a intersection b);
    return ans;

         
}
int main()
{
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {2,4,6,8};
    pair <int,int> ans = findSimilarity(v1,v2,v1.size(),v2.size());
    cout<<ans.first<<" "<<ans.second<<endl;
}