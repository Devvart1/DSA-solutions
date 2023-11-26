#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u,v,wt;
    

node(int u,int v,int wt)
{
    this->u=u;
    this->v=v;
    this->wt=wt;
}
};
int findpar(int i,vector<int> parent) 
{
   
    if (parent[i] == i) 
    {
       
        return i;
    }
    else 
    {
       
        return findpar(parent[i],parent);
    }
}
void unionn(int u,int v,vector<int> &par,vector<int> &rank)
{
    u=findpar(u,par);
    v=findpar(v,par);
    if(rank[u]>rank[v])
    {
        par[v]=u;
    }
    else if(rank[v]>rank[u])
    {
        par[u]=v;
    }
    else
    {
        par[u]=v;
        rank[v]++;
    }
}
bool comp(node x,node y)
{
    return x.wt<y.wt;
}
int main()
{
int x,y;
cin>>x>>y;

    int u,v,wt;
    vector<node> edge;

    for(int i =0;i<y;++i)
    {
        cin>>u>>v>>wt;
        edge.push_back(node(u,v,wt));

    }

sort(edge.begin(),edge.end(),comp);
vector<int> par;
vector<int> rank(x,0);
vector<pair<int,int>> mst;
int cost=0;
for(int i=0;i<x;++i)
{par.push_back(i);


}
for(auto it:edge)
{
    if(findpar(it.u,par)!=findpar(it.v,par))
    {
cost+=it.wt;
mst.push_back({it.u,it.v});
unionn(it.u,it.v,par,rank);
    }
}
cout<<"cost of mast:"<<cost<<endl;

for(auto it:mst)
{cout<<it.first<<"-"<<it.second<<endl;

}
return 0;
}
