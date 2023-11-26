 #include<bits/stdc++.h>

 using namespace std;
 
 
 
 bool bipartite(int i,vector<int>& colour,vector<vector<int>>& adj,int cc)
    {
        colour[i]=cc;
        for(int x:adj[i])
        {
            if(colour[x]==cc)
                return false;
            if(colour[x]==-1)
                bipartite(x,colour,adj,1-colour[i]);
        }
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=dislikes.size();
        vector<vector<int>> adj(N+1);
        for(int i=0;i<n;i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int> colour(N+1,-1);
        for(int i=1;i<=N;i++)
        {
            if(colour[i]==-1)
            {
                if(!bipartite(i,colour,adj,1))
                    return false;
            }
        }
        return true;
    }
