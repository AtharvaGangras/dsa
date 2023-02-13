#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <class T>
void print(const set<T> &s)
{
    cout<<"size:"<<s.size()<<endl;
    for(auto i : s)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
template <typename T2>
void print(const unordered_set<T2> &s)
{
    cout<<"size:"<<s.size()<<endl;
    for(auto i : s)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
template <typename T3>
void print(const multiset<T3> &s)
{
    cout<<"size:"<<s.size()<<endl;
    for(auto i : s)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
    //collection of some elements - has unique elements
    //multisets are used a lot

    set<string> s; //stores in sorted order
    s.insert("Abc"); // O(logn)
    s.insert("Acc");
    s.insert("Aac");
    s.insert("Aac");

    auto it = s.find("Aac"); // if exists returns iterator pointing to it else it.end(); O(logn)
    if(it != s.end())
        cout<< (*it)<<endl;
        s.erase(it);
    s.erase("Acc");
    print(s);

    cout<<endl;
    unordered_set<string> s2; //stores in unsorted order O(1) -> same difference as maps
    s2.insert("Abc"); // O(1)
    s2.insert("Acc");
    s2.insert("Aac");
    s2.insert("Aac1");

    auto it2 = s2.find("Aac"); // if exists returns iterator pointing to it else it.end(); O(logn)
    if(it2 != s2.end())
        cout<< (*it2)<<endl;
        s2.erase(it2);
    s2.erase("Acc");
    print(s2);

    cout<<endl;
    multiset<string> s3; //stores in sorted order
    //used in replacement priority queues
    s3.insert("Abc"); // O(logn)
    s3.insert("Acc");
    s3.insert("Aac");
    s3.insert("Aac");

    auto it3 = s3.find("Aac"); // if exists returns iterator pointing to the first existing value else it.end(); O(logn)
    if(it3 != s3.end())
        cout<< (*it3)<<endl;
        s3.erase(it3);
    s3.erase("Acc");
    s3.insert("Aac");
    s3.insert("Aac");
    s3.insert("Aac");
    s3.insert("Aac");
    print(s3);
    s3.erase("Aac"); //delets all the values
    print(s3);


    
}