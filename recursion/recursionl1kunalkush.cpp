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
int rev(int n)
{ 
        
        int noofdigits= (int)log10(n); //no of digits is logn +1 but we have to do -1 so it becomes total logn
        if(noofdigits == 0) return n; //base case only one digit remaining return
        int digit = n%10;
        return digit*pow(10,noofdigits)+rev(n/10);


}

int main()
{
    // prin(5);
    // chain(5);
    // cout<<fact(5);
    // cout<<sod(1324555);
    // cout<<pod(1234);
    cout<<rev(5512321);
    cout<<endl;
}