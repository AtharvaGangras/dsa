#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    //range based loops
    vector<int> v = {2,3,4,4,5,6,7};

    for(int value:v)
    {
        cout<<value<<" "; //these are copies of the values
    }
    cout<<endl;
    for(int &value:v)
    {
        cout<<value<<" "; //these are actual values
    }
    cout<<endl;

    vector<pair<int,int>> v_p = {{1,2},{2,3},{3,4}};
    for(pair<int,int> &value:v_p)
    {
        cout<<value.first<<" " <<value.second<<endl; //these are actual values
    }
    
    //makes the code very short
    for(auto &value:v_p)
    {
        cout<<value.first<<" " <<value.second<<endl; //these are actual values
    }

    auto a = 1; //determines the datatype 

    //auto can automatically declare the iterator
    for(auto it = v_p.begin(); it!=v_p.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }

}