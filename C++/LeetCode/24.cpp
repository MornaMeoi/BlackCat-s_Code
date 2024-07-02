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

void swapNodes(ListNode* left, ListNode* right)
{
    left->next = right->next;
    right->next = left;
}

ListNode* swapPairs(ListNode* head)
{
    if(head == nullptr)
        return nullptr;
    else if(head->next == nullptr)
        return head;
    head->next->next = swapPairs(head->next->next);
    ListNode* result = head->next;
    swapNodes(head, head->next);
    return result;
}

int main()
{
    return 0;
}