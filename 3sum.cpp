//Problem Statement: Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. 
//In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;


int main()

{
    int n;
    cin>>n;
    vector<int> a(n,-1);
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(a.begin(),a.end());

    set<vector<int>> set;

    for(int i=0;i<n;i++)
    {
        int m=-a[i];
        int l=0,r=n-1;

        while(l<r){
        if(l==i)
        {
            l++;
            continue;
        }
        if(r==i)
        {
            r--;
            continue;
        }

        if((a[l]+a[r])==m)
        {
            vector<int> temp ={a[i],a[l],a[r]};
            sort(temp.begin(),temp.end());
            set.insert(temp);
            l++;
            break;
        }
        else if((a[l]+a[r])>m)
        {
            r--;
        }
        else
        l++;
    }
    }
    for (auto it : set) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
}