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

ListNode *returnNode(ListNode *node)
{
    return node;
}

void reorderList(ListNode* head)
{
    if(head->next != nullptr)
        reorderList(head->next);
    
}

int main()
{

    return 0;
}