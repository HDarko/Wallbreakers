/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

For Iterative Solution below
Runtime: 8 ms, faster than 84.50% of C++ online submissions for Reverse Linked List.
Memory Usage: 9.1 MB, less than 65.28% of C++ online submissions for Reverse Linked List.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //With the use of a temporary varuable
        //we shall have a current node - next pointer
       // conetent we stored in a temp variable
        ListNode* curNode= head;
        ListNode* prevNode=NULL;
        ListNode* tempNode=NULL;
        while(curNode!=NULL)
        {
            tempNode=curNode->next;
            curNode->next=prevNode;
            prevNode=curNode;
            curNode=tempNode;
        }
        return prevNode;        
        
    }
};

/*For recursive solution

Runtime: 8 ms, faster than 84.50% of C++ online submissions for Reverse Linked List.
Memory Usage: 9.4 MB, less than 11.92% of C++ online submissions for Reverse Linked List.
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //Since we know that our argument is a ListNode
        //The node is either null or not
        if(head==NULL)
        {
            return NULL;
            
        }
        //if the next points to a NULL then it must be the tail of the linked 
        //lis t so re must make it the head thus simply return it
        if(head->next==NULL)
        {
            return head;
        }
        //else we need to move to the next node while switching the  pointers
        else
        {
            ListNode * cur= reverseList(head->next);
            //the node after cur Head Node must point to head.
            head->next->next=head;
            //head node -> next is decided by next recursive call so
            //set it to NULL
            head->next=NULL;
            //return the curNode
                return cur;
        }
        
    }
};

