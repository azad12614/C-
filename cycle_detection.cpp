#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vvl vector<vector<ll>>

/*
// Cycle Detection in Undirected Graph using DFS
bool dfs(ll son, ll father, vvl &v, vl &par, vl &vis)
{
    vis[son]=1;
    par[son]=father;
    for(auto &x: v[son])
    {
        if(vis[x]==-1)
            dfs(x,son,v,par,vis);
        else if(x!=par[son])
            return true;
    }
    return false;
}
int main()
{
    ll n,e;
    cin >> n >> e;
    vvl v(n+1);
    vl vis(n+1,-1);
    vl par(n+1);
    for(ll i=0; i<e; i++)
    {
        ll x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(ll i=1; i<=n; i++)
    {
        bool check = false;
        if(vis[i]==-1)
        {
            check = dfs(i,-1,v,par,vis);
            if(check)
            {
                cout << "Has cycle\n";
                return 0;
            }
        }
    }
    cout << "No cycle\n";
}
*/
// Cycle Detection in Directed Graph using DFS
bool dfs(ll node, vvl adj, vl &vis, vl &dfsvis)
{
    vis[node]=1;
    dfsvis[node]=1;
    for(auto &x:adj[node])
    {
        if(!vis[x])
        {
            if(dfs(x, adj, vis, dfsvis))
                return true;
        }
        else if(dfsvis[x])
            return true;
    }
    dfsvis[node]=0;
    return false;
}
int main()
{
    ll n,e;
    cin >> n >> e;
    vvl adj(n+1);
    vl vis(n+1,0);
    vl dfsvis(n+1,0);
    for(ll i=0; i<e; i++)
    {
        ll x,y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for(ll i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            if(dfs(i,adj,vis,dfsvis))
            {
                cout << "Has cycle\n";
                return 0;
            }
        }
    }
    cout << "No cycle\n";
    for(ll i=1; i<=n; i++)
    {
        cout << vis[i] << " " << dfsvis[i] << endl;
    }
}
