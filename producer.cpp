#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int cnt;
int last_timestamp;

void insert(int message)
{
    q.push(message);
}

// there are many way to call the process method.
// but we assume the method is call once every 60 second.
// and if the last process timestamp is l
void process()
{
    while (q.size() && cnt)
    {
        cout << "process  " << q.front() << endl;
        q.pop();
        cnt--;
    }
    while (q.size())
        q.pop();
}

void increasetoken()
{
    int cur_time = 60;
    last_timestamp = 0;
    while (true)
    {
        cnt += (cur_time - last_timestamp) / 60;
        cnt = max(cnt, 3); // the token bucket size is 3.
        last_timestamp = cur_time;
        cur_time += 60;
        this_thread::sleep_for(chrono::seconds(2));
    }
}

int main()
{
    thread(increasetoken).detach();
    for (int i = 0; i < 100; i++)
    {
        cout << "step " << i << endl;
        insert(i);
        process();
        this_thread::sleep_for(chrono::milliseconds(300));
    }
    int x;
    cin >> x;
    return 0;
}