//Given an array of N integers, your task is to find unique quads that add up to 0.
//O(N^3)
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

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
        for(int j=0;j<n;j++)
        {
            if(j==i)
            continue;
            int l=0,r=n-1;
            while(l<r)
            {
                if(l==i || l==j)
                {
                    l++;
                    continue;
                }
                else if(r==i || r==j)
                {
                    r--;
                    continue;
                }
                if((a[i]+a[j]+a[l]+a[r])==0)
                {
                    vector<int> temp={a[i],a[j],a[l],a[r]};
                    sort(temp.begin(),temp.end());
                    set.insert(temp);
                    l++;
                }
                else if((a[i]+a[j]+a[l]+a[r])<0)
                {
                    l++;
                }
                else
                r--;
            }
        }
    }

    for (auto arr:set)
    {
        cout<<"[";
        for(auto ele:arr)
        {
            cout<<ele<<" ";
        }
        cout<<"]";
    }

}
