#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    pair<int,string> p;
    //enter values
    // p = make_pair(2,"abc");
    p = {2,"asdf"};
    // pair<int,string> p1 = p; //makes a copy of p in p1.
    pair<int,string> &p1 = p; //by reference

    p1.first = 3;
    cout<<p.first<<" "<<p.second<<endl;
    cout<<p1.first<<" "<<p.second<<endl;

    //video at 5 min
}