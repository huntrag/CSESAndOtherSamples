#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
#define MOD 1000000007
#define fi first
#define se second
bool isEx(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
int eval(int a1, int a2, char ex)
{
    switch (ex)
    {
    case '+':
        return a1 + a2;
    case '-':
        return a1 - a2;
    case '*':
        return a1 * a2;
    case '/':
        return a1 / a2;
    default:
        return 0;
    }
    return -1;
}

int evalRPN(vector<string> &tokens)
{
    reverse(tokens.begin(), tokens.end());
    int n = tokens.size();
    vector<char> signs(n);
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        if (tokens[i].length() == 1 && isEx(tokens[i][0]))
        {
            signs[i] = tokens[i][0];
            nums[i] = INT_MAX;
        }
        else
        {
            nums[i] = stoi(tokens[i]);
        }
    }

    stack<char> sign;
    stack<int> num;
    int i = 0;
    int count = 0;
    while (i <= n)
    {
        if (num.size() >= 3 && sign.size() >= 1 && (i == n || (count == 2)))
        {
            int a1 = num.top();
            num.pop();
            // cout<<"Removed "<<a1<<" "<<num.size()<<"\n";
            int a2 = num.top();
            num.pop();
            // cout<<"Removed "<<a2<<" "<<num.size()<<"\n";
            char sgn = sign.top();
            sign.pop();
            num.pop();
            // cout<<"Removed "<<sgn<<" "<<num.size()<<"\n";
            if (num.size() >= 1 && num.top() != INT_MAX)
            {
                count = 1;
            }
            else
            {
                count = 0;
            }
            int ans = eval(a1, a2, sgn);
            num.push(ans);
            // cout<<"Inserted "<<ans<<" "<<num.size()<<"\n";
            count++;
            // cout<<a1<<sgn<<a2<<" "<<ans<<"\n";
            if (i == n && num.size() == 1)
            {
                break;
            }
        }
        else if (i < n)
        {
            if (nums[i] == INT_MAX)
            {
                sign.push(signs[i]);
                num.push(nums[i]);
                // cout<<"Inserted "<<signs[i]<<" "<<num.size()<<"\n";
                count = 0;
            }
            else
            {
                num.push(nums[i]);
                // cout<<"Inserted "<<nums[i]<<" "<<num.size()<<"\n";
                count++;
            }
            i++;
        }
        else
        {
            break;
        }
    }
    return num.top();
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin>>test;
    while (test--)
    {
    }
    return 0;
}