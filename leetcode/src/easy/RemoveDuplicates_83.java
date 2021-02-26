package easy;

import java.security.Timestamp;

/**
 * leet problem #83
 * 
 * Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
 * 
 * @author zongjing
 *
 */
public class RemoveDuplicates_83 {
	private static class ListNode {
	    int val;
	    ListNode next;
	    ListNode() {}
	    ListNode(int val) { this.val = val; }
	    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
	}
	
	public static void main(String[] args) {
	
	}
	
	//O(n)
	public static ListNode solution(ListNode head) {
		if(head == null){
            return null;
        }
        ListNode temp = head;
		while(temp.next != null) {
			if(temp.val == temp.next.val) {
				temp.next = temp.next.next;
			}
            else{
			    temp = temp.next;
            }
        }
		
		return head;
	}
}
