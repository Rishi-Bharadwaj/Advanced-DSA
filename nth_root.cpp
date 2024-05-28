// Given two numbers N and M, find the Nth root of M.
 // The nth root of a number M is defined as a number X when raised to the power N equals M. If the 'nth root is not an integer, return -1.

#include<iostream>

using namespace std;

int power(int n,int m,int k)
{
    if(n==1)
    return k;
    else
    return power(n-1,m,m*k); 
}


int main()
{
    int n,m;
    cin>>n>>m;
    
    int low=0,high=m;
    while(low<=high)
    {
        int mid = (low+high)/2;
        int t = power(n,mid,mid);
        if(t==m)
        {
            cout<<mid;
            exit(1);
        }
        
        else if(t<m)
        {
            low=mid+1;
        }
        else
        high=mid-1;
    }
    cout<<"-1";
}