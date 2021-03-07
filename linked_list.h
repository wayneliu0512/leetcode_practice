#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <unordered_map>

using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *CreateList(const vector<int> &vec)
{
    auto head = new ListNode(vec.front());
    auto front = head;
    for (size_t i = 1; i < vec.size(); ++i)
    {
        head->next = new ListNode(vec[i]);
        head = head->next;
    }
    return front;
}

void ShowList(ListNode *head)
{
    while (head)
    {
        cout << head->val << ", ";
        head = head->next;
    }
    cout << endl;
}

ListNode *removeNthFromEnd(ListNode *head, int &count, int n)
{
    if (head == nullptr)
        return nullptr;
    else
    {
        auto new_head = removeNthFromEnd(head->next, count, n);
        if (count == n)
            head->next = new_head;
        count++;
        return head->next;
    }
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int count = 0;
    return removeNthFromEnd(head, count, n);
}

// 1->2->null
