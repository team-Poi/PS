#include <iostream>

using namespace std;

struct Struc
{
    char name[100];
    char memo[100];
};

int main()
{
    Struc child[60];

    int groupnum = 1;
    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            cin >> child[i].name;
            for (int j = 0; j < n - 1; j++)
                cin >> child[i].memo[j];
        }

        cout << "Group " << groupnum++ << "\n";
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (child[i].memo[j] == 'N')
                {
                    int index = n + i - 1 - j;
                    index = index % n;
                    cout << child[index].name << " was nasty about " << child[i].name << "\n";
                    flag = 1;
                }
            }
        }
        if (flag == 0)
        {
            cout << "Nobody was nasty"
                 << "\n";
        }
        cout << "\n";
    }
    return 0;
}