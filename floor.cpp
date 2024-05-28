//You're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].
//The floor of x is the largest element in the array which is smaller than or equal to x.
//The ceiling of x is the smallest element in the array greater than or equal to x.

#include<iostream>
#include<vector>

using namespace std;

 int floor(vector<int> a, int k)
 {
    int n=size(a);
    int low=0,high=n-1;
    int curr=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;

        if(a[mid]>k)
        {
            high=mid-1;
        }
        else if(a[mid]<=k)
        {
            curr=a[mid];
            low=mid+1;
        }
    }
    return curr;
 }
  int ciel(vector<int> a, int k)
 {
    int n=size(a);
    int low=0,high=n-1;
    int curr=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;

        if(a[mid]<k)
        {
            low=mid+1;
        }
        else if(a[mid]>=k)
        {
            curr=a[mid];
            high=mid-1;
        }
    }
    return curr;
 }

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n,-1);
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<floor(a,k)<<" "<<ciel(a,k);

}