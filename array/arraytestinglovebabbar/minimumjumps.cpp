#include <bits/stdc++.h>
using namespace std;
// int minjumps(vector<int> &arr,int current_ind){
//     if(current_ind >= arr.size()) return -1;
//     else if( current_ind == arr.size()-1) return 0;
//     else{
//         int jumps = 0,min_jumps = INT_MAX;
//         int flag = 1;
//         for(int i = arr[current_ind];i>=1;i--)
//         {
//             jumps = minjumps(arr,current_ind+i);
//             if(jumps == -1) continue;
//             jumps++;
//             flag = 0;
//             min_jumps = min(jumps,min_jumps);
//         }
//         if(flag) return -1;
//         return min_jumps;
        
//     } 
// }
// int minimumJumps(vector<int> &arr, int n)
// {
//     // //approach 1(try): bruteforce calculate all possible paths and jumps
//     // //for loop will be near impossible to write 
//     // //we need to do this recursively
//     // int min_jumps = -1;
//     // int jumps = -1;
//     // //for all combinations if reaching n-1 is possible get jumps to number of jumps else make it -1
//     // int s = n-1; //represents the number of spaces to be passed over
//     // int current_index = 0;
//     // while(s!=0)
//     // {

//     // }
//     //approach 1: recursive recursively call minimum jumps function for all possible jumps of the 
//     //current index and then find min jumps between them and then return
//     //base case will be if i exceeds n-1 or arr[i] = 0
//     //TLE - time complexity
//     int ans = minjumps(arr,0);
//     return ans;
    
// }
//solution 2: using loop find the biggest element in the subarray and choose that index to jump at
//time complexity O(n)
int minimumJumps(vector<int> &arr, int n)
{   
    if(n == 1) return 0;
    int current_ind = 0;
    int jumps = 0;
    while(current_ind != n-1)
    {
        int maxival = 0;
        int maxind;
        int loo = current_ind+arr[current_ind];
        if(loo>= arr.size()-1) break;
        for(int i = current_ind+1;i<=loo;i++)//debug this probably need it to stop exceeding array index 
        {
            if(maxival<=i+arr[i])
            {
                maxival = i+arr[i];
                maxind = i;
            }
        }
        jumps++;
        current_ind = maxind;
    }
    jumps++;
    return jumps;
}

int main()
{
    vector<int> arr = {10,9,8,7,6,5,4,3,2,1,1,0};
    cout<<minimumJumps(arr,arr.size());
}