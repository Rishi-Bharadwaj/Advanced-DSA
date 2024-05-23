// Given the number of rows n. Print the first n rows of Pascal’s triangle.

#include<iostream>
#include<vector>

using namespace std;

void pascal(vector<int> prev,int x,int n)
{
    vector<int> f3(x,1);
            int i=1;
            for(;i<x-1;i++)
            {
                f3[i]= prev[i-1]+prev[i];
            }
            for(int j=0;j<(n-x);j++)
            cout<<" ";
            for(int j=0;j<x;j++)
            cout<<f3[j]<<" ";
            cout<<endl;
            if(x<n)
            {
                pascal(f3,x+1,n);
            }
}

int main()
{
    int n;
    cin>>n;
    vector<int> f1(1,1);
    vector<int> f2(2,1);

    if(n==1)
    cout<<f1.at(0);
    else 
    {
        for(int j=0;j<n-1;j++)
            cout<<" ";
        cout<<f1.at(0)<<endl;
        pascal(f2,2,n);
    }
}