#include <bits/stdc++.h>
 
const int INF = 1e9;
 
using namespace std;
 
vector<int> f (1e5 + 1, INF);
vector<bool> isVisited (1e5 + 1, false);
 
void dfs (int cn, vector<vector<int>>& g)
{
    f[cn] = 0;
    isVisited[cn] = true;
    
    for (auto c : g[cn])
    {
        if (not isVisited[c])
        {
            dfs (c, g);
        }
        f[cn] = max (f[cn], 1 + f[c]);
    }
}
 
int main()
{
    int n, e;
    cin >> n >> e;
    
    vector<vector<int>> graph (n + 1, vector<int> (0));
    
    for (int i = 0; i < e; ++i)
    {
        int x, y;
        cin >> x >> y;
        
        graph[x].push_back (y);
    }
    
    for (int x = 1; x <= n; ++x)
    {
        dfs (x, graph);
    }
    
    int r = 0;
    for (int x = 1; x <= n; ++x)
    {
        r = max (r, f[x]);
    }
    cout << r << endl;
    
    return 0;
}