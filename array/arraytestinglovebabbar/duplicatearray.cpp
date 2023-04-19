#include <bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int> &arr) 
{
    //solution 1: bruteforce solution O(n^2) use two loops to find the duplicate
    // for (int i = 0; i <arr.size(); i++)
    // {
    //     int element = arr[i];
    //     for (int j = i+1; j < arr.size(); j++)
    //     {
    //         if(element == arr[j])
    //         {
    //             return arr[j];
    //         }
    //     }
        
    // }
    // return 0;
    //solution 2: by sorting the array and find consequtive element O(nlogn +n)
    // sort(arr.begin(),arr.end());
    // for (int i = 1; i < arr.size(); i++)
    // {
    //     if(arr[i] == arr[i-1])
    //     {
    //         return arr[i];
    //     }
    // }
    // return 0;

    //solution 3:declare another array and use it as a flag array
    // vector <int> flag(arr.size(),0);
    // for(int i = 0;i<arr.size();i++)
    // {
    //     if(flag[arr[i]] == 0) flag[arr[i]] = 1;
    //     else return arr[i];
    // }
    // return 0;
    //xor based solution
    /*
    duplicate = 1^1^2^2^3^3...^(n-1)^(n-1)^duplicateextra
    as the starting value will be 0 as 1^1 is 0 ... the value of the duplicate will be duplicate extra
    */
    int duplicate = 0;
    for(int i = 0; i<arr.size();i++)
    {
        duplicate^=i;
        duplicate^= arr[i];
    }
    return duplicate;
    //linked list cycle method -- do loter
}
int main()
{
    vector<int> vec = {1,2,3,4,4};
    cout<<findDuplicate(vec);
}