#include<bits/stdc++.h>
using namespace std;

int main()
{
int v,e;
cin>>v>>e;
vector<pair<int,int>> adj[v];
int x,y,wt;

for(int i =0;i<e;++i){
cin>>x>>y>>wt;

adj[x].push_back({y,wt});
adj[y].push_back({x,wt});
}

vector<int> key(v,INT_MAX);
vector<bool> mst(v,false);
vector<int> parent(v,-1);
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
key[0]=0;
pq.push({0,0});
while(!pq.empty())
{
    int curVertex=pq.top().second;

    pq.pop();


    if(mst[curVertex]==true)
    continue;
      
    mst[curVertex]=true;

    for(auto itr=adj[curVertex].begin();itr!=adj[curVertex].end();++itr)
    {
        int nextVertex=(*itr).first;
        int weight=(*itr).second;

        if(mst[nextVertex]==false && key[nextVertex]>weight)
        {
            key[nextVertex]=weight;
            parent[nextVertex]=curVertex;
            pq.push({key[nextVertex],nextVertex});
        }
    }


}
for(int i=0;i<v;++i)
{
    cout<<parent[i]<<" ";
}
return 0;

}