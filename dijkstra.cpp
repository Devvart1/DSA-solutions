#include<bits/stdc++.h>
using namespace std;
void dijstra(vector<pair<int,int>> adj[],int n,int src)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    vector<int> dist(n,INT_MAX);
  

 dist[src]=0;

    pq.push({0,src});

    while(!pq.empty())
    {
        int curDist=pq.top().first;
int curVertex=pq.top().second;
pq.pop();
vector<pair<int,int>> ::iterator it;

for(it=adj[curVertex].begin();it!=adj[curVertex].end();it++)
{
int nextVertex=it->first;
int weight=it->second;
int possibleDistance=curDist +weight;

  if(possibleDistance<dist[nextVertex])
  {dist[nextVertex]=possibleDistance;
  pq.push({possibleDistance,nextVertex});
  }
}

    }


for(int i =0;i<n;i++)
cout<<dist[i]<<" ";
}



int main()
{
int n,m;
cin>>n>>m;
vector<pair<int,int>> adj[n];
int u,v,wt;

for(int i =0;i<m;++i)
{
    cin>>u>>v>>wt;
    adj[u].push_back({v,wt});
     adj[v].push_back({u,wt});
    

}
 dijstra(adj,n,0);
return 0;
}

