#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    string s, t;
    cin >> s >> t;
    
    int n = s.size(), m = t.size();
    vector<vector<int>> f (n + 1, vector<int> (m + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            f[i][j] = (s[i - 1] == t[j - 1] ? 1 + f[i - 1][j - 1] :
                       max (f[i - 1][j], f[i][j - 1]));
        }
    }
    
    string r = "";
    int i = n, j = m;
    
    while (i > 0 and j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            r.push_back (s[i - 1]);
            --i, --j;
        }
        else
        {
            if (f[i - 1][j] > f[i][j - 1])
            {
                --i;
            }
            else
            {
                --j;
            }
        }
    }
    
    reverse (r.begin(), r.end());
    cout << r << endl;
    
    return 0;
}