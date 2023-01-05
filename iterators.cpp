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
    cout<< *(it +2)<<endl;
}