#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 400;
int prefix[N];

int sumBetween (int start, int end)
{
    if (end == 0)
    {
        return prefix[0];
    }
    
    return prefix[end] - prefix[start - 1];
}

int solve (int start, int end, int v[], vector<vector<int>>& dp)
{
    if (start >= end)
    {
        return 0;
    }
    
    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }
    
    int r = LLONG_MAX;
    for (int i = start; i <= end - 1; ++i)
    {
        r = min (r, sumBetween(start, i) + sumBetween(i + 1, end) + solve (start, i, v, dp) + solve (i + 1, end, v, dp));
    }
    return dp[start][end] = r;
}

int32_t main()
{
    int n;
    cin >> n;
    
    int v[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    
    vector<vector<int>> dp (n, vector<int> (n, -1));
    
    prefix[0] = v[0];
    for (int i = 1; i < n; ++i)
    {
        prefix[i] = prefix[i - 1] + v[i];
    }
    
    cout << solve (0, n - 1, v, dp);
    
    return 0;
}
