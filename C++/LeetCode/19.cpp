#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    if(head->next == nullptr)
            return {};
    int len = 1;
    ListNode *temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
        ++len;
    }
    len -= n;
    if(len == 0)
        return head->next;
    temp = head;
    while(len > 1)
    {
        temp = temp->next;
        --len;
    }
    temp->next = temp->next->next;
    return head;
}

int main()
{

    return 0;
}