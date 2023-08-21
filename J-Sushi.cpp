#include <bits/stdc++.h>
 
#define int long long
#define float long double
#define INF LLONG_MAX
#define NEG_INF LLONG_MIN
 
#define whatis(x) (#x) << " = " << (x)
//#define cerr if(false)cerr
 
using namespace std;
 
double f[300 + 5][300 + 5][300 + 5];
 
void solve()
{
    int n;
    cin >> n;
    
    vector<int> a (n + 1, 0);
    int ones = 0, twos = 0, threes = 0;
    for (auto &x : a)
    {
        cin >> x;
        
        ones += x == 1;
        twos += x == 2;
        threes += x == 3;
    }
    
    for (int i = 0; i <= 300; ++i)
    {
        for (int j = 0; j <= 300; ++j)
        {
            for (int k = 0; k <= 300; ++k)
            {
                f[i][j][k] = 0;
            }
        }
    }
    
    f[0][0][0] = 0;
 
    for (int k = 0; k <= n; ++k)
    {
        for (int j = 0; j <= n; ++j)
        {
            for (int i = 0; i <= n; ++i)
            {
                if (i + j + k == 0) continue;
                
                if (i + j + k > n)  continue;
                
                double result = (1.00*n) / (i + j + k);
                
                if (i > 0)  result += (1.00*i/(i + j + k))*f[i - 1][j][k];
                if (j > 0)  result += (1.00*j/(i + j + k))*f[i + 1][j - 1][k];
                if (k > 0)  result += (1.00*k/(i + j + k))*f[i][j + 1][k - 1];
                
                f[i][j][k] = result;
            }
        }
    }
    
    cout << setprecision(10) << fixed << f[ones][twos][threes] << endl;
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