#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        char c = chars[0];
        int cnt = 1;
        vector<char> res;
        for (int i = 1; i < chars.size(); i++)
        {
            if (c != chars[i])
            {
                res.push_back(c);
                if (cnt > 1)
                {
                    string s = to_string(cnt);
                    for (char x : s)
                        res.push_back(x);
                }
                c = chars[i];
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }
        res.push_back(c);
        if (cnt > 1)
        {
            string s = to_string(cnt);
            for (char x : s)
                res.push_back(x);
        }
        for (int i = 0; i < res.size(); i++)
            chars[i] = res[i];
        return res.size();
    }
};