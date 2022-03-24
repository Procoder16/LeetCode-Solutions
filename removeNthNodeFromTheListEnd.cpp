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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int lenOfTheList = 0;
        ListNode* temp = head;
        while(temp != NULL){
            lenOfTheList++;
            temp = temp -> next;
        }
        
        if(lenOfTheList == n){
            return head -> next;
        }
        
        temp = head;
        int pos = lenOfTheList - n + 1;
        
        int i = 1;
        while(i != pos - 1){
            temp = temp -> next;
            i++;
        }
        temp -> next = temp -> next -> next;
        
        return head;
    }
};