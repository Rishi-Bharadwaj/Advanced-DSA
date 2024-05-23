//Given an integer array arr, find the contiguous subarray 
//(containing at least one number) which
//has the largest sum and returns its sum and prints the subarray.
//O(N)
#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int end=0;
    int length=0;
    int m_length=0;
    int sum=0;
    int max_sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        length++;
        if(sum>0)
        {
            if(sum>max_sum)
            {
                max_sum=sum;
                end=i;
                m_length=length;
            }
        }
        else
        {
            sum=0;
            length=0;
        }
    }
    cout<<"sum:"<<max_sum<<endl;
    for(int i=end-m_length+1;i<=end;i++)
    {
        cout<<arr[i]<<" ";
    }
}
