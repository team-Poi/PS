#include <bits/stdc++.h>
using namespace std;
int main()
{
    string c;
    cin >> c;
    int max = 0;
    int cnt = 0;
    int target = 0;
    int a[26] = {
        0,
    };
    transform(c.begin(), c.end(), c.begin(), (int (*)(int))toupper); // 전부 대문자로 바꾸는 코드
    for (int i = 0; i < c.length(); i++)
    {
        a[c[i] - 'A']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (max < a[i])
        {
            max = a[i];
            cnt = 0;
            target = i;
        }
        if (max == a[i])
        {
            cnt++;
        }
    }
    if (cnt > 1)
    {
        cout << "?";
    }
    else
    {
        cout << (char)(target + 'A');
    }
    return 0;
}
