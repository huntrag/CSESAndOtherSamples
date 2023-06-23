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
class MinStack
{
private:
    stack<int> s;
    priority_queue<int, vector<int>, greater<int>> q;
    priority_queue<int, vector<int>, greater<int>> del;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        s.push(val);
        q.push(val);
    }

    void pop()
    {
        int elem = s.top();
        del.push(elem);
        s.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        while (!del.empty() && !q.empty() && q.top() == del.top())
        {
            q.pop();
            del.pop();
        }
        return q.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
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