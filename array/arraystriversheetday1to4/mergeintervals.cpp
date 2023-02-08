#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // wrong solution intervals do not need to be in order -- can be made in order using inbuilt sort function
    // now the solution is correct but it is very slow.
        // sort(intervals.begin(),intervals.end());
        // int n = intervals.size();
        // vector<vector<int>>::iterator iter = intervals.begin();
        // for(int i = 0; i<n-1; i++)
        // {
        //     if(intervals[i][1]>=intervals[i+1][0])
        //     {   if(intervals[i][1] < intervals[i+1][1])
        //         intervals[i][1] = intervals[i+1][1];
        //         intervals.erase(iter+i+1);//this step takes a lot of time.
        //         i--;
        //         n--;
        //     }
        // }
    
    // return intervals;



    //bruteforce solution
    //put the intervals in new array and iterate -- time complexity O(N) -- two loops can be reduced to one as below.
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> sol;
    int size = intervals.size();
    int i = 0;
    int counter = 1;
    while(i<size)//first loop chooses the element. 
    {
        counter = 1; // jump counter.
        //now using the second loop to merge intervals
        for(int j = i+1; j<size;j++)
        {
            if(intervals[i][1]>=intervals[j][0])
            {
                if(intervals[i][1]<intervals[j][1]) intervals[i][1] = intervals[j][1]; 
                counter++;
            }
            else{
                break;
            }
        }
        sol.push_back(intervals[i]);//putting into solution
        i += counter;
    }
    return sol;

    //optimal approach -- time complexity O(N)
    sort(intervals.begin(), intervals.end());
  vector < vector < int >> merged;

  for (int i = 0; i < intervals.size(); i++) {
    if (merged.empty() || merged.back()[1] < intervals[i][0]) {
      vector < int > v = {
        intervals[i][0],
        intervals[i][1]
      };

      merged.push_back(v);
    } else {
      merged.back()[1] = max(merged.back()[1], intervals[i][1]);
    }
  }
  return merged;


    }
};
int main()
{
    Solution s;
    vector<vector<int>> vec = {{1,3},{2,6},{8,10},{15,18}};
    auto sol = s.merge(vec);
    for(auto i : sol)
    {   cout<<"{";
        for(auto j : i)
        {
            cout<<j<<" ";
        }
        cout<<"}";
    }
    cout<<endl;
}