
#include <bits/stdc++.h>
using namespace std;

int main()
{


    int r, c;
    cin >> r >> c;
    vector<vector<char>> v(r, vector<char>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> v[i][j];
        }
    }
    int answer = 0, totCoins = 0;
    for  (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (v[i][j] == 'C')
                totCoins++;
        }
    }

    for (int i = 0; i < c; i++) {
        int p = r;
        for (int j = 0; j < r; j++) {
            if (v[j][i] == 'C') {
                p = r - j - 1;
                break;
            }
            else if (v[j][i] == 'H') {
                if (p) continue;
                else p = r - j;
            }
            else p = 0;
        }
        answer += p;
    }
    cout << totCoins << " " << answer * 2;
    return 0;
}