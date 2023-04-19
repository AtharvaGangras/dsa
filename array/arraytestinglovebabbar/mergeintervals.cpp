#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    //solution 1: 
    //the intervals need not be in order so we sort them first
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> merged;
    //now use two loops to enter into merged array
    int n = intervals.size();
    int i = 0;
    int counter;
    
    while(i<n)
    {
        counter = 1;
        for(int j = i+1;j<n;j++)
        {
            if(intervals[i][1] >= intervals[j][0])
            {
                intervals[i][1] = max(intervals[i][1],intervals[j][1]);
                counter++;
            }
            else{
                break;
            }
        }
        merged.push_back(intervals[i]);
        i+=counter;
    }
    return merged;
}

int main()
{
    
}