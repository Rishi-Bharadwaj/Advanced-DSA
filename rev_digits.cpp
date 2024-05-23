//Reverse the digits of an integer
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//O(n), n is number of digits
int main()
{
    int n;
    cin>>n;
    stack<int> stack;
    int x = 1;
    int size = 0;
    int flag=1;
    while(flag!=0)
    {
        int t=n;
        flag= t/x;
        x=x*10;
        size++;
    }
    size=size-1;
    x=x/100;
    while(size!=0)
    {
        int t=n;
        stack.push(t/x);
        n=t%x;
        x=x/10;
        size--;
    }
    while(!stack.empty())
    {
        cout<<stack.top();
        stack.pop();
    }
    
}
