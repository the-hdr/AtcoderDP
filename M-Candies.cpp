#include <bits/stdc++.h>

#define int long long
#define float long double
#define INF LLONG_MAX
#define NEG_INF LLONG_MIN

#define whatis(x) (#x) << " = " << (x)
//#define cerr if(false)cerr

using namespace std;

const int p = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;
    
    vector<int> v (n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i];
    }
    
    int f[n + 1][k + 1];
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            f[i][j] = 0;
        }
    }
    
    for (int i = 0; i <= n; ++i)
    {
        f[i][0] = 1;
    }
    for (int j = 1; j <= k; ++j)
    {
        f[0][j] = 0;
    }
    
    for (int i = 1; i <= n; ++i)
    {
        vector<int> g (k + 1, 0);
        g[0] = f[i - 1][0];
        for (int j = 1; j <= k; ++j)
        {
            g[j] = (g[j - 1] + f[i - 1][j])%p;
        }
        for (int j = 0; j <= k; ++j)
        {
            if (j <= v[i])
            {
                f[i][j] =  g[j];
            }
            else
            {
                int extraCandies = j - v[i] - 1;
                f[i][j] = (g[j] - g[extraCandies] + p)%p;
            }
        }
    }
    cout << f[n][k] << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    //cin >> t;
    
    while (t--) solve();
    
    return 0;
}