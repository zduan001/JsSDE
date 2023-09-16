#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;

void dfs(int target, int res, int idx, string trace)
{
    if (idx == n)
    {
        if (target == res)
            cout << trace << endl;
        return;
    }
    dfs(target, res + arr[idx], idx + 1, trace + "+" + to_string(arr[idx]));
    dfs(target, res - arr[idx], idx + 1, trace + "-" + to_string(arr[idx]));
    dfs(target, res * arr[idx], idx + 1, trace + "*" + to_string(arr[idx]));
    dfs(target, res / arr[idx], idx + 1, trace + "/" + to_string(arr[idx]));
}

int main()
{
    n = 4;
    arr = {1, 2, 3, 4};
    int target = 24;
    dfs(target, arr[0], 1, to_string(arr[0]));
    return 0;
}
