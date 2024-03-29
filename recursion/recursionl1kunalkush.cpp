#include <bits/stdc++.h>
using namespace std;
void prin(int num)
{
    if(num <= 0) return;
    cout<<num<<" ";
    prin(num-1);
}
void oneton(int num)
{
    if(num <= 0) return;
    oneton(num-1); // to print in reverse first call the function so that we get all numbers in the stack
    cout<<num<<" ";// now after all nums above have been printed this will be the last to print
    // basically print 1->n-1 first then print n
}
void chain(int num)
{
    if(num<=0) return;
    cout<<num<<" ";
    chain(num-1);
    cout<<num<<" ";

}
int fact(int num)
{
    if(num<=1) return 1;
    return num*fact(num-1);
}

//sum of digits
int sod(int n)
{
    if(n == 0) return 0;
    return n%10 + sod(n/10);
    
}

//product of digits
int pod(int n)
{
    if(n == 0) return 1;
    return n%10 * pod(n/10);
    
}
//reverse a number: last digit +_ rev(rest of number)
// we will use log to get number of digits
//ways to get number of digits
// 1. take sum = 0 outside globally and keep updating it. sum = sum*10 + current digit
//
int rev(int n)
{ 
        
        int noofdigits= (int)log10(n); //no of digits is logn +1 but we have to do -1 so it becomes total logn
        if(noofdigits == 0) return n; //base case only one digit remaining return
        int digit = n%10;
        return digit*pow(10,noofdigits)+rev(n/10);


}
// palindrome function
bool palin(int n)
{
    return n == rev(n);
}
bool helper(int n,int len){
    if(len == 1 || len == 0) return true;
    int t = n/pow(10,len-1);
    if(n%10 == t)
    {
        n = n% (int)pow(10,len-1);
        n = n%10;
        return helper(n,len-2);
    }
    return false;
}
bool palin2(int n)
{
    int len = (int)log10(n)+1; //finds the length of number
    if(len == 1) return true;
    int t = n/pow(10,len-1);
    // cout<<t<<endl;
    //compare first and last digit
    if(n%10 == t)
    {
        n = n% (int)pow(10,len-1);
        n = n/10;
        return helper(n,len-2);
    }
    return false;
}

// count no. of zeroes in a number
int zeros(int n)
{
    if(n == 0) return 0;
    if(n%10 == 0) return zeros(n/10) +1;
    return zeros(n/10);
}

// reduce a no. to zero question if even /2  if odd -1 from it count the no. of steps required
int reduction(int n)
{
    if(n == 0) return 0;
    if(n&1 == 1) n=n-1; // for odd number
    else n=n/2; //for even number
    return 1+ reduction(n);

}

int main()
{
    // prin(5);
    // chain(5);
    // cout<<fact(5);
    // cout<<sod(1324555);
    // cout<<pod(1234);
    // cout<<rev(5512321);
    // cout<<palin2(12321);
    // cout<<zeros(30210004);
    cout<<reduction(41);
    cout<<endl;
}