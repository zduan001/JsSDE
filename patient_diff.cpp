#include <bits/stdc++.h>

using namespace std;

vector<string> res1, res2;

typedef struct step1res
{
    string prefix;
    string suffix;
    string a;
    string b;
} step1res;

step1res step1(string x, string y)
{
    int i = 0;
    for (i = 0; i < min(x.size(), y.size()); i++)
    {
        if (x[i] != y[i])
            break;
    }
    string prefix = x.substr(0, i);

    x = x.substr(i);
    y = y.substr(i);

    int n = x.size(), m = y.size();
    for (i = 0; i < min(x.size(), y.size()); i++)
    {
        if (x[n - 1 - i] != y[m - 1 - i])
            break;
    }

    string sufix = x.substr(n - i);

    x = x.substr(0, n - i);
    y = y.substr(0, m - i);

    step1res res;
    res.prefix = prefix;
    res.suffix = sufix;
    res.a = x;
    res.b = y;
    return res;
}

pair<int, int> findsame(string x, string y)
{
    unordered_map<char, int> cnt_x;
    unordered_map<char, int> loc_x;
    for (int i = 0; i < x.size(); i++)
    {
        cnt_x[x[i]]++;
        loc_x[x[i]] = i;
    }

    unordered_map<char, int> cnt_y;
    unordered_map<char, int> loc_y;
    for (int j = 0; j < y.size(); j++)
    {
        cnt_y[y[j]]++;
        loc_y[y[j]] = j;
    }

    for (auto &a : cnt_x)
    {
        if (a.second != 1)
            continue;
        char c = a.first;
        if (cnt_y[c] != 1)
            continue;
        return {loc_x[c], loc_y[c]};
    }
    return {-1, -1};
}

void dfs(string i, string j)
{
    step1res x = step1(i, j);
    res1.push_back(x.prefix);
    res2.push_back(x.prefix);

    auto pivot = findsame(x.a, x.b);
    if (pivot.first == -1)
    {
        if (x.a.size())
            res1.push_back("+" + x.a);
        if (x.b.size())
            res2.push_back("-" + x.b);
    }
    else
    {
        dfs(x.a.substr(0, pivot.first), x.b.substr(0, pivot.second));
        string s(1, x.a[pivot.first]);

        res1.push_back(s);
        res2.push_back(s);
        dfs(x.a.substr(pivot.first + 1), x.b.substr(pivot.second + 1));
    }

    res1.push_back(x.suffix);
    res2.push_back(x.suffix);
}

int main()
{
    // step1res x = step1("abcde", "abxyxde");
    // cout << x.prefix << endl << x.suffix << endl << x.a << endl << x.b << endl;

    // auto y = findsame("xyxz", "xxywq");
    // cout << y.first << " " << y.second << endl;

    dfs("xyakb12", "xyckd12");

    for (auto aaa : res1)
        cout << aaa << " ";
    cout << endl;
    for (auto bbb : res2)
        cout << bbb << " ";
    cout << endl;

    return 0;
}
