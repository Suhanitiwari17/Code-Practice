/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {

        ListNode f=list1;
        ListNode s=list2;
        ListNode ans=new ListNode();
        ListNode node=ans;

        while(f!=null && s!=null){
            if(f.val<s.val){
                node.next=f;
                f=f.next;
                node=node.next;
            }
            else{
                node.next=s;
                s=s.next;
                node=node.next;
            }
        }
        while(f!=null){
            node.next=f;
            f=f.next;
           node=node.next;
        }
        while(s!=null){
            node.next=s;
            s=s.next;
            node=node.next;
        }
        return ans.next;
    }
}