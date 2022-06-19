
#include<bits/stdc++.h>
#define ll long long int
#define input(type, a) type a; cin>>a
#define v(type) vector<type>
#define PB push_back
#define PF push_front
#define emp emplace
#define m_p make_pair
#define deq(type) deque<type>
#define tests ll t; cin >> t; while(t--)
#define FOR(type,a,b) for(type i = a;i<b;i++)
using namespace std;


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    v(v(ll)) adj(1e5+2);

    input(int,n); input(int, m);
// n = no of nodes     m = no of edges
    FOR(int, 0, m){
        input(int,x); input(int,y);
        adj[x].PB(y);
        adj[y].PB(x);
    }
    FOR(ll, 1, n+1){
        cout<<i<<" -> ";
        for(auto x:adj[i]){
            cout<<x<<" ";
        }cout<<endl;
    }

    return 0;
}