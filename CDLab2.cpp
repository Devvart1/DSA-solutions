#include <bits/stdc++.h>
using namespace std;

unordered_map<char, bool> ops = {
    {'+', true},
    {'>', true},
    {'=', true}
};

bool checkKeyword(string s) {

    int state = 0;

    for (char x : s) {
        switch (x) {
        case 'i':
            if (state == 0) state = 1;
            else state = -1;
            break;
        case 'f':
            if (state == 1) state = 2;
            else state = -1;
            break;
        case 'e':
            if (state == 0) state = 10;
            else if (state == 12) state = 13;
            else state = -1;
            break;
        case 'l':
            if (state == 10) state = 11;
            else state = -1;
            break;
        case 's':
            if (state == 11) state = 12;
            else state = -1;
            break;
        }
    }

    if (state == 2 || state == 13) return true;
    return false;
}

bool isNumber(string t) {

    int state = 0;
    for (int i = 0; i < t.length(); i++) {
        char x = t[i];
        if (x >= '0' && x <= '9' && state != -1)state = 1;
        else state = -1;
    }
    if (state == 1) return true;
    return false;

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

    fstream f;
    f.open("input.txt", ios::in);
    string word, fin;
    while (f >> word)
    {
        fin += word;
        fin += " ";
    }

    string inp = fin;
    string token;
    int key = 0, ope = 0, num = 0, id = 0;
    for (int i = 0; i < inp.length(); i++) {
        if (inp[i] == ' ' || inp[i] == '+' || inp[i] == '=' || inp[i] == ';' || inp[i] == '>') {
            if (token.length() > 0) {
                if (checkKeyword(token)) {
                    cout << token << " is a keyword " << endl;
                    key++;
                } else if (ops.find(inp[i]) != ops.end()) {
                    cout << token << " is an operator " << endl;
                    ope++;
                }
                else if (isNumber(token)) {
                    cout << token << " is a number " << endl;
                    num++;
                }
                else {
                    cout << token << " is an identifier " << endl;
                    id++;
                }
                token.clear();
            }
            else if (ops.find(inp[i]) != ops.end()) {
                cout << inp[i] << " is an operator " << endl;
                ope++;
            }
        }
        else token.push_back(inp[i]);
    }


    cout << endl << endl;

    cout << "Identifier " << id << endl;
    cout << "keywords " << key << endl;
    cout << "Number " << num << endl;
    cout << "Operator " << ope << endl;



    return 0;

}