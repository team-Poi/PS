#include <iostream>
using namespace std;
using int64 = int64_t;
int64 X = 0;
int64 Y = 0;
int64 Z = 0;

bool test(int64 win) // win 몇판 더이겼는지
{
    int z = ((100 * (Y + win)) / (X + win));
    return Z < z;
}

int main()
{
    cin >> X;
    cin >> Y;
    Z = ((100 * Y) / X);
    if (99 <= Z)
    {
        cout << -1 << '\n';
        return 0;
    }

    int64 s = 0;
    int64 e = X + 1;
    int64 mid;
    int64 ret = -1;
    while (s < e)
    {
        mid = (s + e) / 2;
        if (test(mid))
        {
            ret = mid;
            e = mid;
        }
        else
        {
            s = mid + 1;
        }
    }

    cout << ret << '\n';
}
