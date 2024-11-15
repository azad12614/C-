#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vvl vector<vector<ll>>


bool dfs(ll son, ll father, vvl &v, vl &par, vl &color, ll &cnt)
{
    if(color[son]==1)
    {
        cnt++;
        return 0;
    }
    else if(color[son]==2)
    {
        return 0;
    }
    color[son]=1;
    par[son]=father;
    for(auto &x: v[son])
    {
        if(x!=par[son])
            dfs(x,son,v,par,color,cnt);
    }
    color[son]=2;
}
int main()
{
    ll n,e,cnt=0;
    cin >> n >> e;
    vvl v(n+1);
    vl color(n+1,-1);
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
        if(color[i]==-1)
            dfs(i,-1,v,par,color,cnt);
    }
    cout << cnt << "\n";
}
