#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// void printvec(vector<int> x) // this sends the copy of the vector O(n) -> expensive operation
void printvec(const vector<int> &x)   //pass by reference
{
    for(int i = 0;i<x.size();i++) // size() -> O(1)
    {
        cout<<x[i]<<" ";

    }
    // x.push_back(2); // has no effect on orignal vector as it is pushed into the copy.
    cout<<endl;
}

int main(){
//     pair<int,string> p;
//     //enter values
//     // p = make_pair(2,"abc");
//     p = {2,"asdf"};
//     // pair<int,string> p1 = p; //makes a copy of p in p1.
//     pair<int,string> &p1 = p; //by reference

//     p1.first = 3;
//     cout<<p.first<<" "<<p.second<<endl;
//     cout<<p1.first<<" "<<p.second<<endl;

//     pair<int,int> p_array[3];
//     p_array[0] = {1,2};
//     p_array[1] = {2,3};
//     p_array[2] = {3,4};
//     swap(p_array[0],p_array[2]); //maintains the relation
//     for(int i = 0;i<3;i++)
//     {
//         cout<<p_array[i].first<<" "<<p_array[i].second<<endl;
//     }

    //vectors are arrays with dynamic size
    vector <int> v(10,3); // 10^7 maximum size for both vector and array online
    //10 elements already declared with 3 (by default 0 initialized);
    int n;
    cout<<"Size: ";
    cin>>n;
    for(int i = 0;i<n; i++)
    {
        int ele;
        cin>>ele;
        v.push_back(ele); // O(1)

    }
    printvec(v);
    v.pop_back(); // removes from end O(1)
    printvec(v);

    vector<int> v2 = v; //copy of v  O(n)
    v2.pop_back();
    cout<<endl;
    printvec(v);
    printvec(v2);
}