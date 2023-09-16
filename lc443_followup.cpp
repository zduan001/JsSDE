#include <bits/stdc++.h>
using namespace std;

class Compression
{
public:
    Compression()
    {
        cnt = 0;
        cur = ' ';
    }

    void compress(string str)
    {
        int idx = 0;
        if (cnt == 0)
        {
            cur = str[0];
            cnt = 1;
            idx = 1;
        }
        for (int i = idx; i < str.size(); i++)
        {
            if (str[i] == cur)
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

private:
    char cur;
    int cnt;
};

int main()
{
    Compression com;
    com.compress("aabb");
    cout << "====\n";
    com.compress("bcccdddd");
    return 0;
}