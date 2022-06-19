#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef pair<int , int> pii;

// 행 : 세로
// 열 : 가로

int boardHang , boardYul , countOfColorPaper , mistakePointCount , maxHang = 0;
vector<int> mistakes;
bool inputed[1000005] = {0,};

bool able(int wd){
    int usedColorPaper = 0;
    int lastCover = -1;
    for(auto now : mistakes){
        if(usedColorPaper > countOfColorPaper) return false;
        if(now <= lastCover) continue;

        lastCover = now + wd - 1;
        usedColorPaper++;
    }

    if(usedColorPaper > countOfColorPaper) return false;

    return true;
}

int main(){
    cin.tie(0); cout.tie(0);
    cin >> boardHang >> boardYul >> countOfColorPaper >> mistakePointCount;
    for(int i = 0;i <mistakePointCount;i++){
        int hang , yul; // y , x
        cin >> hang >> yul;
        maxHang = max(maxHang , hang);
        if(!inputed[yul]){
            mistakes.push_back(yul);
            inputed[yul] = true;
        }
    }

    sort(mistakes.begin() , mistakes.end());

    int low = maxHang;
    int high = 1000000;
    int md;
    while(low <= high){
        int mid = (low +high) / 2;
        if(able(mid)){
            high = mid - 1;
            md=  mid;
        }else{
            low = mid + 1;
        }
    }
    cout << md;
}
