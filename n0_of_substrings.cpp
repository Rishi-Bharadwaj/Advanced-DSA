//Given a string s, return the number of homogenous substrings of s. Since the answer may be too large, return it modulo 109 + 7.

//A string is homogenous if all the characters of the string are the same.

//A substring is a contiguous sequence of characters within a string.

class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size();
        int i=1,count=1;
        int curr_alpha=1;
        while(i<n)
        {
            if(s[i]==s[i-1])
            {
                curr_alpha=curr_alpha % 1000000007;
                curr_alpha++;
            }
            else
            {
                curr_alpha=1;
            }
            
            count+=curr_alpha;
            count=count % 1000000007;
            i++;
        }
        return count;
    }
    
};