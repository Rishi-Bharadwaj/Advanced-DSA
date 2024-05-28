// Given two arrays, merge them without using any extra space.

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void swap(int*a,int*b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n,-1);
    vector<int> b(m,-1);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];

    int i=0;
    while(i<n)
    {
        if(b[0]<a[i])
        {
            swap(&b[0],&a[i]);
            sort(b.begin(),b.end());
        }
        i++;
    }
    for(auto x:a)
    cout<<x<<" ";

    for(auto x:b)
    cout<<x<<" ";

}