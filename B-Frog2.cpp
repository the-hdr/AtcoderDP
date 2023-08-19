// This problem is the same as Frogs 1. Only this time, the number of allowed jumps are k;

#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

void solve()
{
    int numberOfStones, maximumNumberOfJumps;
    cin >> numberOfStones >> maximumNumberOfJumps;
    
    // in case maximumNumberOfJumps is 'too high':
    maximumNumberOfJumps = min (numberOfStones - 1, maximumNumberOfJumps);
    
    vector<int> heightsOfStones (numberOfStones);
    for (auto &currentHeight : heightsOfStones)
    {
        cin >> currentHeight;
    }
    
    vector<int> costOfReaching (numberOfStones + 1, INF);
    
    /**************************************************************************************************************************************
     * The state-transition function is:                                                                                                  *
     * f(n) = min {f(n - 1) + |h(n-1) - h(n)|, f(n - 2) + |h(n-1) - h(n)|, f(n - 3) + |h(n-1) - h(n)|, ... , f(n - k) |h(n-1) - h(n)|}.   *
     * Here,                                                                                                                              *
     * n = number of stone that the frog is at currently,                                                                                 *
     * h(n) = height of the current stone,                                                                                                *
     * f(n) = optimum number cost of reaching nth stone,                                                                                  *
     *                                                                                                                                    *
     * TIME-COMPLEXITY:                                                                                                                   *
     * O(k*k + n*k) = O(n*k)                                                                                                              *
     *                                                                                                                                    *
     * SPACE-COMPLEXITY:                                                                                                                  *
     * O(n)                                                                                                                               *
     **************************************************************************************************************************************/
     
    
    // base cases:
    costOfReaching[1] = 0;
    costOfReaching[2] = abs (heightsOfStones[1] - heightsOfStones[0]);
    for (int i = 3; i <= maximumNumberOfJumps; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            costOfReaching[i] = min (costOfReaching[i - j] + abs (heightsOfStones[i - j  - 1] - heightsOfStones[i - 1]),
                                     costOfReaching[i]);
        }
    }
    
    // developing the solution in a bottom-up manner:
    for (int i = maximumNumberOfJumps + 1; i <= numberOfStones; ++i)
    {
        for (int j = 1; j <= maximumNumberOfJumps; ++j)
        {
            costOfReaching[i] = min (costOfReaching[i - j] + abs (heightsOfStones[i - j  - 1] - heightsOfStones[i - 1]),
                                     costOfReaching[i]);
        }
    }
    
    int targetStone = numberOfStones;
    
    cout << costOfReaching[targetStone];
}

int main()
{
    int t = 1;
    // cin >> t;
    
    while (t--)
    {
        solve();
    }
    return 0;
}
