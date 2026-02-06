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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode* ,int> mp;
        ListNode* temp=headA;
        while(temp!=NULL){
            mp[temp]=1;
            temp=temp->next;
        }
        temp=headB;
        while(temp!=NULL){
            if(mp.find(temp) !=mp.end()){
                return temp;
            }else{
                temp=temp->next;
            }
        }
        return NULL;
    }
};