/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
         ListNode beforehead(0) ;
		 ListNode afterhead(1) ;
		 
		 ListNode* before = &beforehead ;
		 ListNode* after = &afterhead ;
		 
		 
		 for( ;head;head = head -> next){
		 	if(head -> val < x){
		 		before -> next = head ;
		 		before = head ;
			 }else{
			 	after -> next = head ;
			 	after = head ;
			 }
		 }
		 
		 after -> next = NULL ;
		 before -> next = afterhead.next ;
		 
		 
		 return beforehead.next ;      
    }
};