#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;
template <typename T>
void printvec(const vector<T> &x)   //pass by reference
{
    for(int i = 0;i<x.size();i++) // size() -> O(1)
    {
        // cout<<x[i].first<<" "<<x[i].second<<endl;
        cout<<x[i]<<" ";


    }
    cout<<endl;
}
void printvec(const vector<vector<int>> &x)   //pass by reference
{
    for(int i = 0;i<x.size();i++) // size() -> O(1)
    {
        for(int j = 0; j< x[i].size(); j++)
        {
            cout<<x[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    // vector<pair<int,int>> v = {{1,2},{2,4},{4,5}};
    //v.pushback({1,4});
    // printvec(v);

    //array of vectors
    // int N;
    // cin>>N;
    // vector<string> v[N]; //acts like a 2d vector in which the number of rows are fixed but the 
    //                     //number of columns are variable.
    // for(int i = 0; i<N;i++)
    // {
    //     int size;
    //     cout<<"Size: ";
    //     cin>>size;
    //     for(int j = 0; j<size;j++)
    //     {
    //         string x;
    //         cin>>x;
    //         v[i].push_back(x);
    //     }
    // }
    // //printing
    // for(int i = 0; i<N;i++)
    // {
    //     printvec(v[i]);
    //     cout<<endl;
    // }
    // cout<< v[0][1]; // 1st element of 0th vector.

    
    //vector of vectors
    int N;
    cin>>N;
    vector<vector<int>> v; //acts like a 2d vector with variable rows and columns
    for(int i = 0; i<N;i++)
    {
        int size;
        cout<<"Size: ";
        cin>>size;
        vector<int> tmp;
        for(int j = 0; j<size;j++)
        {
            int x;
            cin>>x;
            tmp.push_back(x);
        }
        v.push_back(tmp);

    }
    //printing
    for(int i = 0; i<N;i++)
    {
        printvec(v[i]);
        cout<<endl;
    }
    printvec(v);
}