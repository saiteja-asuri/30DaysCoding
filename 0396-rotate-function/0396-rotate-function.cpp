class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        vector<int> remainingSum(n);
        int sum=0,currSum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            currSum+=(i*nums[i]);
        } 
        int mxsum=currSum;
        for(int i=n-1;i>0;i--)
        {
            int newSum=currSum-((n-1)*nums[i])+ sum-nums[i];
            
            mxsum=max(mxsum,newSum);
            currSum=newSum;
        }
        return mxsum;
    }
};