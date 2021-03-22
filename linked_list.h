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
    head->next = nullptr;
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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *target_ptr, *help_ptr, *prev_ptr;

    target_ptr = help_ptr = head;

    int i = 0;
    while (help_ptr != nullptr)
    {
        if (i >= n)
        {
            prev_ptr = target_ptr;
            target_ptr = target_ptr->next;
        }
        ++i;
        help_ptr = help_ptr->next;
    }

    if (target_ptr == head)
    {
        auto temp = head->next;
        delete head;
        return temp;
    }

    auto temp = target_ptr;
    prev_ptr->next = target_ptr->next;
    delete temp;

    return head;
}

ListNode *reverseList(ListNode *head)
{
    ListNode *next;
    ListNode *reverse_head = nullptr;

    while (head)
    {
        next = head->next;
        head->next = reverse_head;
        reverse_head = head;
        head = next;
    }

    return reverse_head;
}
//  4
//  5
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *result;
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;

    if (l1->val < l2->val)
    {
        result = l1;
        l1->next = mergeTwoLists(l1->next, l2);
    }
    else
    {
        result = l2;
        l2->next = mergeTwoLists(l2->next, l1);
    }
    return result;
}
// 12 21
bool isPalindrome(ListNode *head)
{
    ListNode *slow, *fast, *next;
    slow = nullptr;
    fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;

        next = head->next;
        head->next = slow;
        slow = head;
        head = next;
    }

    // odd
    if (fast != nullptr)
        head = head->next;

    while (head != nullptr && slow != nullptr)
    {
        if (head->val != slow->val)
            return false;
        head = head->next;
        slow = slow->next;
    }
    return true;
}

bool hasCycle(ListNode *head)
{
    while (head != nullptr)
    {
        auto fast_head = head;
        while (fast_head != nullptr)
        {
            fast_head = fast_head->next;
            if (head == fast_head)
                return true;
            
        }
        head = head->next;
    }
}