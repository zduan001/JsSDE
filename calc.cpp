#include <bits/stdc++.h>
using namespace std;

void eval(stack<int> &nums, stack<pair<int, char>> &ops)
{
    char op = ops.top().second;
    ops.pop();

    int b = nums.top();
    nums.pop();
    int a = nums.top();
    nums.pop();
    if (op == '+')
        nums.push(a + b);
    if (op == '-')
        nums.push(a - b);
    if (op == '*')
        nums.push(a * b);
    if (op == '/')
        nums.push(a / b);
    return;
}

int main()
{
    string s;
    cin >> s;
    stack<int> nums;
    stack<pair<int, char>> ops;
    int level = 0;
    int i = 0;
    while (i < s.size())
    {
        if (s[i] == '(')
            level += 10;
        else if (s[i] == ')')
            level -= 10;
        else if (isdigit(s[i]))
        {
            int j = i;
            int val = 0;
            while (j < s.size() && isdigit(s[j]))
            {
                val = val * 10 + (s[j] - '0');
                j++;
            }
            i = j - 1;
            nums.push(val);
        }
        else
        {
            int tmp = level;
            if (s[i] == '+' || s[i] == '-')
            {
                tmp += 2;
            }
            else
            {
                tmp += 4;
            }

            while (!ops.empty() && tmp <= ops.top().first)
            {
                eval(nums, ops);
            }
            ops.push({tmp, s[i]});
        }
        i++;
    }
    while (ops.size())
        eval(nums, ops);
    cout << nums.top() << endl;
    return 0;
}