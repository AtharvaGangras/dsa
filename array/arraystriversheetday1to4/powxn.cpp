#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double myPow(double x, int n)
    {
        // from the ques we can see that n is an integer;
        // method 1: bruteforce/naive using for loop and multiply --O(n)
        // double ans = 1;
        // if (n == 0)
        //     return ans;
        // else if (n > 0)
        // {
        //     for (int i = 0; i < n; i++)
        //     {
        //         ans *= x;
        //     }
        //     return ans;
        // }
        // else
        // {
        //     for (int i = 0; i < -1*n; i++)
        //     {
        //         ans *= x;
        //     }
        //     return 1/ans;
        // }

        //method 2: binary exponentiation O(logn)
        long long nn = n;
        double ans = 1;
        if(nn<0) nn *= -1;
        while(nn)
        {
            if(!(nn%2))
            {
                x = x*x;
                nn /= 2;
            }
            else{
                ans *= x;
                nn--;
            }
        }
        if(n<0) return (double)1.0/(double)ans;
        else return ans;
    }

};
int main()
{
    Solution s;
    cout << s.myPow(2.10000, 3) << endl;
}