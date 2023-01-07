#include <iostream>
#include<bits/stdc++.h>

using namespace std;
template <typename T,typename Tm>
void print(const map<T,Tm> &m)
{
    cout<<"size:"<<m.size()<<endl;
    for(auto pr: m)
    {
        cout<<pr.first<<" "<<pr.second<<endl;
    }
}
template <typename T,typename Tm>
void print(const unordered_map<T,Tm> &m)
{
    cout<<"size:"<<m.size()<<endl;
    for(auto pr: m)
    {
        cout<<pr.first<<" "<<pr.second<<endl;
    }
}
 
int main()
{
    //maps -> key:value pairs  normal maps,unordered maps(keys are unique)
    //normal maps -> keys in sorted order -> implemented using red black trees
    //urordered maps -> unsorted.

    // map<int,string> m;
    // m[1] = "abc"; // O(log(n)) ->depends on key
    // // m["athra"] = "asdkjfl"; for a map<string,string> -> O(logn)*stringsizeofkey
    // m[5] = "cdc";
    // m[3] = "acd";
    // m.insert({4,"acg"});
    // m[1] = "aaaaa"; //keys are unique so it will update
    // m.insert({1,"bbbbb"}); //as key 1 is already in map it will fail and value
    //                         // will not change
    // print(m);

    // map<int,int> m2;
    // m2[6];// O(log(n)) by default enters 0
    // print(m2);

    // auto it3 = m.find(20); // will return m.end if value not in map
    //                         // O(logn)
    // if(it3 == m.end())
    // {
    //     cout<<"value not in map"<<endl;
    // }
    // else
    // {
    //     cout<<it3->first<<" "<<it3->second<<endl;
    // }

    // m.erase(3); //O(logn)
    // print(m);
    // it3 = m.find(4);
    // if(it3 != m.end()) //prevents segmentation fault.
    //     m.erase(it3);
    // print(m);
    // m.clear();
    // print(m);

    /*
        unordered maps difference from normal maps
        1. inbuilt implementation -> hash table
        2. time complexity
        3. valid keys datatype(limited) -> cannot put pair as key
    */
    unordered_map<int,string> m;
    m[1] = "abc"; // O(1)
    m[5] = "cdc";
    m[3] = "acd";
    m.insert({4,"acg"});
    m[1] = "aaaaa"; //keys are unique so it will update
    m.insert({1,"bbbbb"}); //as key 1 is already in map it will fail and value
                            // will not change
    print(m);
    auto it3 = m.find(4); // O(1)
    cout<<it3->first<<" "<<it3->second<<endl;


}