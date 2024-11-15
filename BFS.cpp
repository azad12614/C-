#include <bits/stdc++.h>
using namespace std;
int n, e, p;
vector<vector<int>> adj;
vector<int> level, par;
/**
8 8
1 2
1 5
2 4
2 3
5 6
5 7
6 7
7 8
1
8
**/
void bfs(int s)
{
    level = vector<int>(n + 1, -1);
    par = vector<int>(n + 1, -1);
    queue<int> q;
    par[s] = -1;
    q.push(s);
    level[s] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(level[v] == -1) {
                level[v] = level[u] + 1;
                q.push(v);
                par[v] = u;
            }
        }
    }

    cin >> p;
    vector<int> path;
    path.push_back(p);
    while(p != s) {
        p = par[p];
        path.push_back(p);
    }

    for(auto i: path) cout << i << " ";
    cout << endl;


}

int main()
{
    cin>>n>>e;
    adj.resize(n + 1);
    for(int i=0; i<e; i++)
    {
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int s;
    cin >> s;
    bfs(s);

    for(int i = 0; i < n; i++) {
        cout << i + 1 << " : " << level[i + 1] << endl;
    }

    return 0;
}
