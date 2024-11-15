#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vvl vector<vector<ll>>


void dfs(int source, vvl &v, vl &vis, vl &sequence)
{
    vis[source]=1;
    //cout << source << ' ';// do not need in top-sort/Topological sort
    for(auto &x: v[source]){
        if(vis[x]==-1){
            //cout << "-->";// do not need in top-sort/Topological sort
            dfs(x,v,vis,sequence);
        }
    }//completely visited
    sequence.push_back(source);//need in top-sort/Topological sort
}
int main(){
    int n,e;
    cin >> n >> e;
    vvl v(n+1);
    vl vis(n+1,-1);
    vl sequence;
    for(int i=0; i<e; i++){
        ll x,y;
        cin >> x >> y;
        v[x].push_back(y);
        //v[y].push_back(x);// do not need in top-sort/Topological sort
    }
    for(int i=1; i<=n; i++){
        if(vis[i]==-1){
            dfs(i,v,vis,sequence);
        }
    }
    // DFS END
    reverse(sequence.begin(),sequence.end());
    for(auto &x:sequence)
        cout << x << ' ';
}
