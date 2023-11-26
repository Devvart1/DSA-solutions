#include<bits/stdc++.h>
using namespace std;
unordered_map<char, unordered_set<string>> arr;
unordered_map<char, unordered_set<char>> first;

void findfirst(char symbol)
{

    for (auto str : arr[symbol]) {
        if (str[0] == symbol) {
            continue;
        }

        if (str[0] >= 'a' && str[0] <= 'z') {
            first[symbol].insert(str[0]);
        }
        else
        {
            findfirst(str[0]);
            for (char c : first[str[0]]) {
                first[symbol].insert(c);
            }
        }
    }
}

int main()
{


#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    arr['S'] = {"ACB", "CbB", "Ba"};
    arr['A'] = {"da", "BC"};
    arr['B'] = {"g", ""};
    arr['C'] = {"h", ""};
    for (auto [x, y] : arr) {
        for (auto str : y) {
            if (str == "") {
                first['\0'].insert('\0');
            }
            for (auto ch : str) {
                if (ch >= 'a' && ch <= 'z') {
                    first[ch].insert(ch);
                }
            }
        }
    }

    for (auto p : arr) {
        findfirst(p.first);
    }

    for (auto f : first) {
        if (f.first == '\0') {
            cout << "FIRST(" << "eps" << ") >  ";
        }
        else {
            cout << "FIRST(" << f.first << ") >  ";
        }

        for (char c : f.second)
        {
            if (c == '\0') {
                cout << "eps ";
            } else {
                cout << c << " ";
            }
        }
        cout  << endl;
    }

    return 0;
}