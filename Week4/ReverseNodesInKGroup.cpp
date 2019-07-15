/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

    Only constant extra memory is allowed.
    You may not alter the values in the list's nodes, only nodes itself may be changed.
    
    Accoridng to LeetCode for my solution:
    Runtime: 20 ms, faster than 80.27% of C++ online submissions for Reverse Nodes in k-Group.
Memory Usage: 9.7 MB, less than 78.32% of C++ online submissions for Reverse Nodes in k-Group.

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        /*If the list has less thna k nodes then return the list
        This means it can be recursive as if we do have k nodes then
        we reverse them then add the reults from the nodes beyond the first group.
        */
        ListNode* node= head;
        int numberOfNodes{0};
        //Check the number of nodes reamining is k or less
        while(node)
        {
            numberOfNodes+=1;
            if(numberOfNodes==k)
            {
                break;
            }
            node=node->next;
        }
        if(numberOfNodes<k)
        {
            return head;
        }
        //if k or more remain then prepare the next set
        node=node->next;
        ListNode* nextGroup= reverseKGroup(node,k);
        //Now reverse the current group since it is k
        
        ListNode* curNode= head;
        ListNode* prevNode=NULL;
        ListNode* tempNode=NULL;
        int nodeCounter=0;
        while(nodeCounter!=k)
        {
            tempNode=curNode->next;
            curNode->next=prevNode;
            prevNode=curNode;
            curNode=tempNode;
            
            nodeCounter++;
        }
        head->next=nextGroup;       
        return prevNode;
    }
};
