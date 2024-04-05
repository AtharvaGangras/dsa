#include <bits/stdc++.h>
using namespace std;
//this is wrongly written self solution
// pair<int, int> firstandlast(vector<int> &v, int target)
// {
//     // find the element lesser than target
//     // find the element greater than target
//     // l+1 , g-1
//     if (v.size() == 0) return {-1,-1};
//     int s = 0, e = v.size(), m;
//     pair<int, int> ans;
//     // greater element
//     while (s <= e)
//     {
//         m = (s + e) / 2;
//         if (target < v[m])
//         {
//             e = m - 1;
//         }
//         else
//         {
//             s = m + 1;
//         }
//     }
//     ans.second = s-1;
//     // smaller element
//     s = 0, e = v.size();
//     while (s <= e)
//     {
//         m = (s + e) / 2;
//         if (target > v[m])
//             s = m + 1;
//         else
//             e = m - 1;
//     }
//     ans.first = e+1;
//     if (v[ans.first] != target)
//     {
//         ans.first = -1;
//         ans.second = -1;
//     };
//     if (ans.second == v.size() && v[ans.second] != target)
//     {
//         ans.first = -1;
//         ans.second = -1;
//     };
//     return ans;
// }

// vector<int> firstandlast(vector<int> &v,int target)
// {
//     //approach - find first occurence of 7 and find last occurence of 7
//         int s = 0, e = v.size(), m;
//     vector<int> ans;
//     // smaller element
//     while (s <= e)
//     {
//         m = (s + e) / 2;
//         if (target <= v[m])
//         {
//             e = m - 1;
//         }
//         else
//         {
//             s = m + 1;
//         }
//     }
//     ans.push_back(m);
//     //larger element
//     s = 0,e = v.size();
//     while (s <= e)
//     {
//         m = (s + e) / 2;
//         if (target >= v[m])
//         {
            
//             s = m + 1;
//         }
//         else
//         {
//             e = m - 1;
//         }
//     }
//     ans.push_back(m-1);
//     return ans;

// }
int search(vector<int> &t,int target,bool findStartIndex)
{   
    int ans = -1;
    int s = 0, e = t.size() - 1, m;
    while (s <= e)
    {
        m = (s + e) / 2;
        if (t[m] == target)
        {
            //potential answer is found
            ans = m;
            if(findStartIndex){
                e = m-1;
            }
            else{
                s = m+1;
            }
        }  
        else if (target < t[m])
            e = m - 1; // search in left side
        else
            s = m + 1; // search in right side
    }
    return ans;
}
vector<int> firstandlast(vector<int> &v,int target){
    
    vector<int> ans = {-1,-1};

    
    //find the first occcurence
    ans[0] = search(v,target,true);
    //find the last occurence
    ans[1] = search(v,target,false);

    return ans;
}



int main()
{
    vector<int> v = {1,3,4,4,4,4,4,4,4,7,8,};
    int target = 4;
    vector<int> ans = firstandlast(v, target);
    for(int i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
}