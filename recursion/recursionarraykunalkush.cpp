#include <bits/stdc++.h>
using namespace std;
// given an array check if it is sorted or not.
//this program below changes the array
bool ifsort(vector<int> &v)
{
    if(v.size() == 1) return true;
    vector<int>::iterator iter = v.end();
    iter--;
    if(*iter >= *(iter -1)){v.pop_back(); return ifsort(v);}
    return false;


}
// without changing the array
bool helper(vector<int> &v , int i)
{
    if(i+1 == v.size()) return true;
    if(v[i] <= v[i+1]) return helper(v,i+1);
    return false;
    // return v[i] <= v[i+1] && helper(v,i+1); // don't do this as the entire stack is called regardless if a function ends up false in between
}
bool ifsort2(vector<int> &v)
{
    return helper(v,0);
}

//linear search with recursion
int helper2(vector<int> &v, int target, int index)
{
    if(index>=v.size()) return -1;
    if(v[index] == target) return index;
    return helper2(v,target,index+1);
}
int linearsearch(vector<int> &v,int target){
    return helper2(v,target,0);
}
void helper3(vector<int> &v,int target,int index,vector<int> &vreturn)
{
    if(index>=v.size()) return;
    if(v[index] == target) vreturn.push_back(index);
    return helper3(v,target,index+1,vreturn);

}
vector<int> linearsearch2(vector<int> &v,int target){
    vector<int> vreturn;
    helper3(v,target,0,vreturn);
    return vreturn;
}
//without using helper function
vector<int> linearsearch3(vector<int> &v,int target,int index){
    vector<int> vreturn;
    if(index>=v.size()) return vreturn;
    if(v[index] == target) vreturn.push_back(index);
    vector<int> v2= linearsearch3(v,target,index+1);
    vreturn.insert(vreturn.end(),v2.begin(),v2.end());
    return vreturn;
}

//rotated binary search


int main()
{
    vector<int> v = {23,343,400,23,355454,23,33444444};
    // cout<<v.size();
    // cout<<ifsort2(v)<<endl;
    // cout<<v.size()<<endl;
    // for (int i = 0; i < v.size(); i++) 
    // cout << v[i] << " "; 
    // cout<<linearsearch(v,40);
    //get all indexes of repeated elements
    vector<int> out = linearsearch3(v,23,0);
    for(int i = 0; i<out.size(); i++)
    {
        cout<<out[i]<<" ";
    }

    cout<<endl;
}