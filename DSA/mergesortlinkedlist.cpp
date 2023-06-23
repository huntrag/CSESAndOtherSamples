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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *merge(ListNode *node1, ListNode *node2)
{
    if (node1 == NULL && node2 == NULL)
    {
        return NULL;
    }
    else if (node1 == NULL)
    {
        node2->next = merge(node1, node2->next);
        return node2;
    }
    else if (node2 == NULL)
    {
        node1->next = merge(node1->next, node2);
        return node1;
    }
    else if (node1->val < node2->val)
    {
        node1->next = merge(node1->next, node2);
        return node1;
    }
    else
    {
        node2->next = merge(node1, node2->next);
        return node2;
    }
    return NULL;
}

ListNode *findmid(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    fast = slow->next;
    slow->next = NULL;
    return fast;
}

ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *head2 = findmid(head);
    head = sortList(head);
    head2 = sortList(head2);
    return merge(head, head2);
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
    unordered_map<double, int> um;
    while (test--)
    {
        // cout << DBL_MAX;
        um[0.1] = 1;
        um.clear();
        cout << um[0.1];
    }
    return 0;
}