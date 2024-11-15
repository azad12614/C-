#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vvl vector<vector<ll>>
#define vl vector<ll>

ll n,e;
vvl adj;
vl tops;

void top(ll n, vvl adj)
{
    queue<ll> q;
    vl indegree(n,0);
    for(ll i=0; i<n; i++)
    {
        for(auto &it:adj[i])
        {
            indegree[it]++;
        }
    }
    for(ll i=0; i<n; i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        ll node =q.front();
        q.pop();
        tops.push_back(node);
        for(auto &it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            {
                q.push(it);
            }
        }
    }
}

int main()
{
    cin >> n >> e;
    adj.resize(n+1);
    for(ll i=0; i<e; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        //adj[y].push_back(x);
    }
    top(n,adj);
    for(ll i=0; i<n; i++)
        cout << tops[i]+1 << ' ';
    cout << endl;
}
