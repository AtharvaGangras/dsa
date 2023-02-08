#include <bits/stdc++.h>
using namespace std;
int merge(long long arr[],int low,int mid,int high);
int mergesort(long long arr[],int low,int high);
long long getInversions(long long* arr, int n){
    // Write your code here.
    //solution 1 -- bruteforce method
    //using two loops time complexity O(n^2)
    // int count = 0;
    // for(int i = 0; i<n;i++)
    // {
    //     for(int j = i; j<n;j++)
    //     {
    //         if(arr[i]> arr[j]) count++;
    //     }
    // }
    // return count;

    //solution 2 using merge sort algorithm to compute and reduce the amount of comparisons 
    //time complexity O(nlogn) space O(n)
    long long ans = mergesort(arr,0,n-1);
    return ans;

    //sol3 fenwick tree
    //do later
}
int mergesort(long long arr[],int low,int high)
{   int count = 0;
    if(low<high)
    {   int mid = (low+high)/2;
        //sort left array
        count += mergesort(arr,low,mid);
        //sort right array
        count += mergesort(arr,mid+1,high);
        //merge them both
        count += merge(arr,low,mid,high);
    }
    return count;
}
int merge(long long arr[],int low,int mid,int high)
{   int count = 0;
    vector<long long> tmp (high+1);
    int i = low,j = mid+1,k = low; // i -> 1st array tracker j-> 2nd array tracker k-> copy tracker
    while((i<=mid) && (j<=high))
    {
        if(arr[i]> arr[j])
        {
            tmp[k] = arr[j];
            count = count +mid+1-i;
            j++;k++;
        }
        else
        {
            tmp[k] = arr[i];
            i++;k++;

        }
    }
    //if copying the remaining array
    while(i<=mid)
    {
        tmp[k] = arr[i];
        i++;k++;
    }
    while(j<= high)
    {
        tmp[k] = arr[j];
        j++;k++;
    }
    //copying temp array back into main array
    for(int i = low;i<=high;i++)
    {
        arr[i] = tmp[i];
    }
    return count;

}
 
int main()
{
    long long arr[] = {2,5,1,3,4};
    int size = 5;
    cout<<getInversions(arr,size)<<endl;
    for(auto i : arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}