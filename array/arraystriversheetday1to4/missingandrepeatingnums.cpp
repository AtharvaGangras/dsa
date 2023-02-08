#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// optimal sol - time complexity - O(n) space - O(1)

	//sol1: another array approach time O(2n)  space O(n)
	// vector<int> val (n+1,0);
	// pair <int,int> mr;
	// for(auto i : arr)
	// {
	// 	val[i]++; //O(n)
	// }
	// for(int i = 1; i<=n ; i++)//O(n)
	// {
	// 	if(val[i] == 2) mr.second = i;
	// 	else if (val[i] == 0) mr.first = i;
	// }
	// return mr;
    
    
    //sol2: using math time O(n) space O(1)
    /*
    math equations
    ideal sum of natural = sum we got - value of missing num + value of repeating num
    ideal sum of square = sum we got - value of missing num + value of repeating num
    s1  = s - m+p
    s1-s = p-m  --1
    sq1 -s = p**2 - m**2  -- 2
    sq1 -s = (p-m)(p+m)  -- substitute and solve
    */
   	// long long int len = arr.size();

    // long long int S = (len * (len+1) ) /2;
    // long long int P = (len * (len +1) *(2*len +1) )/6;
    // long long int missingNumber=0, repeating=0;
     
    // for(int i=0;i<arr.size(); i++){
    //    S -= (long long int)arr[i];
    //    P -= (long long int)arr[i]*(long long int)arr[i];
    // }
     
    // missingNumber = (S + P/S)/2;

    // repeating = missingNumber - S;


    // return {missingNumber,repeating};

    //sol3 - XOR -- redo this later again for practice.https://takeuforward.org/data-structure/find-the-repeating-and-missing-numbers/
    /*
    xor of number with itself is 0
    xor of number with 0 is itself
    */
   //to hold xor nums
   int xor1;
   //hold set bit
   int setbit;
   //missing and repeated
   int m=0,r=0;

   xor1 = arr[0];
   for(int i = 1;i<n;i++)
   { // xor with the whole array O(n)
        xor1^=arr[i];
    // combining the second loop of xor with natural nos
   }
   for(int i = 1;i<=n;i++) //O(n)
   {
        xor1 ^= i;
   }

   //getting the rightmost 1 bit of the result
   setbit = xor1 & ~(xor1-1);

   //this xor1 gives us x^y - using the setbit as reference to divide into two buckets
   for(int i = 0;i<n;i++)
   {
        if(setbit & arr[i])
        {
            m ^= arr[i];
        }
        else
        {
            r ^= arr[i];
        }
   }
   for(int i = 1; i<=n;i++)
   {
        if(setbit & i)
        {
            m^= i;
        }
        else
        {
            r ^= i;
        }
   }

   //now finally checking for missing and repeated in correct order(as they can be either one)
   int count = 0;
   for(int i = 0; i<n;i++)
   {
        if(r == arr[i])
        {
            count++;
        }
   }
   if(count == 0)
   {
        //wrong order
        return {r,m};
   }
   return {m,r};

}

int main()
{
    vector<int> v = {3,3,2,1};
    int size = v.size();
    auto p = missingAndRepeating(v,size);
    cout<<p.first<<p.second<<endl;
}