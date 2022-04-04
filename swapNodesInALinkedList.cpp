#include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* first = head;
        ListNode* second = head;
        
        int count = 1;
        
        while(count != k){
            first = first -> next;
            count++;
        }
        
        ListNode* temp = head;
        
        int length = 1;
        while(temp != NULL){
            temp = temp -> next;
            length++;
        }
        
        count = 1;
        
        while(count != (length - k)){
            second = second -> next;
            count++;
        }
        
        int t = first -> val;
        first -> val = second -> val;
        second -> val = t;
        
        return head;
    }
};