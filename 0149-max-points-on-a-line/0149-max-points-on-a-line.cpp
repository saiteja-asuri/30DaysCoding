class Solution {
public:
     int maxPoints(vector<vector<int>>& points) {
        unordered_map<double,int> mp;
        int n=points.size();
        int mx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int y=points[j][1]-points[i][1];
                int x=points[j][0]-points[i][0];
                double k= (double)y/x;
                if(x==0)
                    k=abs(k);
                mp[k]++;
                mx=max(mx,mp[k]);
            }
            mp.clear();
        }
         return mx+1;
     }
};
