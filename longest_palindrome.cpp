//Given a string s, return the longest 
//palindromic substring in s.

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int i=0;
        int curr;
        int max=1;
        string str;
        str=s[0];

        while(i<n)
        {
            curr=1;
            int a=i-1,b=i+1;
            while(a>=0 && b<=n && s[a]==s[b])
            {
                a--;b++;
                curr+=2;
            }
            if(curr>max)
            {
                str.resize(b-a-1);
                for(int k=a+1;k<=b-1;k++)
                {
                    str[k-a-1]=s[k];
                }
                max=curr;
            }
            i++;
        }
        i=0;
        while(i<n)
        {
            curr=0;
            int a=i,b=i+1;
            while(a>=0 && b<=n && s[a]==s[b])
            {
                a--;b++;
                curr+=2;
            }
            if(curr>max)
            {
                str.resize(b-a-1);
                for(int k=a+1;k<=b-1;k++)
                {
                    str[k-a-1]=s[k];
                }
                max=curr;
            }
            i++;
        }

        return str;
    }
};