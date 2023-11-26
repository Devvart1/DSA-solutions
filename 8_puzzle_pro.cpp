#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

// Function to check if a given board configuration is the goal state
bool is_goal(vector<int> board) {
    for (int i = 0; i < 9; i++) {
        if (board[i] != i + 1) {
            return false;
        }
    }
    return true;
}

// Function to get the next possible states of the board
vector<vector<int>> get_next_states(vector<int> board) {
    vector<vector<int>> next_states;
    int blank_pos = -1;
    for (int i = 0; i < 9; i++) {
        if (board[i] == 9) {
            blank_pos = i;
            break;
        }
    }
    if (blank_pos % 3 > 0) { // Move blank left
        vector<int> next_board(board);
        swap(next_board[blank_pos], next_board[blank_pos - 1]);
        next_states.push_back(next_board);
    }
    if (blank_pos % 3 < 2) { // Move blank right
        vector<int> next_board(board);
        swap(next_board[blank_pos], next_board[blank_pos + 1]);
        next_states.push_back(next_board);
    }
    if (blank_pos / 3 > 0) { // Move blank up
        vector<int> next_board(board);
        swap(next_board[blank_pos], next_board[blank_pos - 3]);
        next_states.push_back(next_board);
    }
    if (blank_pos / 3 < 2) { // Move blank down
        vector<int> next_board(board);
        swap(next_board[blank_pos], next_board[blank_pos + 3]);
        next_states.push_back(next_board);
    }
    return next_states;
}

// DFS algorithm to solve the puzzle
bool dfs(vector<int> board) {
    stack<vector<int>> frontier;
    unordered_set<string> explored;
    frontier.push(board);
    while (!frontier.empty()) {
        vector<int> curr_board = frontier.top();
        frontier.pop();
        if (is_goal(curr_board)) {
            cout << "Solution found!\n";
            for (int i = 0; i < 9; i++) {
                cout << curr_board[i] << " ";
                if (i % 3 == 2) {
                    cout << endl;
                }
            }
            return true;
        }
        explored.insert(string(curr_board.begin(), curr_board.end()));
        vector<vector<int>> next_states = get_next_states(curr_board);
        for (int i = 0; i < next_states.size(); i++) {
            if (explored.find(string(next_states[i].begin(), next_states[i].end())) == explored.end()) {
                frontier.push(next_states[i]);
            }
        }
    }
    cout << "No solution found.\n";
    return false;
}

int main() {
    vector<int> board = {1, 2, 3, 4, 9, 5, 7, 8, 6}; // Initial board configuration
    dfs(board);
    return 0;
}
