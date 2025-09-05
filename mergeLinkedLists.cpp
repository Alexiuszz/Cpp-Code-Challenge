#include <iostream>
#include <vector>

using namespace std;

struct SinglyLinkedListNode
{
        int data;
        SinglyLinkedListNode *next;
        SinglyLinkedListNode(int x)
        {
                data = x;
                next = nullptr;
        }
};

SinglyLinkedListNode *mergeLinkedLists2(SinglyLinkedListNode *headA, SinglyLinkedListNode *headB)
{
        SinglyLinkedListNode *res = new SinglyLinkedListNode(0);
        SinglyLinkedListNode *currNode = res;
        while (headA != nullptr || headB != nullptr)
        {
                if (headA != nullptr)
                {
                        if (headB != nullptr)
                        {
                                if (headA->data <= headB->data)
                                {
                                        if (currNode->data == 0)
                                        {
                                                res = new SinglyLinkedListNode(headA->data);
                                                currNode = res;
                                        }
                                        else
                                        {
                                                currNode->next = new SinglyLinkedListNode(headA->data);
                                                currNode = currNode->next;
                                        }

                                        headA = headA->next;
                                }
                                else
                                {
                                        if (currNode->data == 0)
                                        {
                                                res = new SinglyLinkedListNode(headB->data);
                                                currNode = res;
                                        }
                                        else
                                        {
                                                currNode->next = new SinglyLinkedListNode(headB->data);
                                                currNode = currNode->next;
                                        }
                                        headB = headB->next;
                                }
                        }
                        else
                        {
                                currNode->next = new SinglyLinkedListNode(headA->data);
                                currNode = currNode->next;
                                headA = headA->next;
                        }
                }
                else if (headB != nullptr)
                {
                        currNode->next = new SinglyLinkedListNode(headB->data);
                        currNode = currNode->next;
                        headB = headB->next;
                }
        }

        return res;
}

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1; 
    
    if (head1->data < head2->data) {
        head1->next = mergeLists(head1->next, head2);
        return head1;
    }
    head2->next = mergeLists(head1, head2->next);
    return head2;
}

SinglyLinkedListNode *mergeLinkedLists3(SinglyLinkedListNode *headA, SinglyLinkedListNode *headB)
{
        SinglyLinkedListNode dummy(0);           // Dummy node for simplicity
        SinglyLinkedListNode *currNode = &dummy; // Start currNode at dummy

        // Merge until one of the lists is exhausted
        while (headA != nullptr && headB != nullptr)
        {
                if (headA->data <= headB->data)
                {
                        currNode->next = new SinglyLinkedListNode(headA->data);
                        headA = headA->next;
                }
                else
                {
                        currNode->next = new SinglyLinkedListNode(headB->data);
                        headB = headB->next;
                }
                currNode = currNode->next; // Move currNode forward
        }

        // Attach the remaining nodes
        if (headA != nullptr)
        {
                currNode->next = headA;
        }
        else
        {
                currNode->next = headB;
        }

        return dummy.next; // Skip the dummy node and return the merged list's head
}

SinglyLinkedListNode *mergeLinkedLists(SinglyLinkedListNode *headA, SinglyLinkedListNode *headB)
{
        vector<int> temp;

        while (headA != 0)
        {
                temp.push_back(headA->data);
                headA = headA->next;
        }
        while (headB != 0)
        {
                temp.push_back(headB->data);
                headB = headB->next;
        }

        return nullptr;
}

int main()
{
        SinglyLinkedListNode *iList1 = new SinglyLinkedListNode(1);
        SinglyLinkedListNode *iList2 = new SinglyLinkedListNode(1);
        SinglyLinkedListNode *currNode = iList1;
        int val = 0;

        std::cout << "Enter IList1 Nodes: \n"
                  << iList1->data << "\n";
        while (1)
        {
                cin >> val;
                if (val == 0)
                        break;
                currNode->next = new SinglyLinkedListNode(val);
                currNode = currNode->next;
        }
        val = 0;
        currNode = iList2;

        std::cout << "Enter IList2 Nodes: \n"
                  << iList1->data << "\n";
        while (1)
        {
                cin >> val;
                if (val == 0)
                        break;
                currNode->next = new SinglyLinkedListNode(val);
                currNode = currNode->next;
        }

        SinglyLinkedListNode *res = mergeLinkedLists3(iList1, iList2);

        std::cout << "Print Merge Nodes: \n";
        while (res->data != 0)
        {
                std::cout << res->data << "\n";
                res = res->next;
        }
}