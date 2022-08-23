class Solution {
public:
    ListNode* reverseList(ListNode* head){
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode* newNode = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return newNode;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast -> next != NULL && fast -> next -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        slow -> next = reverseList(slow -> next);
        slow = slow -> next;
        ListNode* temp = head;
        
        while(slow != NULL){
            if(temp -> val != slow -> val){
                return false;
            }
            slow = slow -> next;
            temp = temp -> next;
        }
        return true;
    }
};