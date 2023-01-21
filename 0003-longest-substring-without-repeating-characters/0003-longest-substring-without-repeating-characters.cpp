class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> ump;
        int l=-1,mx=0;
        int i=0;
        while(i<n)
        {
            if(ump.find(s[i])!=ump.end() && ump[s[i]] > l)
            {
                l=ump[s[i]];
            }
            ump[s[i]]=i;
            mx=max(mx,i-l);
            i++;
        }
        return mx;
    }
};