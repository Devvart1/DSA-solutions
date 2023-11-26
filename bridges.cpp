#include<bits/stdc++.h>
using namespace std;
void dfs(int node,int parent,vector<int> &vis,vector<int> &tin,vector<int> &low,int &timer,vector<int> adj[])
{
    vis[node]=1;
tin[node]=low[node]=timer++;
for(auto it:adj[node])
{
    if(it==parent)continue;

    if(!vis[it])
    {
       dfs(it,node,vis,tin,low,timer,adj); 
       low[it]=min(low[node],low[it]);
       if(low[it]>tin[node])
       {
        cout<<node<<" "<<it<<endl;
       }
       else{
        low[node]=min(low[node],tin[it]);
       }
    }
    
}
}
int main()
{

    int v,m;
    cin>>v>>m;
    vector<int> edge[v];
    int x,y;
    for(int i =0;i<m;++i)
    {
       cin>>x>>y;
       edge[x].push_back(y);
       edge[y].push_back(x);

    }
vector<int> vis(v,0);
vector<int> tin(v,-1);
vector<int> low(v,-1);
int timer=0;
for(int i =0;i<v;++i)
{
    if(!vis[i]==0)
    {
        dfs(i,-1,vis,tin,low,timer,edge);
    }
}

   
    return 0;
}