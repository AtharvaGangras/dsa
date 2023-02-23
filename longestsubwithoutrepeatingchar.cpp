#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //bruteforce - checking for all strings and using set to store data
        //timecomplexity O(n^2);
        // int maxcount = 0;//maximum size of string
    
        // for(int i = 0; i<s.size();i++)
        // {
        //     int count = 0;//max size of current string
        //     unordered_set<char> c;
        //     for(int j = i;j<s.size();j++)
        //     {
        //         if(c.find(s[j]) != c.end()) break;
        //         count++;
        //         c.insert(s[j]);


        //     }
        //     maxcount = max(maxcount,count);
        // }
        // return maxcount;

        //approach2: left and right pointer - right moves if no repeat ,if repeat then left moves to 
        //eliminate it.
        //time O(2n)
        // unordered_set<char> store;
        // int l = 0,r= 0,len = 0;
        // while(r<s.size())
        // {
        //     if(store.find(s[r])==store.end())
        //     {
        //         len = max(len,r-l+1);
                
        //     }
        //     else
        //     {
        //         while(store.find(s[r])!= store.end())
        //         {
        //             store.erase(s[l]);
        //             l++;
        //         }
        //     }
        //     store.insert(s[r]);
        //     r++;
        // }
        // return len;

        //approach 3: same as above but using a map to store index for left pointer. 
        //time - O(n) space -O(N)
        unordered_map<char,int> store;
        int l = 0,r= 0,len = 0;
        while(r<s.size())
        {
            if(store.find(s[r])!=store.end())
            {
                l = max(l,store[s[r]]+1);
            }
            len = max(len,r-l+1);
            store[s[r]] = r;
            r++;
        }
        return len;
    }

};
int main()
{
    Solution s;
    string s2 = "tmmzuxt";
    cout<<s.lengthOfLongestSubstring(s2)<<endl;
}