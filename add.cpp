#include <bits/stdc++.h>
using namespace std;

string s1, s2;

int main()
{
    cin >> s1 >> s2;
    vector<int> v1, v2;

    for (int i = s1.size() - 1; i >= 0; i--)
        v1.push_back(s1[i] - '0');
    for (int i = s2.size() - 1; i >= 0; i--)
        v2.push_back(s2[i] - '0');

    vector<int> res;
    int carry = 0;
    for (int i = 0; i < max(v1.size(), v2.size()); i++)
    {
        int a = (i >= v1.size() ? 0 : v1[i]);
        int b = (i >= v2.size() ? 0 : v2[i]);
        int tmp = a + b + carry;

        res.push_back(tmp % 10);
        carry = tmp / 10;
    }
    if (carry)
        res.push_back(carry);
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i];
    cout << endl;
    return 0;
}