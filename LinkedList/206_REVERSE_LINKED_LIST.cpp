// Given the head of a singly linked list, reverse the list, and return the reversed list.

//   Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *currptr = head;
        ListNode *tempnext = nullptr;
        while (currptr)
        {
            tempnext = currptr->next;
            currptr->next = prev;
            prev = currptr;
            currptr = tempnext;
        }
        return prev;
    }
};