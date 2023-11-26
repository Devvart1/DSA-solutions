#include <bits/stdc++.h>
using namespace std;
vector<int> DVR(int n, int src, vector<vector<int>> &edges)
{
    vector<int> distance(n + 1, INT_MAX);
    distance[src] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (distance[u] != INT_MAX && (distance[u] + w < distance[v]))
                distance[v] = distance[u] + w;
        }
    }
   
    
    return distance;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
  
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
          
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
        edges.push_back({y, x, w});
        
    }
    for (int src = 1; src <= n; src++)
    {
        vector<int> ans = DVR(n, src, edges);
        cout << "\nmini. distance via DVR for router N" << src << " is :\n";
        for (int i = 1; i <= n; i++)
        {
            cout << "router N" << i << " has mini. distance of " << ans[i] << " from the router N" << src << endl;
        }
    }
    return 0;
}
