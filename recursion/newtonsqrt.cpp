#include <bits/stdc++.h>
using namespace std;
double sqrtnewtonraphson(double n);
int main()
{   
    // double a = 40;
    // double root = sqrtnewtonraphson(a);
    // cout<<"The root of"<<a<<"is"<<root<<endl;
    cout<<5%1<<endl;
}
double sqrtnewtonraphson(double n){
    double x = n;
    while(true)
    {
        double root = 0.5*(x+n/x);
        if(abs(root-x)<1) return root;
        x = root;
        cout<<root<<endl;
    }
}