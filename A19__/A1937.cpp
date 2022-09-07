#include <iostream>
#include <algorithm>
using namespace std;

int K = 0, n = 0;
int Ne[502][502];
int memo[502][502];

// x,y에서 시작하면 최대한 살수있는 일
int solve(int x, int y)
{
    if (memo[x][y] != -1)
    {
        return memo[x][y];
    }
    int ans = 0;
    if (Ne[x - 1][y] > Ne[x][y])
    {
        ans = max(solve(x - 1, y), ans);
    }
    if (Ne[x + 1][y] > Ne[x][y])
    {
        ans = max(solve(x + 1, y), ans);
    }
    if (Ne[x][y + 1] > Ne[x][y])
    {
        ans = max(solve(x, y + 1), ans);
    }
    if (Ne[x][y - 1] > Ne[x][y])
    {
        ans = max(solve(x, y - 1), ans);
    }
    memo[x][y] = ans + 1;
    return ans + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            Ne[i][j] = 0;
            memo[i][j] = -1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> Ne[i][j];
        }
    }
    int a = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a = max(solve(i, j), a);
        }
    }
    cout << a;
}