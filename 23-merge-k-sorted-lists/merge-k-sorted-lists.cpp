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
    ListNode* convert(vector<int>& arr) {
        if (arr.size() == 0) return NULL;

        ListNode* head = new ListNode(arr[0]);
        ListNode* temp = head;

        for (int i = 1; i < arr.size(); i++) {
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> finalarr;

        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];
            while (temp != NULL) {
                finalarr.push_back(temp->val);
                temp = temp->next;
            }
        }

        if (finalarr.size() == 0) return NULL;

        sort(finalarr.begin(), finalarr.end());

        return convert(finalarr);
    }
};
;