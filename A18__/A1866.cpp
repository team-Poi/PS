#include <iostream>
#include <algorithm>

using namespace std;

int a = 3005, e, f, g;

int main()
{
    int b[a], c[a], d[a];
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> e;
    for (int i = 1; i <= e; i++)
    {
        cin >> c[i];
    }

    sort(c + 1, c + e + 1);

    for (int i = 1; i <= e; i++)
    {
        d[i] = d[i - 1] + c[i];
    }

    cin >> f >> g;
    for (int i = 1; i <= e; i++)
    {
        b[i] = b[i - 1] + f * c[i];

        for (int j = i; j >= 1; j--)
        {
            int t = (i + j) / 2; // i ~ j 까지 heli + truck

            int y = (c[t] * (t - j + 1) - (d[t] - d[j - 1])) * f;
            int u = ((d[i] - d[t - 1]) - (c[t] * (i - t + 1))) * f;

            b[i] = min(b[i], b[j - 1] + y + u + g);
        }
    }

    cout << b[e];
}
