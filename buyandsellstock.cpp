#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //m1 bruteforce -- using two loops timecomplexity - O(n^2) space O(1)
        //problem - timelimit exceeded.
        // int size = prices.size();
        // int maxprofit = 0;
        // for(int i = 0;i<size;i++)
        // {
        //     for(int j = i+1;j<size;j++)
        //     {
                
        //         if(prices[j]>prices[i]) maxprofit = max(prices[j]-prices[i],maxprofit);

        //     }
        // }
        // return maxprofit;

        // m2 - one pass - instead of two loops we will maintain a minimum value from the start of
        // array and compare time complexity O(n) space O(1)
        int maxprofit = 0,minele=INT_MAX;
        for(auto i : prices)
        {
            // if(i<minele) minele = i;
            // else if(i > minele) maxprofit = max(maxprofit,i-minele);
            minele = min(minele, i);
            maxprofit = max(maxprofit, i - minele);
        }
        return maxprofit;
    }
};
int main()
{
    Solution s;
    vector<int> vec = {7,1,5,3,6,4};
    cout<<s.maxProfit(vec)<<endl;
}