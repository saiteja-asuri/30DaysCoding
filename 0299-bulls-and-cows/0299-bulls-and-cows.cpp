class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> ump;
        int bull=0,cow=0;
        string ng;
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i])
                bull++;
            else
            {
                ump[secret[i]]++;
                ng+=guess[i];
            }
        }
        for(int i=0;i<ng.size();i++)
        {
            if(ump[ng[i]]>0)
            {
                ump[ng[i]]--;
                cow++;
            }
        }
        return to_string(bull)+"A"+to_string(cow)+"B";
    }
};