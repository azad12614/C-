#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vvl vector<vector<ll>>

void topsort(ll source, vl &vis, stack<ll> &st, vector<pair<ll,ll>> adj[])
{
    vis[source]=1;
    for(auto x: adj[source])
    {
        if(!vis[x.first])
        {
            topsort(x.first,vis,st,adj);
        }
    }
    st.push(source);
}

void shortestpath(ll src, ll n, vector<pair<ll,ll>> adj[])
{
    vl vis(n,0);
    stack<ll> st;
    for(ll i=0; i<n; i++)
        if(!vis[i])
            topsort(i,vis,st,adj);
    vl dist(n,1e9);
    dist[src]=0;
    while(!st.empty())
    {
        ll node = st.top();
        st.pop();
        if(dist[node]!=1e9)
        {
            for(auto &it:adj[node])
            {
                if(dist[node]+it.second < dist[it.first])
                {
                    dist[it.first]=dist[node]+it.second;
                }
            }
        }
    }
    for(ll i=0; i<n; i++)
        dist[i]==1e9 ? cout << "INF":cout << dist[i] << " ";
}

int main()
{
    ll n,e;
    cin >> n >> e;
    vector<pair<ll,ll>> adj[n];
    for(ll i=0; i<e; i++)
    {
        ll x,y,w;
        cin >> x >> y >> w;
        adj[x].push_back({y,w});
    }
    shortestpath(0,n,adj);
}
/*
6 7
0 1 2
0 4 1
1 2 3
2 3 6
4 2 2
4 5 4
5 3 1
*/
