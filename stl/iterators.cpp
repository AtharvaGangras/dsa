#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    vector<int> v = {2,4,53,4,43,55,3};
    for(int i = 0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    //iterator
    vector<int> ::iterator it = v.begin(); //points to the first element
                                            //end() points to the next element after last element
    cout<< *it<<endl;
    cout<< *(it +2)<<endl; //vector is contiguous

    for(it = v.begin(); it!=v.end();it++)
    {
        cout<<*it<<endl;
    }
    /*
    it++ -> moves to next iterator (works for non contiguous containers)
    it+1 -> moves to the next location  (invalid location for maps and sets).   
    */

   vector<pair<int,int>> v_p = {{1,2},{2,3},{3,4}};
   vector<pair<int,int>>::iterator pit;

   for(pit = v_p.begin();pit != v_p.end();pit++)
   {
        cout<<pit->first<<" "<<pit->second<<endl;
   }
}