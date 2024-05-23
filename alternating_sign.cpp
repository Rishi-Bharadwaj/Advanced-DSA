#include<iostream>

using namespace std;

//O(2N)

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int ans[n];
    int a=0,b=0;
    for(int i=0;i<n;i+=2)
    {
        while(arr[a]<0 && a<n)
        a++;
        while(arr[b]>0 && b<n)
        b++;
        ans[i]=arr[a];
        ans[i+1]=arr[b];
        a++;
        b++;
    }
    for(auto x:ans)
    cout<<x<<" ";
}