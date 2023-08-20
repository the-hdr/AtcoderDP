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
    
    vector<vector<int>> f (n + 1, vector<int> (totalWeight + 1, 0));
    for (int currentItem = 1; currentItem <= n; ++currentItem)
    {
        for (int currentWeight = 1; currentWeight <= totalWeight; ++currentWeight)
        {
            if (currentWeight >= weights[currentItem])
            f[currentItem][currentWeight] = max (values[currentItem] +
                                                 f[currentItem - 1][currentWeight - weights[currentItem]],
                                                 f[currentItem - 1][currentWeight]);
            else
            f[currentItem][currentWeight] = f[currentItem - 1][currentWeight];
        }
    }
    
    cout << f[n][totalWeight] << endl;
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