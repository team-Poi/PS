#include <iostream>
using namespace std;

int main()
{
    int N = 0;
    cin >> N;
    int howmanyfisrtname[26] = {
        0,
    };

    for (int i = 0; i < N; i++)
    {
        string name;
        cin >> name;
        howmanyfisrtname[((int)name[0]) - 97]++;
    }

    bool cango = false;
    for (int i = 0; i < 26; i++)
    {
        if (howmanyfisrtname[i] >= 5)
        {
            cout << ((char)(i + 97));
            cango = true;
        }
    }

    if (cango == false)
        cout << "PREDAJA";
}