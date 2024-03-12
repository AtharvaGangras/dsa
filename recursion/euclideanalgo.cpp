#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b)
{
    if(a == 0)
        return b;
    return GCD(b%a,a);
}
int LCM(int a, int b)
{
    return a*b/GCD(a,b);
    return a*b/GCD(a,b);
}
int main()
{
    cout<<GCD(4,8)<<endl;
    cout<<LCM(5,7)<<endl;
}