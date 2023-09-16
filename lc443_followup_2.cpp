#include <bits/stdc++.h>
using namespace std;

class Compression
{
public:
    Compression()
    {
        cnt = 0;
        last_idx = -1;
    }

    void compress(int idx, string input)
    {
        m[idx] = input;
        if (idx != last_idx + 1)
        {
            return;
        }
        while (m.count(last_idx + 1))
        {
            last_idx++;
            string str = m[last_idx];
            int start = 0;
            if (cnt == 0)
            {
                cur = str[0];
                cnt = 1;
                start = 1;
            }
            for (int i = start; i < str.size(); i++)
            {
                if (cur == str[i])
                {
                    cnt++;
                }
                else
                {
                    cout << cur << cnt;
                    cur = str[i];
                    cnt = 1;
                }
            }
        }
    }

private:
    unordered_map<int, string> m;
    char cur;
    int cnt;
    int last_idx;
};

int main()
{
    Compression com;
    com.compress(3, "deef");
    cout << "=============\n";
    com.compress(1, "bbcc");
    cout << "=============\n";
    com.compress(0, "ab");
    cout << "=============\n";
    com.compress(2, "ccdd");
}