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
        if (head == NULL || head->next == NULL)
            return head;
            
        ListNode *odd_head = (ListNode*)malloc(sizeof(ListNode));
        ListNode *even_head = (ListNode*)malloc(sizeof(ListNode));
        
        odd_head->next = head;
        even_head->next = head->next;
        
        ListNode *temp = even_head;
        

        
        while(head->next != NULL)
        {
            temp->next = head->next;
            temp = temp->next;
            if (temp->next == NULL)
                break;
            else
            {
                head->next = temp->next;
                head = head->next;
                temp->next = NULL;
            }
        }
        
        head->next = even_head->next;
        
        return odd_head->next;
        
        
    }
};