#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Define the variables and their domains
const int num_variables = 3;
const vector<int> domain = {1, 2, 3};

// Define the constraints
bool constraint(int var1, int val1, int var2, int val2) {
    if (var1 == 0 && var2 == 1 && val1 == 1 && val2 == 2) return false;
    if (var1 == 1 && var2 == 2 && val1 == 2 && val2 == 3) return false;
    return true;
}

// Recursive function to solve the CSP
bool backtrack(int variables[], int var_index) {
    if (var_index == num_variables) return true;
    for (int val : domain) {
        variables[var_index] = val;
        bool consistent = true;
        for (int i = 0; i < var_index; i++) {
            if (!constraint(var_index, val, i, variables[i])) {
                consistent = false;
                break;
            }
        }
        if (consistent && backtrack(variables, var_index + 1)) {
            return true;
        }
    }
    return false;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    int variables[num_variables];
    if (backtrack(variables, 0)) {
        for (int i = 0; i < num_variables; i++) {
            cout << "Variable " << i << " = " << variables[i] << endl;
        }
    } else {
        cout << "No solution found." << endl;
    }
    return 0;
}

