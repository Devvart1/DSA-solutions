#include<bits/stdc++.h>
using namespace std;

bool checkvariable(string s) {
    char c = s[0];
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') {
        return true;
    }
    return false;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif



    unordered_set<string> oper = {"+", "-", "<", ">", "/", "*", "="};
    unordered_set<string> keyw = {"if", "else", "int", "float", "char", "double", "bool"};

    unordered_set<string> foper;
    unordered_set<string> fkey;
    unordered_set<string> fiden;
    unordered_set<string> fconst;
    string str = "if x>a\nx=b\nelse\nx=x+10";
    int i = 0, j = 0;
    int n = str.size();
    string temp;
    while (j < n && i <= j)
    {
        string temp2;
        temp2 += str[j];

        if (str[j] == ' '  || str[j] == '\n') {

            if (oper.count(temp)) {
                foper.insert(temp);
                temp = "";
            }
            else if (keyw.count(temp)) {
                fkey.insert(temp);
                temp = "";

            }
            else {
                if (checkvariable(temp) == false) {
                    cout << temp << " is not a valid varialble\n";
                    temp = "";

                }
                else {
                    fiden.insert(temp);
                    temp = "";
                }

            }
            j++;
            i = j;
        }

        else if (oper.count(temp2)) {
            foper.insert(temp2);
            string tempiden = str.substr(i, (j - i));
            fiden.insert(tempiden);
            j++;
            i = j;
            temp = "";

        }
        else if (temp2 == ";") {
            if (checkvariable(temp) == false) {

                cout << temp << " is not a valid varialble\n";
                temp = "";
            }
            else {
                fiden.insert(temp);
                temp = "";

            }
            j++;
            i++;
        }
        else {
            temp += str[j];
            j++;
        }

    }
    if (checkvariable(temp) == false) {
        int i = 0;
        bool check = true;
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] >= '0' && temp[i] <= '9') {
                continue;
            }
            else {
                check = false;
            }
        }
        if (check) {
            fconst.insert(temp);
        }
    }

    cout << fiden.size() << " identifiers are: ";
    for (auto x : fiden) {
        cout << x << " ";
    }

    cout << "\n" << foper.size() << " operators are: ";
    for (auto x : foper)
    {
        cout << x << " ";
    }

    cout << "\n" << fkey.size() << " keywords are: ";
    for (auto x : fkey) {
        cout << x << " ";
    }
    cout << endl;
    cout << fconst.size() << " constants are: ";
    for (auto x : fconst) {
        cout << x << " ";
    }





}