//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool DFS(vector<int> adj[],vector<bool> &visited,int s,int par,unordered_set<int> &ust)
    {
        visited[s]=true;
        ust.insert(s);
        for(int x : adj[s])
        {
            if(visited[x]==false)
            {
                if(DFS(adj,visited,x,par,ust)==true)
                return true;
            }
            else
            {
                if(ust.count(x)==1)
                    return true;
            }
        }
        ust.erase(s);
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++)
        {
            unordered_set<int> ust;
            if(visited[i]==false)
            {
            if(DFS(adj,visited,i,-1,ust)==true)
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends