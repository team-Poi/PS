#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <cassert>
#include <stack>
#include <cstring>
using namespace std;
#define interface struct
#define zx3f 1061109567
#define itn int
typedef long long ll;
typedef unsigned long ull;
typedef pair<int, int> pii;
typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main()
{
    cin.tie(0);
    cout.tie(0);
    double a, b, c;
    cin >> a >> b >> c;
    a *= 10;
    b *= 10;
    c *= 10;
    printf("%.2f", b * a + b * c + a * c);
}