//Given an array of numbers, you need to return the count of reverse pairs.
// Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].

#include<iostream>
#include<vector>

using namespace std;
int count=0;

void merge(vector<int>& a, int low, int mid, int high)
{
    int n1=mid-low+1;
    int n2= high-mid;
    vector<int> temp1(n1,1);
    vector<int> temp2(n2,1);
    for(int i=low;i<=mid;i++)
    {
        temp1[i-low]=a[i];
    }
    for(int i=mid+1;i<=high;i++)
    {
        temp2[i-mid-1]=a[i];
    }

    int i=0,j=0,k=low;
    while(i<n1 && j<n2)
    {
        if(temp1[i]<=temp2[j])
        {
            a[k++]=temp1[i++];
        }
        else if(temp1[i]>temp2[j])
        {
            a[k++]=temp2[j];
            if(temp1[i]>2*temp2[j])
            {
                count+=(n1-i);
            }
            j++;
        }
    }
    while(i<n1)
    {
        a[k++]=temp1[i++];
    }
    while(j<n2)
    {
        a[k++]=temp2[j++];
    }
    // for(auto x:a)
    // cout<<x<<" ";
    // cout<<endl;
}

void msort(vector<int>& a, int low, int high)
{
    if(low>=high)
    return;
    int mid= (low+high)/2;
    msort(a,low,mid);
    msort(a,mid+1,high);
    merge(a,low,mid,high);
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n,1);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    msort(a,0,n-1);
    cout<<count;
}