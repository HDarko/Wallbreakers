/*
Given a singly linked list, group all odd nodes together followed by the even nodes.
Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL

Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL

Note:

    The relative order inside both the even and odd groups should remain as it was in the input.
    The first node is considered odd, the second node even and so on ...
    
 According to LeetCode
 Runtime: 24 ms, faster than 13.37% of C++ online submissions for Odd Even Linked List.
Memory Usage: 9.7 MB, less than 41.10% of C++ online submissions for Odd Even Linked List.
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
    ListNode* oddEvenList(ListNode* head) {
        //the best way is to handle this to to do odd then even in an iteractive manner 
        //we need a evenHead to keep track of , an even and odd pointer too
        if(head==NULL)
        {
            return head;
        }
        //Node 1 is odd
        ListNode* oddNode= head;
        ListNode* evenHead= head->next;
        ListNode* evenNode=head->next;
        // while both evenNode and even->next are not null
        while((evenNode!=NULL) && (evenNode->next)!=NULL)
        {
            //we connect odd to even 
            oddNode->next=evenNode->next;
            //update oddNode
            oddNode=oddNode->next;
            //now repeat with even
            evenNode->next=oddNode->next;
            evenNode=evenNode->next;
        }
        //connect the two linked lists
        oddNode->next=evenHead;
        //head is still the first node for the odd linked list so return it
        return head;
        
    }
};

