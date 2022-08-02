#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

void solve()
{
    int numberOfStones;
    cin >> numberOfStones;
    
    vector<int> heightsOfStones (numberOfStones);
    for (auto &currentHeight : heightsOfStones)
    {
        cin >> currentHeight;
    }
    
    vector<int> costOfReaching (numberOfStones + 1, INF);
    
    /*****************************************************************************
    * The state-transition equation here is:                                     *
    * f(n) = min (f(n - 1) + |h(n-1) - h(n)|, f(n - 2) + |h(n - 2) + h(n)|).     *
    * Here,                                                                      *
    * n = number of stone the frog is at currently,                              *
    * f(n) = function giving the optimum cost of reaching the nth stone,         *
    * h(n) = height of the nth stone.                                            *'
    * The base cases are:                                                        *
    * f(1) = 0                                                                   *
    * f(2) = |h(2) - h(1)|                                                       *
    *****************************************************************************/
  
    costOfReaching[1] = 0;
    costOfReaching[2] = abs (heightsOfStones[1] - heightsOfStones[0]);
  
    for (int currentStone = 3; currentStone <= numberOfStones; ++currentStone)
    {
        costOfReaching[currentStone] = min (costOfReaching[currentStone - 1] + abs (heightsOfStones[currentStone - 2] - heightsOfStones[currentStone - 1]),
                                            costOfReaching[currentStone - 2] + abs (heightsOfStones[currentStone - 3] - heightsOfStones[currentStone - 1]));
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
