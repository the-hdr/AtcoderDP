#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> a (n + 1), b (n + 1), c (n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    
    /*************************************************************************************************
     *                                                                                               *
     * DEFINITION OF THE STATE PARAMETERS AND STATE:                                                 *
     * n = day number;                                                                               *
     * i = activity number;                                                                          *
     * f(n, i) = maximum amount of happiness after n days given that on the nth day,                 *
     *           ith activity was chosen;                                                            *
     *                                                                                               *
     * STATE-TRANSITION EQUATION:                                                                    *
     * f(n, 1) = a[i] + max {f(i - 1, 2), f(i - 1, 3)};                                              *
     * f(n, 2) = b[i] + max {f(i - 1, 1), f(i - 1, 3)};                                              *
     * f(n, 3) = c[i] + max {f(i - 1, 1), f(i - 1, 2)};                                              *
     *                                                                                               *
     * BASE-CASES:                                                                                   *
     * f(1, 1) = a[1];                                                                               *
     * f(1, 2) = b[1];                                                                               *
     * f(1, 3) = c[1];                                                                               *
     *                                                                                               *
     * FINAL SUBPROBLEM:                                                                             *
     * max {f(n, 1), f(n, 2), f(n, 3)};                                                              *
     *                                                                                               *
     * TIME-COMPLEXITY:                                                                              *
     * O(n)                                                                                          *
     *                                                                                               *
     * SPACE-COMPLEXITY:                                                                             *
     * O(n)                                                                                          *
     *                                                                                               *
     *************************************************************************************************/
    
    vector<vector<int>> f (n + 1, vector<int> (3 + 1));
    
    // base cases:
    f[1][1] = a[1];
    f[1][2] = b[1];
    f[1][3] = c[1];
    
    // state-transition:
    for (int day = 2; day <= n; ++day)
    {
        f[day][1] = a[day] + max (f[day - 1][2], f[day - 1][3]);
        f[day][2] = b[day] + max (f[day - 1][1], f[day - 1][3]);
        f[day][3] = c[day] + max (f[day - 1][1], f[day - 1][2]);
    }
    
    // final subproblem:
    cout << max ({f[n][1], f[n][2], f[n][3]}) << endl;
    
    return 0;
}
