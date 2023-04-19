#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;//size of array
    int arr[n];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;//value to be rotated.
    cin>>k;

    // //approach 1: bruteforce - first print shifted elements then print the starting elements
    // //this is not allowed
    // for(int i = k;i<n;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // for(int i = 0; i<k;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }

    // //approach 1: bruteforce storing first element in temp variable and shifting
    // int temp;
    // while(k!=0)
    // {
    //     temp = arr[0];
    //     for(int i = 0;i<n-1;i++)
    //     {
    //         arr[i] = arr[i+1];
    //     }
    //     arr[n-1] = temp;
    //     k--;
    // }

    // for(int i = 0; i<n;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }

    // approach2: shifting array k times is nothing but shifting elements by k;
    int temp[k];
    for(int i = 0;i<k;i++)
    {
        temp[i] = arr[i];
    }
    for(int i = 0;i<n-k;i++)
    {
        arr[i] = arr[k+i];
    }
    for(int i = 0;i<k;i++)
    {
        arr[n-k+i] = temp[i];
    }
    for(int i = 0; i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;