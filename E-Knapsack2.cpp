#include <bits/stdc++.h>
 
#define int long long
#define float long double
#define INF LLONG_MAX
#define NEG_INF LLONG_MIN
 
#define whatis(x) (#x) << " = " << (x)
//#define cerr if(false)cerr
 
using namespace std;
 
void solve()
{
    int n, totalWeight;
    cin >> n >> totalWeight;
    
    vector<int> values (n + 1), weights (n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> weights[i] >> values[i];
    }
    
    const int MAXVALUE = 1e5;
    vector<vector<int>> f (n + 1, vector<int> (MAXVALUE + 1, 0));
    
    const int INFINITY_ = 1e17;
    for (int v = 1; v <= MAXVALUE; ++v)
    {
        f[0][v] = INFINITY_;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int v = 1; v <= MAXVALUE; ++v)
        {
            if (v >= values[i])
            f[i][v] = min (weights[i] + f[i - 1][v - values[i]], f[i - 1][v]);
            else
            f[i][v] = f[i - 1][v];
        }
    }
    for (int v = MAXVALUE; v >= 0; --v)
    {
        if (f[n][v] <= totalWeight)
        {
            cout << v << endl;
            return;
        }
    }
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