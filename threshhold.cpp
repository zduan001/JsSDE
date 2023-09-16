#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void process(string key, string status)
    {
        if (status != "failure")
        {
            last_status[key] = status;
            return;
        }

        if (status != last_status[key])
        {
            cnt[key].push_back(1);
        }
        else
        {
            int tmp = cnt[key][cnt[key].size() - 1];
            cnt[key][cnt[key].size() - 1] = tmp + 1;
        }
        last_status[key] = status;
    }

    void query(int threshhold)
    {
        for (auto &x : cnt)
        {
            for (auto &t : x.second)
            {
                if (t > threshhold)
                {
                    cout << x.first << endl;
                    break;
                }
            }
        }
    }

private:
    unordered_map<string, vector<int>> cnt;
    unordered_map<string, string> last_status;
};

int main()
{
    Solution sol;
    sol.process("tom", "failure");
    sol.process("tom", "pass");
    sol.process("jack", "pass");
    sol.process("tom", "failure");
    sol.process("tom", "failure");
    sol.process("jack", "failure");
    sol.process("jack", "failure");
    sol.process("tom", "failure");
    sol.process("jack", "failure");
    sol.query(2);
    return 0;
}