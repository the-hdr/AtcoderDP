#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v (n);
    for (auto &x : v)   cin >> x;

    vector<int> f (k + 1, 0);
    f[0] = 0;
    for (int x = 1; x <= k; ++x)
    {
        for (auto y : v)
        {
            if (x >= y)
            {
                f[x] |= (1 - f[x - y]);
            }
        }
    }
    cout << (f[k] ? "First" : "Second") << endl;
    return 0;
}