#include<bits/stdc++.h>
using namespace std;
void makeset(int v,int parent[],int rank[])
{
    for(int i =0;i<v;++i)
    {
        parent[i]=i;
        rank[i]=0;
    }
}
int findpar(int i,int parent[]) 
{
    // If i is the parent of itself
    if (parent[i] == i) 
    {
        // Then i is the representative of 
        // this set
        return i;
    }
    else 
    {
       
        return findpar(parent[i],parent);
    }
}
void unionx(int u,int v,int parent[],int rank[])
{
    u=findpar(u,parent);
    v=findpar(v,parent);
    if(rank[u]<rank[v])
    parent[u]=v;
    else if(rank[v]<rank[u])
    parent[v]=u;
    else
    {parent[v]=u;  
    rank[u]++;
}
}

int main()
{int m;
    cin>>m;
int parent[m];
int rank[m];
makeset(m,parent,rank);
int u,v;


for(int i=0;i<m;++i)
{
cin>>u>>v;
unionx(u,v,parent,rank);
}
for(int i=0;i<m;++i)
{
cout<<parent[i]<<endl;
}

if(parent[3]!=parent[4])
cout<<"DIff parent";
else
cout<<"Same parent";

    return 0;

}