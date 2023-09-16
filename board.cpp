#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<char>> board;

void checkifWin()
{
    // 1. check vertical
    // 2. check horizontal
    // 3. check diagnal.
}

void insert(int col, char c)
{
    board[col].push_back(c);
}

int main()
{
    insert(0, 'R');

    return 0;
}