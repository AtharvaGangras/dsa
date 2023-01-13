#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
int main()
{   //for pairs,vectors and sets the first values are compared and if same then the next values are compared.
    // map <pair<int,int>,int> m;
    // map <set<int>,int> m2;

    //example 1
    map<pair<string,string>,vector<int>> m;

    //input for number of elements in map
    int n;
    cin>>n;

    for(int i = 0; i<n; i++)
    {
        // take the first and second element for pair and then no. of elements in vector.
        string fn,ln;
        int ct;
        cout<<"element"<<i+1<<endl;
        cin>> fn>>ln>>ct;

        cout<<"Enter vector elements"<<endl;
        for(int j = 0; j<ct;j++)
        {
            int x;
            cin>>x;
            m[{fn,ln}].push_back(x);
        }
        

    }

    //printing map
    cout<<endl;
    for(const auto &pr :m)
    {
        cout<<pr.first.first<<" "<<pr.first.second<<endl; // prints the pair
        for(auto &val: pr.second) //prints the vector
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }





}