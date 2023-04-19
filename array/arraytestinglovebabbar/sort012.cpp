#include <bits/stdc++.h>
using namespace std;
void sort012(int *arr, int n)
{
   //this is solved previously.
   //approach1: sort and then return time O(nlogn) space O(1)
//    sort(arr,arr+n);
   
   //option 2: bucket sort:
   //as it is given that there are only three possiblilites for the value we can just count them
   //in a different array and then replace them time O(2n) space O(1)
//    int temp[3] = {0,0,0};
//    for(int i = 0; i<n;i++) 
//    {
//         temp[arr[i]]++;
//    }
//    int i = 0;
//    while(i<temp[0])
//    {
//         arr[i] = 0;i++;
//    }
//    while(i<temp[0]+temp[1])
//    {
//         arr[i] = 1; i++;
//    }
//    while(i<n)
//    {
//         arr[i] = 2; i++;
//    }

   //approach 3: 3 pointer approach - use three pointers to track 0 1 and 2
   //time O(n) space O(1)
   int low = 0,mid = 0,high = n-1;
   while(mid<=high)
   {
        if(arr[mid]== 0){
            swap(arr[low],arr[mid]);
            low++;mid++;
        }
        else if(arr[mid] == 1) mid++;
        else{
            swap(arr[mid],arr[high]);
            high--;
        } 
   }

}
int main()
{
    int arr[] = {0, 0, 0, 1, 1, 0, 0, 1, 1, 0};
    sort012(arr,10);
    for(int i =0; i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}