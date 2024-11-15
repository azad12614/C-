// Dijkstra's Algorithm | Shortest Path in Undirected weighted Graphs
// T.C. = O((N+E)log N)
// S.C. = 2*O(N)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

int main()
{
    ll n,e;
    cin >> n >> e;
    vector<pair<ll,ll>> adj[n+1];
    for(ll i=0; i<e; i++)
    {
        ll x,y,w;
        cin >> x >> y >> w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    ll source;
    cin >> source;

    // Dijkstra's Algorithm start
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    vl dist_arr(n+1,LONG_MAX);

    dist_arr[source] = 0;
    pq.push({0,source});

    while(!pq.empty())
    {
        ll dist = pq.top().first;
        ll prev = pq.top().second;
        pq.pop();

        for(auto &x:adj[prev])
        {
            ll next = x.first;
            ll nextdist = x.second;
            if(dist_arr[next]>dist_arr[prev]+nextdist)
            {
                dist_arr[next]=dist_arr[prev]+nextdist;
                pq.push({dist_arr[next],next});
            }
        }
    }
    cout << "the distances from source, " << source << ", are : \n";
    for(ll i=1; i<=n; i++)
        cout << dist_arr[i] << ' ';
    cout << "\n";

    return 0;
}
/*
5 6
1 2 2
1 4 1
2 5 5
2 3 4
4 3 3
3 5 1
1
*/
