#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 3;
    int num = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            if (a == 0)
                a = 9;
            num = num * 10 + a;
        }
    }

    map<int, int> d;

    d[num] = 0;

    queue<int> q;
    q.push(num);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        string now_str = to_string(now);
        int blank_idx = now_str.find('9');
        int x = blank_idx / 3;
        int y = blank_idx % 3;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3)
            {
                string next_str = now_str;
                swap(next_str[x * 3 + y], next_str[nx * 3 + ny]);
                int next = stoi(next_str);

                if (d.count(next) == 0) // next_now 문자열을 한번도 만든 적이 없다면,
                {
                    d[next] = d[now] + 1;
                    q.push(next);
                }
            }
        }
    }

    if (d.count(123456789) == 0)
        cout << -1 << '\n';
    else
        cout << d[123456789] << '\n';

    return 0;
}