//There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements.
//Without altering the relative order of positive and negative elements, you must return
//an array of alternately positive and negative values.
//O(2N)
#include<iostream>

using namespace std;

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
