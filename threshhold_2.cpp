#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> pis;

class Solution
{
public:
    void process(int timestamp, string key, string status)
    {
        m[key].push_back({timestamp, status});
    }

    void query(int start_time, int end_time, int threshhold)
    {
        for (auto &item : m)
        {
            auto vec = item.second;
            int l = 0, r = vec.size() - 1;
            while (l < r)
            {
                int mid = (l + r) / 2;
                if (vec[mid].first >= start_time)
                    r = mid;
                else
                    l = mid + 1;
            }
            if (vec[l].first < start_time)
                continue;
            int a = l;
            l = 0;
            r = vec.size() - 1;
            while (l < r)
            {
                int mid = (l + r + 1) / 2;
                if (vec[mid].first <= end_time)
                    l = mid;
                else
                    r = mid - 1;
            }
            int b = l;

            int cnt = 0;
            for (int i = a; i <= b; i++)
            {
                if (vec[i].second == "failure")
                {
                    cnt++;
                    if (cnt > threshhold)
                    {
                        cout << item.first << endl;
                        break;
                    }
                }
            }
        }
    }

private:
    unordered_map<string, vector<pis>> m;
};

int main()
{
    Solution sol;
    sol.process(1, "tom", "failure");
    sol.process(2, "tom", "pass");
    sol.process(3, "jack", "pass");
    sol.process(4, "tom", "failure");
    sol.process(5, "tom", "failure");
    sol.process(6, "jack", "failure");
    sol.process(7, "jack", "failure");
    sol.process(8, "tom", "failure");
    sol.process(9, "jack", "failure");
    sol.query(3, 8, 2);
    return 0;
}