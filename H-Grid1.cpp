#include <bits/stdc++.h>
 
const int p = 1e9 + 7;
 
using namespace std;
 
int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> grid (n, vector<char> (m, 0));
    for (auto &row : grid)
    {
        for (auto &character : row)
        {
            cin >> character;
        }
    }
    
    vector<vector<int>> numberOfWays (n, vector<int> (m, 0));
    
    // base cases:
    numberOfWays[0][0] = grid[0][0] == '#' ? 0 : 1;
    for (int i = 1; i < n; ++i)
    {
        numberOfWays[i][0] = grid[i][0] == '#' ? 0 : numberOfWays[i - 1][0];
    }
    for (int j = 1; j < m; ++j)
    {
        numberOfWays[0][j] = grid[0][j] == '#' ? 0 : numberOfWays[0][j - 1];
    }
    
    // state-transition:
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            numberOfWays[i][j] = grid[i][j] == '#' ? 0 : (numberOfWays[i][j - 1] + numberOfWays[i - 1][j])%p;
        }
    }
    
    // final subproblem:
    cout << numberOfWays[n - 1][m - 1] << endl;
    
    return 0;
}