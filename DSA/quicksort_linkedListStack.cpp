#include <bits/stdc++.h>/h>
using namespace std;

struct node
{
    int data;
    node *next;
};

void quickSort(node **headRef)
{
    if ((*headRef)->next == NULL)
    {
        return;
    }
    stack<node *> rev;
    node *head = *headRef;
    node *cur = head;
    while (cur != NULL)
    {
        rev.push(cur);
        cur = cur->next;
    }
    node *pivot = rev.top();
    rev.pop();
    node *pivot_prev = rev.top();
    node *prev = NULL;
    while (head != rev.top())
    {
        while (head != rev.top() && head->data < pivot->data)
        {
            prev = head;
            head = head->next;
        }
        if (head != rev.top())
        {
            node *cur_rev = rev.top();
            node *prev_rev = cur_rev->next;
            rev.pop();
            node *next_rev = rev.top();
            node *temp = head;
            head = cur_rev;
            head->next = temp->next;
            next_rev->next = temp;
            temp->next = prev_rev;
            if (prev == NULL)
            {
                (*headRef) = head;
            }
            else
            {
                prev->next = head;
            }
        }
    }
    pivot_prev->next = pivot->next;
    pivot->next = prev->next;
    prev->next = NULL;
    quickSort(headRef);
    quickSort(&(pivot->next));
    head = (*headRef);
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = pivot;
}