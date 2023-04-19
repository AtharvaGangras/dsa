#include <bits/stdc++.h>
using namespace std;
int sumOfMaxMin(int arr[], int n){
	//approach 1: sort array and then first and last ele time (Nlogn)
    sort(arr, arr + n);
    return arr[0] + arr[n - 1];
    // approach 2: use for loop to get min and max element and then sum
    //time O(N) space O(1)
    int min = arr[0],max= arr[0];
    for(int i = 1; i<n;i++)
    {
        if(min>arr[i]) min = arr[i];
        else if(max<arr[i]) max = arr[i];
    }
    return min+max;
    //approach 3: divide and conquer -same time as above but minimises comparsions
    //do this in college skipped for now.

    

}
int main()
{
    int arr[] = {5,6,1,2,4,3,2,1};
    int n = 8;
    cout<<sumOfMaxMin(arr,n);
}