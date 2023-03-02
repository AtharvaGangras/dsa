#include <bits/stdc++.h>
using namespace std;
long long maxSubarraySum(int arr[], int n)
{
    //approach 1: bruteforce - 2loops
    //first loop for start of subarray second for end
    //time complexity O(n^2)
    // int maxsum = INT_MIN;
    // int sum = arr[0];
    // for(int i = 0; i<n;i++)
    // {   sum = 0;
    //     for(int j = i;j<n;j++)
    //     {
    //         sum += arr[j];
    //         maxsum = max(sum,maxsum);
    //     }
    
    // }
    // maxsum = max(maxsum,0);
    // return maxsum;
    //approach 2: kadane's algorithm store sum till previous element if positive else discard
    //time complexity O(N) space O(1)
    long long sum = 0;
    long long maxsum = INT_MIN;
    for(int i= 0;i<n;i++)
    {
        sum += arr[i];
        if(sum < 0) sum = 0;
        maxsum= max(maxsum,sum);
    }
    return maxsum;

    //approach 3: mergesort
     /*  
    Time Complexity : O(N * log(N))
    Space Complexity : O(N)

    Where N is the length of array.
*/


// long crossSum(int* arr, int low, int high, int mid) {

//     if (low == high) {
//         return arr[low];
//     }

//     long leftSubsum = 0;
//     long currSum = 0;

//     // maximum subarray sum by including elements on left of mid.
//     for (int i = mid; i > low - 1; --i) {

//         currSum += arr[i];
//         leftSubsum = max(leftSubsum, currSum);

//     }

//     long rightSubsum = 0;
//     currSum = 0;

//     // maximum subarray sum by include elements on right of mid.
//     for (int i = mid + 1; i < high + 1; ++i) {

//         currSum += arr[i];
//         rightSubsum = max(rightSubsum, currSum);

//     }

//     return leftSubsum + rightSubsum;
// }

// long maxSubarraySumHelper(int* arr, int low, int high) {
//     // if there is only one element.
//     if (low == high) {
//         return arr[low];
//     }

//     int mid = (low + high) / 2;

//     // left maximum subarray sum
//     long leftSum = maxSubarraySumHelper(arr, low, mid);

//     // right maximum subarray sum
//     long rightSum = maxSubarraySumHelper(arr, mid + 1, high);

//     // Maximum subarray sum such that the subarray crosses the midpoint.
//     long crossS = crossSum(arr, low, high, mid);

//     return max(max(leftSum, rightSum), crossS);
// }


// long maxSubarraySum(int* arr, int n) {

//     return maxSubarraySumHelper(arr, 0, n - 1);
// } 


}
int main()
{
    int arr[] = {18, -6, -6, -5, 7, 10, 16, -6, -2, 0 };
    int n = 10;
    cout<<maxSubarraySum(arr,n);
}