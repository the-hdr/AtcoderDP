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
    int n;
    cin >> n;
    
    vector<int> v (n, 0);
    int s = 0;
    for (auto &x : v)
    {
        cin >> x;
        s += x;
    }
    
    int f[n][n][2];
    
    for (int i = 0; i <= n - 1; ++i)
    {
        f[i][i][0] = v[i];
        
        f[i][i][1] = 0;
    }
    
    for (int JminusI = 1; JminusI <= n - 1; ++JminusI)
    {
        for (int I = 0; I + JminusI <= n - 1; ++I)
        {
            int J = JminusI + I;
            
            f[I][J][0] = max (v[I] + f[I + 1][J][1], v[J] + f[I][J - 1][1]);
            f[I][J][1] = min (f[I + 1][J][0], f[I][J - 1][0]);
        }
    }
    cout << 2*f[0][n - 1][0] - s << endl;
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