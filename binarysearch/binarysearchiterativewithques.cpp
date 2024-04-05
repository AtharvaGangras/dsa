#include <bits/stdc++.h>
using namespace std;

// writing binary search for this ascending array
int binarysearch(vector<int> &v, int target)
{
    int s = 0, e = v.size() - 1, m;
    while (s <= e)
    {
        m = (s + e) / 2;
        if (v[m] == target)
            return m;
        else if (target < v[m])
            e = m - 1; // search in left side
        else
            s = m + 1; // search in right side
    }
    return -1;
}
// binary search for descending array
int binarysearchdesc(vector<int> &v, int target)
{
    int s = 0, e = v.size() - 1, m;
    while (s <= e)
    {
        m = (s + e) / 2;
        if (v[m] == target)
            return m;
        else if (target < v[m])
            s = m + 1; // search in right side instead even if target is smaller than current element
        else
            e = m - 1; // search in right side
    }
    return -1;
}

// order agnostic binary search- we don't know if array is in ascending or descending
// given sorted array but don't know ascending or descending
int binarysearchorderagnos(vector<int> &v, int target)
{
    if (v[0] < v[v.size() - 1])
        return binarysearch(v, target);
    return binarysearchdesc(v, target);
}

// ceiling of a given number: smallest element in aray greater or equal to target elemnt
// first do binary search
int ceiling(vector<int> &v, int target)
{
    if(target> v[v.size()-1]) return -1;
    int s = 0, e = v.size() - 1, m;
    while (s <= e)
    {
        m = (s + e) / 2;
        if (v[m] == target)
            return m;
        else if (target < v[m])
            e = m - 1; // search in left side
        else
            s = m + 1; // search in right side
    }
    // while (v[m] < target) // this complication not needed just return start as start = m+1
    // {
    //     if (m != v.size())
    //     {
    //         m++;
    //     }
    //     else
    //     {
    //         return -1;
    //     }
    // }
    // return m;
    return s;
}

//find the floor of a number
int flooor(vector<int> &v, int target)
{
    if(target< v[0]) return -1;
    int s = 0, e = v.size() - 1, m;
    while (s <= e)
    {
        m = (s + e) / 2;
        if (v[m] == target)
            return m;
        else if (target < v[m])
            e = m - 1; // search in left side
        else
            s = m + 1; // search in right side
    }
    return e;
}

//greater character
char greatchar(vector<char> &v, char target)
{
    if(target>= v[v.size() -1]) return v[0];
    int s = 0, e = v.size() - 1, m;
    while (s <= e)
    {
        m = (s + e) / 2;
        if (target < v[m])
            e = m - 1; // search in left side
        else
            s = m + 1; // search in right side
    }
    return v[s];
}

int main()
{
    vector<int> v = {1, 3, 4, 6, 12, 18, 75, 90};
    vector<int> v2 = {90, 75, 18, 12, 6, 4, 3, 1};
    vector<int> v3 = {2, 3, 5, 9, 14, 16, 18};

    // cout<<binarysearch(v,14)<<endl;
    // cout<<binarysearchdesc(v2,3)<<endl;
    // cout<<binarysearchorderagnos(v2,18)<<endl;
    // cout << v3[flooor(v3, 17)] << endl;

    vector<char> v4 = {'c','f','i','l','p','s'};
    cout<<greatchar(v4,'z');
}