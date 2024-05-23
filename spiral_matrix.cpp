//Given an n x m matrix print its elements in a spiral manner
//O(nm)
#include<iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>a[i][j];
    }
    int left=0,right=m-1,top=0,bottom=n-1;
    
    while(left<=right && top<=bottom){

    for(int i=left;i<=right;i++)
    cout<<a[top][i]<<" ";
    top++;

    for(int i=top;i<=bottom;i++)
    cout<<a[i][right]<<" ";
    right--;

    for(int i=right;i>=left;i--)
    cout<<a[bottom][i]<<" ";
    bottom--;

    for(int i=bottom;i>=top;i--)
    cout<<a[i][left]<<" ";
    left++;
    }
}
