#include <bits/stdc++.h>
 
const int p = 1e9 + 7;
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    
    vector<double> p (n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i];
    }
    
    vector<vector<double>> f (n + 1, vector<double> (n + 1, 0));
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (j == 0)
            {
                f[i][0] = f[i - 1][0]*(1 - p[i]);
            }
            else
            {
                f[i][j] = f[i - 1][j]*(1 - p[i]) + f[i - 1][j - 1]*p[i];
            }
        }
    }
    
    double result = 0;
    for (int i = n/2 + 1; i <= n; ++i)
    {
        result += f[n][i];
    }
    cout << setprecision (10) << fixed << result << endl;
    
    return 0;
}