#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <numbers>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int , pair<int , bool>> pii;
typedef vector<int> vi;

#define s second;
#define l first

int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};

vi path[10005];
int n;
int uping[10005];

int main(){
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0;i < n - 1;i++) {
        int par , chi;
        cin >> par >> chi;
        path[chi].push_back(par);
        uping[i] = -1;
    }
    uping[n - 1] = -1;
    uping[n] = -1;

    int st , ed;
    cin >> st >> ed;
    queue<pii> q;

    q.push({st , {0 , 0}});
    q.push({ed , {0 , 1}});

    while(!q.empty()) {
        pii now = q.front();
        q.pop();

        if(uping[now.first] != -1) {
            cout << now.l;
            return 0;
        }

        uping[now.l] = now.second.second;
        // printf("uping[%d] = %d\n", now.l , now.second.second);
        for(auto x : path[now.l]) {
            q.push({x , { now.second.first + 1, now.second.second }});
        }
    }
}