//A monkey is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.
//Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.
//Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.

//O(nlog(max(a[i])))

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int test(vector<float> a, float k,int h)
{
    float count=0;
    for(float x: a)
    {
        count+=ceil(x/k);
    }
    if(count>h)
    return 0;
    else 
    return 1;
}
int main()
{
    int n,h;
    cin>>n>>h;
    vector<float> a(n,1);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int max=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>max)
        max=a[i];
    }

    int low= n;
    int high=max;
    int curr=max;
    while(low<=high)
    {
        int mid= (low+high)/2;
        if(test(a,mid,h))
        {
            curr=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    cout<<curr;
}