#include <iostream>
using namespace std;

int arr[2000001] = {
    0,
};
int main()
{
    int N = 0;   //학생의 수
    int C = 0;   //폭죽쇼가 끝나는 시간
    cin >> N;    //학생의 수 입력
    cin >> C;    //폭죽쇼가 끝나는 시간 입력
    int cnt = 0; // 폭죽이 터지는 시간의 수
    for (int i = 0; i < N; i++)
    {
        int num = 0;    //터지는 시간
        cin >> num;     //터지는 시간 입력
        int temp = num; //터지는시간 초기값
        if (!arr[num])  //터지는 시간이 있으면 패스
        {
            while (1) //무한반복
            {
                if (num > C) //폭죽쇼가 끝나는 시간이 되면 끝네기
                    break;   //멈추기
                else
                {
                    arr[num] = 1; //그 시간에 한다고 표기
                    num += temp;  //그 다음 시간으로 넘기기
                }
            }
        }
    }
    for (int i = 0; i < C; i++)
        if (arr[i + 1])
            cnt++; //그 시간에 하면 카운트

    cout << cnt; //카운트출력
}