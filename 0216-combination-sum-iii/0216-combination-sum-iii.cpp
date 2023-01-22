class Solution {
public:
    void getCombinations(vector<vector<int>> &res,int n,int k,int i,vector<int> &temp)
    {       
        if(n<0 || (n>0 && k==0))
            return ;
        if(n==0 && k==0)
        {
            res.push_back(temp);
            return ;
        }
        if(i>=10)
            return ;
        temp.push_back(i);
        getCombinations(res,n-i,k-1,i+1,temp);
        temp.pop_back();
        getCombinations(res,n,k,i+1,temp);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        getCombinations(res,n,k,1,temp);
        return res;
    }
};