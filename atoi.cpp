class Solution {
public:
    int myAtoi(string s) {

        int n=s.size();
        int i=0;
        while(i<n && s[i]==' ')
        {
            i++;
        }

        int sf=0;

        if(s[i]=='-')
            {
                sf=1;
                i++;
            }
        else if(s[i]=='+')
        i++;

        int ef=0;

        int sum=0;
        while(i<n && s[i]>='0' && s[i]<='9')
        {
            
            int c= s[i]-'0';
            if(sum<=INT_MAX/10)
            sum=sum*10;
            else
            {
                sum=INT_MAX;
                cout<<sum<<endl;
            break;
            }
            
            if(sum <INT_MAX-c)
            sum=sum + c;
            else if(sum==INT_MAX-c && sf==1)
            {
                sum=sum+c;
                ef=1;
            }
            else 
            {
                sum=INT_MAX;
                cout<<sum<<endl;
            break;
            }
            cout<<sum<<endl;
            i++;
        }

        if(sf)
        {
            if(sum==INT_MAX && ef==0)
            sum=INT_MIN;
            else if(sum==INT_MAX && ef==1)
            sum= -INT_MAX;
            else
            sum= -sum;
        }

        return sum;
    }
};